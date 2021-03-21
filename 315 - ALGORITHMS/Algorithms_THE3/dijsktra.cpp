// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 
  
#include <limits.h> 
#include <stdio.h> 
  
// Number of vertices in the graph 
#define V 9 
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], int sptSet[]){
    int min = 99999;
    int min_index;
    for(int i=0; i< V; i++){
        if(dist[i] < min && sptSet[i]==0){
            min= dist[i];
            min_index = i;
        }
    }
    return min_index;
    
} 
  
// A utility function to print the constructed distance array 
int printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[][V], int src) 
{ 
    int visited[V];
    int dist[V];
    for(int i=0; i< V; i++){
        visited[i]=0; 
        dist[i]=99999;
    }
    dist[src] = 0;

    for(int count=0; count < V-1 ; count++){

        int u = minDistance(dist, visited);
        visited[u]=1;

        for(int v=0; v< V ; v++){
            if(graph[u][v] != 0 && graph[u][v] + dist[u] < dist[v] && visited[v]==0 && dist[u] != 99999){
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }
  
    // print the constructed distance array 
    printSolution(dist); 
} 
  
// driver program to test above function 
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 