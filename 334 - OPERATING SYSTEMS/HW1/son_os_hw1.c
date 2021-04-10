
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <sys/un.h>
#include <poll.h>

#include "logging.c"

#ifdef SYSVR4
#define PIPE(a) pipe(a)
#else
#include<sys/socket.h>
#define PIPE(a) socketpair(AF_UNIX, SOCK_STREAM,PF_UNIX,(a))
#endif

#define NOWAIT 0
#define LISTEN_BACKLOG 50
#include<stdlib.h> 
#include <stdint.h>
#include<unistd.h> 
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

typedef struct pollfd Pollfd;
Pollfd *bidderPoll;

int main() 
{       

    int starting_bid, minimum_increment , num_of_bidders;
    int num_arg_bidder,bidder_arg;
    pid_t *bidderPids;
    int w;
    int min_delay=99999;
    
    scanf("%d %d %d", &starting_bid, &minimum_increment , &num_of_bidders);

    char *bidders_path[num_of_bidders];
    int bidder_args[num_of_bidders];
    int bidder_ids[num_of_bidders];


    //printf("num_of_bidders-> %d\n", num_of_bidders);
    //printf("starting_bid-> %d\n", starting_bid);
    //printf("minimum_increment-> %d\n", minimum_increment);
 
    
        

//take_input.c deki argumans ile bu argumans aynı sey olacak
    //delete_begin {

    char ***argumans= malloc(sizeof(char **) * num_of_bidders);
    //char *argss[] = {"./PatternBidder", "200", "0", "1", "2",NULL}; 
    //char *args[] = {"./PatternBidder", "100", "0", "1",NULL}; 
    //char *args[] = {"./SlowStartBidder" , "500", NULL}; 
    /*char *argss[] = {"./Bidder", "2000",NULL}; 
    char *args[] = {"./Bidder", "2000",NULL};
    argumans[0] = argss;
    argumans[1] = args;
    
    for(int i=0; i< 2; i++){ //argumanlar dogru gelmis mi diye yazdırmak icin
        for(int j=0; j<2; j++){ 
            printf("%s ",argumans[i][j]);
        }
        printf("\n");
    }
    */
// } delete_end  , yani bu kısımlar silinecek cunku take_input.c'deki argumans arrayi bunların yerine gelecek
    char temp_buffer[100];
    int num_of_args;
    for( int i=0 ; i<num_of_bidders; i++ ) {
        scanf("%s %d", temp_buffer, &num_of_args);
        argumans[i] = (char **) malloc( (num_of_args+2) * sizeof(char*) );
        argumans[i][0] = (char *) malloc( (strlen(temp_buffer)+1) * sizeof(char) );
        strcpy(argumans[i][0], temp_buffer);
        for ( int j=0 ; j<num_of_args ; j++ ) {
            scanf("%s", temp_buffer);

            if(j==0){
                if(atoi(temp_buffer) < min_delay){
                    min_delay=atoi(temp_buffer);
                    //printf("min_delay == %d \n",min_delay); 
                }
            }
            

            argumans[i][j+1] = (char *) malloc( (strlen(temp_buffer)+1) * sizeof(char) );
            strcpy(argumans[i][j+1], temp_buffer);
        }
        argumans[i][num_of_args+1] = NULL;
    }
    /* This part is for printing all executables and their arguments */
    /* It is commented out */
    /*
    for(int i=0; i<num_of_bidders; i++){ 
        for(int j=0; argumans[i][j]; j++){ 
            printf("%s ",argumans[i][j]);
        }
        printf("\n");
    }
    */


    int **bidderFds, p;
    bidderFds = malloc(sizeof(int*) * num_of_bidders);
    for(int i=0; i<num_of_bidders; i++){
        bidderFds[i] = calloc(2, sizeof(int));
    }

    bidderPoll  = malloc(num_of_bidders * sizeof(Pollfd));
    
    for (int i = 0; i < num_of_bidders; i++) {

        PIPE(bidderFds[i]);
        bidderPoll[i] = (Pollfd) { bidderFds[i][1], POLLIN, 0 };
           
        
    }
   
    bidderPids = malloc(num_of_bidders * sizeof(pid_t));

//**********************FORK****************************************************************
    for(int i=0; i<num_of_bidders; i++){
        
        pid_t fork_pid = fork();
  
        if (fork_pid < 0) {
            fprintf(stderr, "Fork ERROR, this should not be the case :(\n");
            fflush(stderr);
        }
        else if (fork_pid == 0) { // CHILD-BIDDER
            //printf("CHILD-BIDDER %d ",i);
           
            int bidderEnd= bidderFds[i][0];
            

            
            dup2(bidderEnd, 0); //STDIN_FILENO
            dup2(bidderEnd, 1); //STDOUT_FILENO
            close(bidderFds[i][0]);
            for (int j = 0; j < num_of_bidders; j++) {
                close(bidderFds[j][0]);
                close(bidderFds[j][1]);
            }


            if (execvp(argumans[i][0],argumans[i]) < 0) {
                
                    fprintf(stderr, "Execvp ERROR \n");
                    fflush(stderr);
                }           
            
        }
        else{   //SERVER
            //printf("SERVER-PARENT\n");
            
            bidderPids[i]=getpid();
            
            close(bidderFds[i][0]);
            //wait(&child_status[i]);

                   
            
        }

        
    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
    
    int flag=0;
    int status[num_of_bidders];
    int winner_id;
    int current_highest_bid=0;
    int serverEnd ;
    int child_stat;

    int did_first_bid[num_of_bidders]; // bidderlar bidlerken, ilk bidleri mi diye tutmak icin
    for(int i=0; i< num_of_bidders ; i++){
        did_first_bid[i]=0;
    }
    int finished_bidding[num_of_bidders];
    for(int i=0; i< num_of_bidders; i++){
        finished_bidding[i]=0;
    }

    //printf("***********min_delay == %d \n",min_delay);
    while(flag==0){
        int retval;
        retval = poll(bidderPoll, num_of_bidders, min_delay);
        //printf("min_delay == %d \n",min_delay); 
        //retval = poll(bidderPoll, num_of_bidders, min_delay);
 
        
        if (retval < 0) {
            fprintf(stderr, "Poll listen ERROR, this should not be the case :(\n");
            fflush(stderr);
        }
        else if (retval > 0) {
            //printf("retval = %d \n",retval);

            

            for(int i=0; i< num_of_bidders ; i++){
                //printf("iiiiiiii-> %d\n",i);
                //printf("bidderPoll[i].fd-> %d\n",bidderPoll[i].fd);
                //printf("bidderPoll[i].revents = %d\n",bidderPoll[i].revents);
                
                if ((bidderPoll[i].revents & POLLIN) == POLLIN){

                    cm message;
                    

                    serverEnd = bidderFds[i][1];
                    //printf("server_end_____%d_______%d\n",i, serverEnd);

                    int r;
                    r= read(serverEnd, (void*) &message, sizeof(cm)) ;
                        
                    //printf("message_id -> %d\n",message.message_id);
                    ii *input = calloc(1,sizeof(ii));

                    input->type = message.message_id;
                    input->pid=bidderPids[i];
                    input->info.status = message.params.status;
                    input->info.bid = message.params.bid;
                    input->info.delay= message.params.delay;

                    print_input(input,i);
                   
                    
                    
                    
                    if(message.message_id==1){ //CLIENT_CONNECT 


                        sm serverMessage ;
                        serverMessage.message_id=1;
                        serverMessage.params.start_info.client_id = i;
                        serverMessage.params.start_info.starting_bid= starting_bid;
                        serverMessage.params.start_info.current_bid=0;
                        serverMessage.params.start_info.minimum_increment= minimum_increment;

                        ssize_t w;
                        w=write(serverEnd, (void*) &serverMessage, sizeof(sm)) ;
                        //printf("-----wwww----- %ld\n",w);
                        oi * output= calloc(1,sizeof(oi));
                        output->type=1;
                        output->pid= bidderPids[i];
                        output->info=serverMessage.params;
                        print_output( output, i);


                    }
                    else if(message.message_id==2){ //CLIENT_BID

                        
                        //update current highest bid
                        
   
                        sm serverMessage ={0};

                        if(message.params.bid < starting_bid && did_first_bid[i] ==0){//BID_LOWER_THAN_STARTING_BID 1
                            serverMessage.params.result_info.result= 1;
                        }
                        else if(message.params.bid < current_highest_bid){//BID_LOWER_THAN_CURRENT 2
                            serverMessage.params.result_info.result= 2;
                        }
                        else if(message.params.bid - current_highest_bid < minimum_increment ){
                                                                            //BID_INCREMENT_LOWER_THAN_MINIMUM 3
                            serverMessage.params.result_info.result= 3;
                        }
                        else{ //BID_ACCEPTED 0
                            serverMessage.params.result_info.result= 0;
                            current_highest_bid = message.params.bid;
                            winner_id = i; //id of the winning bidder

                        }

                        did_first_bid[i] =1; //ilk bidini isaretle
                        
                        serverMessage.message_id=2;
  
                        serverMessage.params.result_info.current_bid = current_highest_bid;

                        ssize_t w;

                        w=write(serverEnd, (void*) &serverMessage,sizeof(sm)) ;
                        //printf("-----wwww----- %ld\n",w);
                        

                        oi * output= calloc(1,sizeof(oi));
                        output->type=2;
                        output->pid= bidderPids[i];
                        output->info=serverMessage.params;
                        print_output( output, i);

                    }

                    


                    else if(message.message_id==3){  //CLIENT_FINISHED 3

                        //printf("***************_type_3_message_*************************\n");

                        

                        finished_bidding[i]=1;
                        status[i] = message.params.status;
                        int count=0;

                        for(int j=0 ; j< num_of_bidders; j++){
                            if(finished_bidding[j] == 1)
                                count=count +1;
                        }
                        if(count == num_of_bidders){ //auction finished
                            print_server_finished(winner_id,  current_highest_bid);

                            flag=1; //while bitsin
                            
                            sm serverMessage;
                            serverMessage.message_id=3;
                            serverMessage.params.winner_info.winner_id = winner_id;
                            serverMessage.params.winner_info.winning_bid = current_highest_bid;

                            
                           // print_client_finished(int client_id, int status, int status_match)


                            for(int k=0; k < num_of_bidders ; k++){

                                if (write(bidderFds[k][1], (void*) &serverMessage, sizeof(sm)) == -1) {
                                        fprintf(stderr, "ERROR on write \n");
                                        fflush(stderr);
                                }
                                oi * output= calloc(1,sizeof(oi));
                                output->type=3;
                                output->pid= bidderPids[k];
                                output->info=serverMessage.params;
                                print_output( output, k);

                            }
                            
                        break;
                        }
                        else{ //auction didn't finish

                                //do nothing?

                        } 

                        
                    }
                    
                    
                }
                else{ //(bidderPoll[i].revents & POLLIN) != POLLIN)
                    ;
                   
                }
                
            }
            
            
    
        }
        else{ //retval == 0
            ;
            //printf("reval==0\n");
        }
    }

    
    









    
    for (int i = 0; i < num_of_bidders; i++) {
        free(bidderFds[i]);
    }
    free(bidderPoll);
    free(bidderPids);

    int child_status[num_of_bidders];
    int r=0;
    while (wait(&child_status[r]) > 0 & r < num_of_bidders){

        //print_client_finished(int client_id, int status, int status_match)
        print_client_finished(r, child_status[r], child_status[r] == status[r]);
        r=r+1;
    
    }

    return 0; 
    
} 


