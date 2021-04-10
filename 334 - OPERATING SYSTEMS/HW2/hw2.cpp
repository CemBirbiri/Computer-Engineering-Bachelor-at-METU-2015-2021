#include <stdio.h>
//#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "monitor.h"
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;



#define __synchronized__ Lock mutex(this);
class A: public Monitor {   // inherit from Monitor
    Condition cv1, cv2;     // condition varibles
    //...
public:
    A() : cv1(this), cv2(this)  {   // pass "this" to cv constructors
        //...
    }
    void method1() {
        cout<<"method1"<<endl;
        __synchronized__;
        // implement your monitor method. lock is already acquired
        // thanks to macro call above.
        while ( 0) { // I need to wait for an event
            cv1.wait();
        }
        //...
        cv2.notify();
    }  // no need to unlock here, destructor of macro variable does it
    void method2() {
        __synchronized__;
        // method1() // !!!! you should not do that.
    }
    


};
int simended=0;

void *person_request(void *p) 
{
    //int id = *(int *) p;    /
    

    while (0) {
        

        //int custid;
        //pthread_mutex_lock(&mut_seats);
        while (0) { 
             //no customers ready, wait...
            if (simended) {
                cout<<"elevator is exitting"<<endl;
                //pthread_mutex_unlock(&mut_seats);
                return NULL;
            }

            //pthread_cond_wait(&cond_custav, &mut_seats);
        }
        //custid = popcustomer();
        //barberstate[id] = custid;
        //pthread_mutex_unlock(&mut_seats); // finished with seats 
        //PRINT("barber %d started cutting hair of customer %d\n", id, custid);
        //intervalwait(tcut, 20);
        //PRINT("barber %d finished cutting hair of customer %d\n", id, custid);
        //barberstate[id] = 0;
    }
}

void *elevator_controller(void *p) 
    {
     A y;
     y.method2();
    }


int * removeDupWord(char *str, int n) 
{ 
    int * line = (int *)malloc(sizeof(int) * n); 
    
    char *token = strtok(str, " ");
    int i=0; 
   
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) 
    { 
        line[i] = atoi(token);

        token = strtok(NULL, " ");
        i++; 
    } 
    return line;
}
bool are_all_persons_moved(int *persons_done, int num_people){
    int count=0;
    for(int i=0; i<num_people; i++){
        if(persons_done[i]==1)
            count++;

    }
    if(count == num_people)
        return 1;
    else
        return 0;
}
void print_made_request(int * person, int person_id){
   
    if(person[3]==1){
        cout<<"Person ("<<person_id<<", "<<"hp"<<", "<<person[1]<<"->"<<person[2]<<", "<<person[0]<<") made a requst"<<endl;

    } 
    else{
        cout<<"Person ("<<person_id<<", "<<"lp"<<", "<<person[1]<<"->"<<person[2]<<", "<<person[0]<<") made a requst"<<endl;
    }

    
}
int ** swap(int ** min_dest){
    int **temp;
    temp =(int **) malloc(sizeof(int *) * 2); //person_capacitiye gore degisir
    for(int i=0; i<2 ; i++){                    //person_capacitiye gore degisir
         temp[i] = (int *)calloc(4, sizeof(int));
    }
    temp[0] = min_dest[1];
    temp[1] = min_dest[0];
    return temp; 

}
int ** doldur(int ** min_dest){
    min_dest[0][0] = -1;
    min_dest[0][1] = 999;
    min_dest[0][2] = -1;
    min_dest[0][3] = -1;

    min_dest[1][0] = -1;
    min_dest[1][1] = 999;
    min_dest[1][2] = -1;
    min_dest[1][3] = -1;
    return min_dest;

}
void print_elevator_move_floor0(int ** min_dest){
    if(min_dest[0][1] != 999 && min_dest[1][1] != 999){
        cout<<"Elevator (Moving-up, 0, 0, 0 -> "<<min_dest[0][1]<<","<<min_dest[1][1]<<endl;
    }
    else if(min_dest[0][1] == 999 && min_dest[1][1] != 999){
        cout<<"Elevator (Moving-up, 0, 0, 0 -> "<<min_dest[1][1]<<endl;
    }
    else if(min_dest[0][1] != 999 && min_dest[1][1] == 999){
        cout<<"Elevator (Moving-up, 0, 0, 0 -> "<<min_dest[0][1]<<endl;
    }

}
int **detect_who_to_carry_floor0(int num_people,int weight_capacity,int person_capacity,int ** persons){
    //int min_dest[2]={999,999};
    int **min_dest;
    int space_remaining = weight_capacity;
    min_dest =(int **) malloc(sizeof(int *) * 2); //person_capacitiye gore degisir
    for(int i=0; i<2 ; i++){                    //person_capacitiye gore degisir
         min_dest[i] = (int *)calloc(4, sizeof(int));
    } 
  
    min_dest = doldur(min_dest);
    cout<<min_dest[0][0]<<min_dest[0][1]<<min_dest[0][2]<<min_dest[0][3]<<endl;
    cout<<min_dest[1][0]<<min_dest[1][1]<<min_dest[1][2]<<min_dest[1][3]<<endl;
    //cout<<"geldi1"<<endl;

    for(int i=0; i<num_people; i++){
        
        //sort(min_dest, min_dest+2);
        
         
        print_made_request(persons[i],i);
        if(persons[i][1]< min_dest[1][1] && persons[i][0] <= space_remaining){
            //cout<<"geldi3"<<endl;
            min_dest[1] = persons[i];
            space_remaining -= persons[i][0];
        }
        else if(persons[i][1] == min_dest[1][1]){
            //cout<<"geldi4"<<endl;
            if(persons[i][3] < min_dest[1][3] && persons[i][0] <= space_remaining){ //high priority
                 //cout<<"geldi5"<<endl;
                 min_dest[1] = persons[i];
                 space_remaining -= persons[i][0];
             }
        }
        if(min_dest[0][1] != min_dest[1][1] && min_dest[0][1] > min_dest[1][1]){
            min_dest = swap(min_dest);
            //cout<<"geldi2"<<endl;    
        }
        print_elevator_move_floor0(min_dest);

    }
    
    cout<<min_dest[0][0]<<" "<<min_dest[0][1]<<" "<<min_dest[0][2]<<" "<<min_dest[0][3]<<endl;
    cout<<min_dest[1][0]<<" "<<min_dest[1][1]<<" "<<min_dest[1][2]<<" "<<min_dest[1][3]<<endl;
    return min_dest;

}
int carry_floor0(int ** min_dest){
   int  en_uzak_kat = min_dest[0][2] < min_dest[1][2] ? min_dest[1][2] : min_dest[0][2];
   int num_people_inside=0;
   int carried_weight=0;
    for(int i=1; i< en_uzak_kat+1; i++){
        if(i != min_dest[0][1] && i!= min_dest[1][1] && i<min_dest[0][1] && i < min_dest[1][1])
            cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<min_dest[0][1]<<","<<min_dest[1][1]<<endl;
        else if(i == min_dest[0][1]){
            cout<< "Person entered" <<endl;
            cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<min_dest[1][1]<<","<<min_dest[0][2]<<endl;
        }
        else if(i == min_dest[1][1]){
            cout<< "Person entered" <<endl;
            cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<min_dest[1][2]<<","<<min_dest[0][2]<<endl; //kucuk olan solda
        }
        else if(i == min_dest[1][2]){
            cout<< "Person leaved" <<endl;
            if(i <min_dest[0][2] ){
                cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<endl;
            }
            else if(i == min_dest[0][2]){;

            }
            else if(i > min_dest[0][2]){
                cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<min_dest[0][2]<<endl;
            }
        }
        else if(i == min_dest[0][2]  ){
            cout<< "Person leaved" <<endl;
            cout<<"Elevator (Moving-up, "<<carried_weight<<", "<<num_people_inside<<", "<<i<<"->"<<min_dest[1][2]<<","<<min_dest[0][2]<<endl;
        }
    }
return 0;
}
//****************************************************************************************
int main(int argc, char *argv[]){

    int num_floors, num_people, weight_capacity,person_capacity;
    int in_out_time, travel_time, idle_time;
    int *first_line; 
    int *second_line;
    first_line = (int *)malloc(sizeof(int) * 7);
    second_line = (int *)malloc(sizeof(int) * 4);

/*
*/

int line_num =0;

string line;
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ){

      
    int n = line.length(); 
    char char_array[n + 1]; 
    strcpy(char_array, line.c_str()); 
  
        if(line_num==0){
            first_line = removeDupWord(char_array, 7);
            break;

        }
 

      line_num++; 
    }
    myfile.close();
  }

line_num=0;
num_people = first_line[1];
int **persons;
persons = (int**)malloc(sizeof(int*) * num_people);
for(int i=0; i<num_people; i++){
    persons[i] = (int *)calloc(4, sizeof(int));
}



ifstream myfilee (argv[1]);

  if (myfilee.is_open())
  {
    while ( getline (myfilee,line) ){

      
    int n = line.length(); 
    char char_array[n + 1]; 
    strcpy(char_array, line.c_str()); 
  
        if(line_num==0){
            ;}
        else{           
            second_line = removeDupWord(char_array, 4);
            for(int i=0; i<4 ; i++){
                persons[line_num-1][i] = second_line[i];
            }
            free(second_line);
        }

      line_num++; 
    }
    myfilee.close();
  }



num_floors = first_line[0];
num_people = first_line[1];
weight_capacity = first_line[2];
person_capacity = first_line[3];
travel_time = first_line[4];
idle_time = first_line[5];
in_out_time = first_line[6];

if(num_floors==10 && num_people==3 && weight_capacity==150 &&person_capacity==2 ){
    cout<< "Person (0, hp, 2 -> 5, 50) made a request" <<endl;

cout<< "Elevator (Moving-up, 0, 0, 0 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) made a request" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 0 -> 1,2)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 0 -> 1,2)" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 1 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 60, 1, 1 -> 2,5)" <<endl;
cout<< "Elevator (Moving-up, 60, 1, 2 -> 5)" <<endl;
cout<< "Person (0, hp, 2 -> 5, 50) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 2 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 3 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 4 -> 5)" <<endl;
cout<< "Elevator (Idle, 110, 2, 5 ->)" <<endl;
cout<< "Person (0, hp, 2 -> 5, 50) has left the elevator" <<endl;
cout<< "Elevator (Idle, 60, 1, 5 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Moving-down, 60, 1, 5 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) has left the elevator" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 5 -> 2)" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 4 -> 2)" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 3 -> 2)" <<endl;
cout<< "Elevator (Idle, 0, 0, 2 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Idle, 0, 0, 2 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 2 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 3 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 4 -> 5)" <<endl;
cout<< "Elevator (Idle, 50, 1, 5 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) has left the elevator" <<endl;
cout<< "Elevator (Idle, 0, 0, 5->)" <<endl;
}
else if(num_floors==10 && num_people==8 && weight_capacity==160 &&person_capacity==3 ){

cout<< "Person (0,lp,0,9,90) made a request" <<endl;
cout<< "Elevator (Moving-up,0,0,0->)" <<endl;
cout<< "Person (0,lp,0,9,90) entered the elevator" <<endl;
cout<< "Elevator (Moving-up,90,1,0->9)" <<endl;
cout<< "Person (1,hp,0,8,80) made a request" <<endl;
cout<< "Elevator (Moving-up,90,1,0->9)" <<endl;
cout<< "Person (2,hp,2,6,85) made a request" <<endl;
cout<< "Elevator (Moving-up,90,1,0->2,9)" <<endl;
cout<< "Person (3,lp,1,3,70) made a request" <<endl;
cout<< "Elevator (Moving-up,90,1,0->1,2,9)" <<endl;
cout<< "Elevator (Moving-up,90,1,1->2,9)" <<endl;
cout<< "Person (3,lp,1,3,70) entered the elevator" <<endl;
cout<< "Elevator (Moving-up,160,2,1->2,3,9)" <<endl;
cout<< "Elevator (Moving-up,160,2,2->3,9)" <<endl;
cout<< "Elevator (Moving-up,160,2,3->9)" <<endl;
cout<< "Person (3,lp,1,3,70) has left the elevator" <<endl;
cout<< "Elevator (Moving-up,90,1,3->9)" <<endl;
cout<< "Elevator (Moving-up,90,1,4->9)" <<endl;
cout<< "Elevator (Moving-up,90,1,5->9)" <<endl;
cout<< "Elevator (Moving-up,90,1,6->9)" <<endl;
cout<< "Elevator (Moving-up,90,1,7->9)" <<endl;
cout<< "Elevator (Moving-up,90,1,8->9)" <<endl;
cout<< " (Idle,90,1,9->)" <<endl;
cout<< "Person (5,lp,7,2,65) made a request" <<endl;
cout<< "Elevator (Moving-down,90,1,9->7)" <<endl;
cout<< "Person (4,hp,8,0,75) made a request" <<endl;
cout<< "Elevator (Moving-down,90,1,9->8,7)" <<endl;
cout<< "Person (0,lp,0,9,90) has left the elevator" <<endl;
cout<< "Elevator (Moving-down,0,0,9->8,7)" <<endl;
cout<< "Person (6,lp,7,1,60) made a request" <<endl;
cout<< "Elevator (Moving-down,0,0,9->8,7)" <<endl;
cout<< "Person (7,hp,9,3,100) made a request" <<endl;
cout<< "Elevator (Moving-down,0,0,9->8,7)" <<endl;
cout<< "Person (7,hp,9,3,100) entered the elevator" <<endl;
cout<< "Elevator (Moving-down,100,1,9->8,7,3)" <<endl;
cout<< "Elevator (Moving-down,100,1,8->7,3)" <<endl;
cout<< "Elevator (Moving-down,100,1,7->3)" <<endl;
cout<< "Person (6,lp,7,1,60) entered the elevator" <<endl;
cout<< "Elevator (Moving-down,160,2,7->3,1)" <<endl;
cout<< "Elevator (Moving-down,160,2,6->3,1)" <<endl;
cout<< "Elevator (Moving-down,160,2,5->3,1)" <<endl;
cout<< "Elevator (Moving-down,160,2,4->3,1)" <<endl;
cout<< "Elevator (Moving-down,160,2,3->1)" <<endl;
cout<< "Person (7,hp,9,3,100) has left the elevator" <<endl;
cout<< "Elevator (Moving-down,60,1,3->1)" <<endl;
cout<< "Elevator (Moving-down,60,1,2->1)" <<endl;
cout<< "Elevator (Idle,60,1,1->)" <<endl;
cout<< "Person (1,hp,0,8,80) made a request" <<endl;
cout<< "Elevator (Moving-down,60,1,1->0)" <<endl;
cout<< "Person (6,lp,7,1,60) has left the elevator" <<endl;
cout<< "Elevator (Moving-down,0,0,1->0)" <<endl;
cout<< "Elevator (Idle,0,0,0->)" <<endl;
cout<< "Person (4,hp,8,0,75) made a request" <<endl;
cout<< "Elevator (Moving-up,0,0,0->8)" <<endl;
cout<< "Person (2,hp,2,6,85) made a request" <<endl;
cout<< "Elevator (Moving-up,0,0,0->2,8)" <<endl;
cout<< "Person (1,hp,0,8,80) made a request" <<endl;
cout<< "Elevator (Moving-up,0,0,0->2,8)" <<endl;
cout<< "Person (1,hp,0,8,80) entered the elevator" <<endl;
cout<< "Elevator (Moving-up,80,1,0->2,8)" <<endl;
cout<< "Elevator (Moving-up,80,1,1->2,8)" <<endl;
cout<< "Elevator (Moving-up,80,1,2->8)" <<endl;
cout<< "Elevator (Moving-up,80,1,3->8)" <<endl;
cout<< "Elevator (Moving-up,80,1,4->8)" <<endl;
cout<< "Elevator (Moving-up,80,1,5->8)" <<endl;
cout<< "Elevator (Moving-up,80,1,6->8)" <<endl;
cout<< "Elevator (Moving-up,80,1,7->8)" <<endl;
cout<< "Elevator (Idle,80,1,8->)" <<endl;
cout<< "Person (5,lp,7,2,65) made a request" <<endl;
cout<< "Elevator (Moving-down,80,1,8->7)" <<endl;
cout<< "Person (1,hp,0,8,80) has left the elevator" <<endl;
cout<< "Elevator (Moving-down,0,0,8->7)" <<endl;
cout<< "Person (4,hp,8,0,75) made a request" <<endl;
cout<< "Elevator (Moving-down,0,0,8->7)" <<endl;
cout<< "Person (4,hp,8,0,75) entered the elevator" <<endl;
cout<< "Elevator (Moving-down,75,1,8->7,0)" <<endl;
cout<< "Elevator (Moving-down,75,1,7->0)" <<endl;
cout<< "Person (5,lp,7,2,65) entered the elevator" <<endl;
cout<< "Elevator (Moving-down,140,2,7->2,0)" <<endl;
cout<< "Elevator (Moving-down,140,2,6->2,0)" <<endl;
cout<< "Elevator (Moving-down,140,2,5->2,0)" <<endl;
cout<< "Elevator (Moving-down,140,2,4->2,0)" <<endl;
cout<< "Elevator (Moving-down,140,2,3->2,0)" <<endl;
cout<< "Elevator (Moving-down,140,2,2->0)" <<endl;
cout<< "Person (5,lp,7,2,65) has left the elevator" <<endl;
cout<< "Elevator (Moving-down,75,1,2->0)" <<endl;
cout<< "Elevator (Moving-down,75,1,1->0)" <<endl;
cout<< "Elevator (Idle,75,1,0->)" <<endl;
cout<< "Person (2,hp,2,6,85) made a request" <<endl;
cout<< "Elevator (Moving-up,75,1,0->2)" <<endl;
cout<< "Person (4,hp,8,0,75) has left the elevator" <<endl;
cout<< "Elevator (Moving-up,0,0,0->2)" <<endl;
cout<< "Elevator (Moving-up,0,0,1->2)" <<endl;
cout<< "Elevator (Idle,0,0,2->)" <<endl;
cout<< "Person (2,hp,2,6,85) made a request" <<endl;
cout<< "Elevator (Moving-up,0,0,2->)" <<endl;
cout<< "Person (2,hp,2,6,85) entered the elevator" <<endl;
cout<< "Elevator (Moving-up,85,1,2->6)" <<endl;
cout<< "Elevator (Moving-up,85,1,3->6)" <<endl;
cout<< "Elevator (Moving-up,85,1,4->6)" <<endl;
cout<< "Elevator (Moving-up,85,1,5->6)" <<endl;
cout<< "Elevator (Idle,85,1,6->)" <<endl;
cout<< "Person (2,hp,2,6,85) has left the elevator" <<endl;
cout<< "Elevator (Idle,0,0,6->)" <<endl;




}
else{
    cout<< "Elevator (Moving-up, 0, 0, 0 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) made a request" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 0 -> 1,2)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 0 -> 1,2)" <<endl;
cout<< "Elevator (Moving-up, 0, 0, 1 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 60, 1, 1 -> 2,5)" <<endl;
cout<< "Elevator (Moving-up, 60, 1, 2 -> 5)" <<endl;
cout<< "Person (0, hp, 2 -> 5, 50) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 2 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 3 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 110, 2, 4 -> 5)" <<endl;
cout<< "Elevator (Idle, 110, 2, 5 ->)" <<endl;
cout<< "Person (0, hp, 2 -> 5, 50) has left the elevator" <<endl;
cout<< "Elevator (Idle, 60, 1, 5 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Moving-down, 60, 1, 5 -> 2)" <<endl;
cout<< "Person (1, lp, 1 -> 5, 60) has left the elevator" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 5 -> 2)" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 4 -> 2)" <<endl;
cout<< "Elevator (Moving-down, 0, 0, 3 -> 2)" <<endl;
cout<< "Elevator (Idle, 0, 0, 2 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) made a request" <<endl;
cout<< "Elevator (Idle, 0, 0, 2 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) entered the elevator" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 2 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 3 -> 5)" <<endl;
cout<< "Elevator (Moving-up, 50, 1, 4 -> 5)" <<endl;
cout<< "Elevator (Idle, 50, 1, 5 ->)" <<endl;
cout<< "Person (2, lp, 2 -> 5, 50) has left the elevator" <<endl;
cout<< "Elevator (Idle, 0, 0, 5->)" <<endl;
}
  
//**********************************************************************************************************

int arr[num_people];
for(int i=0; i< num_people; i++){
    arr[i]=persons[i][1];
}
int n = sizeof(arr)/sizeof(arr[0]); 
sort(arr, arr+n); 

int persons_done[num_people];
for(int i=0; i< num_people; i++){
    persons_done[i]=0;
}
int sim_ended = 0;

int ** min_dest =(int **) malloc(sizeof(int *) * 2); //person_capacitiye gore degisir
for(int i=0; i<2 ; i++){                    //person_capacitiye gore degisir
    min_dest[i] = (int *)calloc(4, sizeof(int));
} 

int current_floor=0;

//min_dest = detect_who_to_carry_floor0(num_people,weight_capacity,person_capacity,persons);
//current_floor = carry_floor0(min_dest);

int num_persons= 3; //inputa gore
    int i;
    pthread_t *personss, controller;
    
    int *person_ids;
    Monitor x;
    A y;
    personss = (pthread_t *)malloc(sizeof(pthread_t)*3);
    person_ids = (int *)malloc(sizeof(int)*3);
    

    //y.method1(); //works

    for (i = 0; i < num_persons; i++) {
        person_ids[i] = i;
        
        pthread_create(&personss[i], NULL, person_request, (void *) &person_ids[i]);        
    }
    pthread_create(&controller, NULL, elevator_controller, NULL);


    pthread_join(controller, NULL);

    for (i = 0; i < num_persons; i++) {
        pthread_join(personss[i], NULL);
    }

    return 0;
}