// C++ Program for Floyd Warshall Algorithm  
#include <bits/stdc++.h> 
using namespace std; 
  
// Number of vertices in the graph  
#define V 4  
  
/* Define Infinite as a large enough 
value.This value will be used for  
vertices not connected to each other */
#define INF 99999  
  
// A function to print the solution matrix  
void printSolution(int dist[][V]);  
  
// Solves the all-pairs shortest path  
// problem using Floyd Warshall algorithm  
void floydWarshall (int graph[][V])  
{  
    int dist[V][V];
    for(int i=0 ; i < V ; i++){
        for(int j=0 ; j < V ; j++){
            dist[i][j]= graph[i][j];
        }
    }
    for(int k =0 ; k< V ; k++){
        for(int i=0 ; i< V ; i++){
            for(int j=0; j< V ; j++){

                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
               if(dist[j][k] + dist[k][i] < dist[j][i])
                    dist[j][i] = dist[j][k] + dist[k][i];
            }
        }
    }
    printSolution(dist);  
}  
  
/* A utility function to print solution */
void printSolution(int dist[][V])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
  
// Driver code  
int main()  
{  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    floydWarshall(graph);  
    return 0;  
}  