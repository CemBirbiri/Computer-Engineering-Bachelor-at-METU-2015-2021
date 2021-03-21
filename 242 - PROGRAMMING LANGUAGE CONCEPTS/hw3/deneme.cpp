#include<iostream> 
using namespace std; 
  
// An abstract class with constructor 

  


bool is_in(int *a){
  for(int i=0; i<3;i++){
    if(a[i]==1) cout<<"1"<<endl;
  }
}



int main(void) 
{ 
    int board_size;
    int x,y;
    int maxTurnNumber;
    int number_of_players;
    int id,x1,y1;
    string team,self;

  for(int i=0; i< 4 ; i++){
  	if(i==0) cin>>board_size;
  	else if(i==1) cin>>x>>y;
  	else if(i==2) cin>>maxTurnNumber;
  	else{
  		cin>>number_of_players;
  		for(int j=0 ; j< number_of_players; j++){
  			cin>>id>>self>>team>>x1>>y1;
  		}
  	}
  }
  cout<<"board_size="<<board_size<<endl;
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;
  cout<<"maxTurnNumber="<<maxTurnNumber<<endl;
  cout<<"number_of_players="<<number_of_players<<endl;
  cout<<"id="<<id<<"self="<<self<<"team="<<team<<"x1,y1="<<x1<<y1<<endl;

    return 0; 
} 



 /*
	6 -> size of board
	3 3 ->chest coord
	29  -> maxTurnNumber
	2  -> number of players -P.
	12 ARCHER BARBARIAN 3 5  
	11 FIGHTER KNIGHT 1 1




	6 
	3 3 
	29  
	2  
	12 ARCHER BARBARIAN 3 5  
	11 FIGHTER KNIGHT 1 1
  */