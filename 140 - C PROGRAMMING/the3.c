#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
	struct vertex
		{ char tag;
		  char *label;
		  struct vertex *edge[1]; }
	vertex, *vp;
#define TAG(vp)   ((vp)->tag)
#define LABEL(vp) ((vp)->label)
#define EDGE(vp)  ((vp)->edge)


int len_vertex(vertex** arr){
	int i=0;
	while( LABEL(arr[i]) ){
		i++;
	}
	return i;
}

int len_char(char** arr){
	int i=0;
	while(*arr[i]!=0){
		i++;
	}
	return i;
}
int are_labels_same(vertex **arr,vertex *edge){
	int i;
	for(i=0; i<len_vertex(arr) ; i++ ){
		if(LABEL(arr[i])==LABEL(edge)) return 1;

	}
	return 0;


}
int edge_count(vp graph){
	int i=1,count=0;
	
	while(EDGE(graph)[i]){
		
		count++;
		i=i+1;
	}
	
	return i-1;
}


int is_in_char(char **arr,char *edge){
	int i;
	for(i=0; i<len_char(arr) ; i++ ){
		if(arr[i]==edge) return 1;

	}
	return 0;

}
int is_in_vertex(vertex **arr,vertex *edge){
	int i;
	for(i=0; i<len_vertex(arr) ; i++ ){
		if(arr[i]==edge) return 1;

	}
	return 0;

}
int edgeimi(vertex *a1 , vertex * a2){
	int i=1;
	
	for(i=1; i<= edge_count(a1); i++){
		if(EDGE(a1)[i]==a2){
			return 1;
		}

	}
	return 0;
	
	


}

vertex **names(vp graph){
	
	char **B = NULL;
	int i=1,j=1, k=0, x,count=0, y;
	
	
	
	vertex **N =NULL;
	N= calloc(sizeof(vp*),50);
	
	for(i=0; i<50; i++){
		N[i] = calloc(sizeof(vp),13); 

	}

	
	
	B= calloc(sizeof(char*),50);
	for(i=0; i<50; i++){
		B[i] = calloc(sizeof(char),13); 

	}

  	N[0]=graph;
  

	
	while(j<=edge_count(graph)){
		

			N[j] = EDGE(graph)[j];

			j++;

	}
	
	B[0]=LABEL(N[0]);



	


	
	
	x = len_vertex(N);
	y = len_char(B);
	

	while(x!=y){

		
		for(j=1; j< x ; j++){ 
			
			
			for(i=1; i<= edge_count(N[j]) ; i++){ 
				
				
				
				if(!is_in_vertex( N ,EDGE(N[j])[i] ) &&  !is_in_char( B ,LABEL(EDGE(N[j])[i] )) ){
					
				
					N[x]= EDGE(N[j])[i];
					x++;
								

					
			}


			
		}

	
		B[y]=LABEL(N[j]);
		y++;
		


	}
	}



	free(B);
return N;

}

vertex **birlesim(vertex **N1 , vertex **N2){
		int i=0;
		int x= len_vertex(N1);


		

		for(i=0; i< len_vertex(N2); i++){
			if( !are_labels_same(N1 , N2[i]) ) {
				LABEL(N1[x])= LABEL(N2[i]);
				x++;
			}
		}

		for(i=0; i<x;i++){
			} 
		return N1;
}
int **adjacency(vertex **N1){
	int i=0,j,len_N1;
	
	
	
	int **matrix = malloc(sizeof(int*)*len_N1);
	len_N1=len_vertex(N1);
	for(i=0 ; i< len_N1; i++){
		matrix[i] = malloc(sizeof(int)*len_N1); 
	}





	for(i=0; i< len_N1; i++){
	}

	for(j=0; j< len_N1; j++){
		
		for(i=0 ; i<len_N1; i++){



			
			if(edgeimi( N1[j] , N1[i] )){
				matrix[j][i]=1;
			}
			else matrix[j][i]=0;
		}
	}


return matrix;


}
int find(vertex **N2, int **matrix2, char *colom, char * row, int len){ 
	int i,j;
	for(j=0 ; j< len ; j++){

		for(i=0 ;  i< len ; i++){
			if(LABEL(N2[j])==colom && LABEL(N2[i])==row){
				

				return matrix2[j][i];
			}
		}
	}
	return -1;

}

int **son_islem(int **matrix1 , int **matrix2,  vertex **N1 , vertex **N2){
	int i,j;
	int len= len_vertex(N1);

	int **matrix3 = malloc(sizeof(int*)*len);
	
	for(i=0 ; i< len; i++){
		matrix3[i] = malloc(sizeof(int)*len); 
	}


	for( j=0 ; j< len ; j++){

		for(i=0 ; i< len ; i++){

			matrix3[j][i]= matrix1[j][i] || find( N2, matrix2, LABEL(N1[j]) ,LABEL(N1[i]),  len);

		}
	}
	
	


	return matrix3;

}
int bir_sayisi(int **matrix3,int i,int len){
	int count=1;
	int j=0;
	for(j=0; j<len ; j++ ){
		if(matrix3[i][j]==1) count++;
	}
	return count;
}
char **alfabetik(char **str , int len ){

	
		int i, j;
     char *temp;

for(i=0; i<len-1; ++i){
	
        
        for(j=i+1; j<len ; ++j)

        {

        	
        	if(str[i]==NULL || str[j]==NULL) {;}

            else if(strcmp(str[i], str[j])>0)
            {
            	
                

               temp =str[i];
                
                
                str[i]=str[j];
                
                
                
                str[j]= temp;
                
               
            }
        }

}


    
}

vertex *findd(vertex **edgee,char *label,int len){
	int i;
	for(i=0; i<len ; i++){
		if(LABEL(edgee[i])==label) return edgee[i];
	}
}

vertex **chara_cevir(vertex **edge1,int len){
	int i,h,k;
	vertex **edges2; 

	char **array;
	array=malloc(sizeof(char*)*len);
	for(i=0; i<len; i++){
		array[i] = malloc(sizeof(char)*len);
	}
	
	edges2= malloc(sizeof(edges2)*len);
	
	for(h=0; h<len; h++){
		edges2[h] = malloc(sizeof(edges2)*len);
	}
	




	for(i=0; i<len ;i++){
		array[i]=LABEL(edge1[i]);
	}

		
	alfabetik(array,len);


	for(k=0; k<len ;k++ ){
		edges2[k]= findd(edge1, array[k],len);
	}
	free(array);
	return edges2;





}

vertex **fonk(vertex **edge1, int len){

	vertex **edges2;
	int h;

		edges2= malloc(sizeof(edges2)*len);
	
	for(h=0; h<len; h++){
		edges2[h] = malloc(sizeof(edges2)*len);
	}

	edges2= chara_cevir(edge1,len);
	
	return edges2;


}

vp merge(vp graph1, vp graph2){


	
	vertex *burhan;
	

	
	int count=0,x,j,k,l,h,w=0,m=1;
	int **matrix3,i;
	int len=len_vertex(birlesim(names(graph1),names(graph2)));
	
	vertex **N1; 
	vertex **edges;
	edges= malloc(sizeof(edges)*len);
	burhan= malloc(sizeof(burhan)+50*sizeof(vertex));
	for(i=0; i<len; i++){
		edges[i] = malloc(sizeof(edges)*len);
	}



	N1= malloc(sizeof(N1)*len);
	
	for(i=0; i<len; i++){
		N1[i] = malloc(sizeof(N1)*len);
	}



	N1=birlesim(names(graph1),names(graph2)) ; 


	matrix3 = malloc(sizeof(int*)*len);
	
	for(i=0 ; i< len; i++){
		matrix3[i] = malloc(sizeof(int)*len); 
	}


	matrix3 = son_islem (  adjacency( birlesim(names(graph1),names(graph2))) 
		, adjacency( birlesim(names(graph2),names(graph1))) 
		,birlesim(names(graph1),names(graph2)) 
		, birlesim(names(graph2),names(graph1)));
	
	for(i=0 ; i< len ; i++){

		vertex *new = N1[i];


		new = malloc(sizeof(N1[i])+ bir_sayisi(matrix3,i,len)*sizeof(vertex));
		LABEL(new)=LABEL(N1[i]);

		x=bir_sayisi(matrix3, i, len);
		count=1;
		
		
		
		for(j=0 ; j<len ; j++ ){

				if(matrix3[i][j]){ 
					edges[count-1]=N1[j];
					count++;
				}
			
		}
		
		edges=fonk(edges,len);

		
		

			



			while( LABEL(edges[w]) ){
				
				EDGE(new)[m] = edges[w];






				w++;
				m++;
			}
			m=1;
			w=0;
		









		free(edges);
		edges= malloc(sizeof(edges)*len);
	
	for(h=0; h<len; h++){
		edges[h] = malloc(sizeof(edges)*len);
	}


		
			

	


	}

	




	


	return burhan;
	

	


}

