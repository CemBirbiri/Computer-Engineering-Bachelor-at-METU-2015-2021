//#include "the3.h"
#include <bits/stdc++.h> 
using namespace std; 


// You  can define extra functions here

/* A utility function to print solution */

void printSolution(int**& edgeList,int n)  
{  
     
    for (int i = 0; i < n; i++)  
    {  
        for (int j = 0; j < n; j++)  
        {  
            if (edgeList[i][j] == 99999)  
                cout<<"INF"<<"     ";  
            else
                cout<<edgeList[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
} 
void printScores(double *& scores, int n){
    for(int i=0; i< n; i++){
        cout<<scores[i]<<" ";
    }
    cout<<" "<<endl;
    
}
void printArray(int  *scores, int n){
    for(int i=0; i< n; i++){
        cout<<scores[i]<<" ";
    }
    cout<<" "<<endl;
    
}


void make_infinity(int n,  int**& dist){
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            else if(dist[i][j]==0)
                dist[i][j]= 99999;
        }
    }

}
// INPUT :
//            n         : number of nodes in the graph
//            edgeList  : edges in the graph
//            scores    : importance scores
// return value : 
//                 number of disconnected components
int Important (int n, int **&edgeList, double *& scores)
{ 
    int  i, j, k;
    int **dist;
      dist = new int*[n];   
    
    for (int i = 0; i < n; ++i) {
      dist[i] = new int[n];
    }
    
    for(int i =0 ; i<n;i++){
        for(int j=0; j<n;j++){
            dist[i][j] = edgeList[i][j];
        }
    }

make_infinity(n, dist);

    double sum = 0;      
     
  printSolution(dist,n);
    //Finding the all shortest paths using Floyd-Warshall alg.
    for (int k = 0; k < n; k++){  
        
        for (int i = 0; i < n; i++)  {  
             
            for (int j = 0; j < n; j++){  
                 
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];

                if (dist[j][k] + dist[k][i] < dist[j][i])  
                    dist[j][i] = dist[j][k] + dist[k][i];   
            }  
        }
    }


    //Calculating the scores
    for (k = 0; k < n; k++)  {  
        for (i = 0; i < n; i++){   
            for (j = 0; j < n; j++)  {

                if(dist[i][k] == 99999 || dist[j][k] == 99999 || dist[i][j]==99999 ){continue;}
                else if(i==k || j==k){continue;}
                else if(i==j){
                    sum = sum + (dist[i][k] + dist[k][j]) / 1.0;  }
                else{
                    sum = sum + (  ((dist[i][k] + dist[k][j])*1.0 )/  (1.0*dist[i][j])  );} 
            }
              
        }
        scores[k]=sum;
        sum=0;    
    } 
int count=1;
int array[n];
    for(i=0 ; i < n; i++){
        array[i]=0;
    }
int flag;
//int flag2;
    //Finding the number of disconnected graphs
     for (int i = 0; i < n; i++)  { 

        flag = n;
        //flag2=0; 
        for (int j = 0; j < n; j++){
            
            
            

            if( dist[i][j] != 0 && dist[i][j] != 99999){

                
                
                
                for(int k=0; k<n ; k++){

                    if(dist[j][k] != 0 && dist[j][k] != 99999){
                        
                        if(array[k] == 0){
                            
                            array[k]= count;
                            flag = flag -1 ;
                            //flag2= 1;
                            }
                        
                    }
                    
                }


            }
            if( j == n-1 && flag==n){ //&& flag2 == 0){
                //cout<< j << count<<endl;
                if(array[i]==0 && i!=0){
                    array[i] = count;
                    
                    count = count + 1;
                }

            }
            else if( j == n-1 && flag!=n ){
                
                count = count + 1;

            }


         
              
        }
        
        //count = count +1;
          
    }

int max=0;
    for(i=0; i< n; i++){
        if(array[i] > max)
            max= array[i];
    }

    cout<<"maxxxxxxxxxx-> "<<max<<endl;
    cout<<"array-> "<<endl;
    printArray(array, n);
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"dist-> "<<endl;
    printSolution(dist ,n ); 
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"EdgeList-> "<<endl;
    printSolution(edgeList ,n );

    //cout<<"Scores-> "<<endl;
    //printScores(scores, n);

   return max; 
}




int main(){


double *scores = new double[5];
      
    int **edgeList = new int*[5];
      int edgelist[5][5] = {0, 0, 2, 5, 3,0, 0, 0, 2, 3,2, 0, 0, 1, 0,5, 2, 1, 0, 4,3, 3, 0, 4, 0};
    
    for (int i = 0; i < 5; ++i) {
      edgeList[i] = new int[5];
    }
    
    for(int i =0 ; i<5;i++){
        for(int j=0; j<5;j++){
            edgeList[i][j] = edgelist[i][j];
        }
    }




Important(5,  edgeList , scores);







/*

double *scores = new double[6];
      int **edgeList = new int*[6];
     int edgelist[6][6] = {0, 0, 0, 3, 0, 2,
                           0 ,0, 3, 0, 2, 0,
                           0, 3, 0, 0, 0, 0,
                           3, 0, 0, 0, 0, 4,
                           0, 2, 0, 0, 0, 0,
                           2, 0, 0, 4, 0, 0};
    
    for (int i = 0; i < 6; ++i) {
      edgeList[i] = new int[6];
    }
    
    for(int i =0 ; i<6;i++){
        for(int j=0; j<6;j++){
            edgeList[i][j] = edgelist[i][j];
        }
    }
*/
/*
double *scores = new double[6];
      int **edgeList = new int*[6];
     int edgelist[6][6] = {0, 0, 1, 0, 10, 3,
                           0 ,0, 0, 0, 0, 0,
                           1, 0, 0, 0, 8, 9,
                           0, 0, 0, 0, 0, 0,
                           10, 0, 8, 0, 0, 0,
                           3, 0, 9, 0, 0, 0};
    
    for (int i = 0; i < 6; ++i) {
      edgeList[i] = new int[6];
    }
    
    for(int i =0 ; i<6;i++){
        for(int j=0; j<6;j++){
            edgeList[i][j] = edgelist[i][j];
        }
    }


Important(6,  edgeList , scores);


*/
/*

    double *scores = new double[2];
      int **edgeList = new int*[2];
     int edgelist[2][2] = {0, 17,
                           17 ,0
                           };
    
    for (int i = 0; i < 2; ++i) {
      edgeList[i] = new int[2];
    }
    
    for(int i =0 ; i<2;i++){
        for(int j=0; j<2;j++){
            edgeList[i][j] = edgelist[i][j];
        }
    }


Important(2,  edgeList , scores);*/

return 0;
}

