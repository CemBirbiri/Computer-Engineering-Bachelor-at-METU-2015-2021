#include <bits/stdc++.h> 
using namespace std; 
  
// Number of vertices in the graph  
#define V 5 


void printMST(int parent[], int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  

int find_min_key(int key[], int mst[]){
	int min=99999;
	int min_index;

	for(int i=0; i< V; i++){
		if(key[i] < min && mst[i]==0){
			min= key[i]; min_index=i;
		}
	}
	return min_index;

	
}

void primMST(int graph[V][V]){

	int key[V];
	int parent[V];
	int visited[V];

	for(int i=0 ; i< V;i++){
		key[i]=99999;
		visited[i]=0;
	}	

parent[0]=-1;
key[0]=0;

for(int count=0; count < V-1; count++){

	int u = find_min_key(key , visited);
	visited[u] = 1 ;

	for( int v=0 ; v< V ; v++){
		if(graph[u][v]!=0 && visited[v]==0 && graph[u][v] < key[v]){
			key[v] = graph[u][v];
			parent[v]= u;
		}
	}
}
printMST(parent, graph);



}












// Driver code 
int main()  
{  
    /* Let us create the following graph  
        2 3  
    (0)--(1)--(2)  
    | / \ |  
    6| 8/ \5 |7  
    | / \ |  
    (3)-------(4)  
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    // Print the solution  
    primMST(graph);  
  
    return 0;  
}  