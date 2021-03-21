typedef struct node{
int key;
char value[V_SIZE];
struct node *next;
struct node *down;
} node;




node *init(int branch){
	node *list_head, *level_head;
	int N=0;
	list_head=malloc(sizeof(node));
	level_head -> key=0;
	level_head -> next=NULL;
	level_head -> down=NULL;
	list_head -> key = branch*1000 + N;
	list_head -> next=NULL;
	list_head -> down = level_head;
	return list_head;

}

int is_empty(node *list){
	if(list -> down ->next ==NULL && list -> down -> down ==NULL){
		return 1;
	}
	else return 0;
}

int num_nodes(node *list){
	int count=0;
	node *p;
	p =list -> down;
	if(list -> down -> down == NULL) return 1;
	else {
		while (p -> down != NULL){
			count+=1;;
			p= p-> down;
		}
		return count+1;
	}
}

int num_levels(mode *list){
	node *p,*x;
	int c=0;
	num_levels=0;
	p=list ->down;
	while(p->down!= NULL){
		p=p->down;
	}
	x=p->next;
	while(x->next!=NULL){
		num_levels+=1;
		x=x->next;

	}
	return num_levels+1;
}

node insert(node *list,int key,char *value){
	node *p,*x,*q,*a,*b,*y=NULL;
	int N=(list->key)%1000;
	int B=(list->key)/1000;
	int i,A,D=0,level_head_sayisi=0;
	p=list->down;
	if(p->next==NULL){x=maloc(sizeof(node));
					x->key=key; 
					x->value=strcpy(x,value); 
					N+=1;}
	
	else{
	a=p;
		/*b=p->next;*/
	while(p->down!=NULL){
		p=p->down;}
			if(p->next==NULL){/*listede sadece level headler varsa*/
				A=N;
				dublication:if(A%B==0){
						A=A/B;
						D+=1;
						goto dublication;}
				while(a->down!=NULL){
					level_head_sayisi+=1;
					a=a->down;}
				a=list->down;
				for(i=0; i<(level_head_sayisi)-D ; i++){
					a=a->down;}
				while(a->down!=NULL){
					x=maloc(sizeof(node));
					x->key=key; 
					x->value=strcpy(x,value);
					a->next=x
					N+=1;
					if(y==NULL){y=x; x=NULL; a=a->down;}
					else{y->down=x; y=NULL; y=x; x=NULL; a=a->down;}

				}/*while(a->down!=NULL)*/
				}/*if(p->next==NULL)*/

		
		else{
	
		q=p->next;
		while(q->next!=NULL){
			if(q->key!=key){ 
				q=q->next;}
			else{c=1; break;}
		}
		q=p->next;
		if(c=0){
			A=N;
			dublication:if(A%B==0){
					A=A/B;
					D+=1;
					goto dublication;}
			while(a->down!=NULL){
				level_head_sayisi+=1;
				a=a->down;}
			a=list->down;
			for(i=0; i<(level_head_sayisi)-D ; i++){
				a=a->down;
			}
			while(a->down!=NULL){
				if(a->next==NULL){
					
						x=maloc(sizeof(node));
						x->key=key; 
						x->value=strcpy(x,value);
						a->next=x;
						
						N+=1;
						}
				else{
					b=a->next;
					p=a;
					car:if((b->key)>key){
								x=maloc(sizeof(node));
								x->key=key; 
								x->value=strcpy(x,value);
								x->next=b;
								p->next=x;
								
								N+=1;}
						
						else{
							if(b->next==NULL){
								x=maloc(sizeof(node));
								x->key=key; 
								x->value=strcpy(x,value);
								x->next=NULL; x->down=NULL;
								b->next=x;
								
								
								N+=1;

							}
							else{b=b->next;
							p=p->next;
							goto car;}}
				}
				if(y==NULL){

				y=x;
				x=NULL;
				a=a->down;}
				else (y!=NULL){
				y->down=x;
				y=NULL;
				y=x;
				x=NULL;

				a=a->down;}
		}/*while(a->down!=NULL) */
			


return y;}/*if(c=0)*/
		if(c=1){
			a=list->down;
			while(a->down!=NULL){
				if(a->next==NULL) {a=a->down;}
				else{
					b=a->next;
					while(b->next!=NULL){
						if(b->key==key){b->value=strcpy(b,value);}
						else {b=b->next;}}
					a=a->down;

				}
			}/*while(a->down!=NULL)*/)


		}










}/*else*/}}/*insert func*/






		


















































		bus:if((q->key)>key){
			x=malloc(sizeof(node));
			x->key=key;
			x->value=strcpy(x,value);
			x->next=q;
			p->next=x;

			while(a->down!=NULL){
				car:if(a->next==NULL){
					b=malloc(sizeof(node));
					b->key=key;
					b->value=strcpy(b,value);
					a->next=b;
					a=a->down;
					goto car;
				}
				else{}

			}
			



			return x;}
		else if((q->key)==key) return NULL;
		else{
			q=q->next;
			p=p->next;
			goto bus;
		}
		



	}
}











Node* removeNode(Node *head, int index){
   int i = 0;
   Node *p,*q;
   p = head;
   for(i = 0; i < index - 1; i++){
       p = p -> next;
   }
   q = p -> next -> next;
   free(p -> next);
   p -> next = q;
   return head;
}


void clear(node *list){

	  node *p,*x,*current,*next;
     
     current=list->down;
     p=current;

     while(p->down!=NULL){
     	p=p->down;
	     while (current != NULL) {
	         next = current->next;
	         free(current);

	         current = next;
	     }
	     list->down=p;
	     current=p;
	 }
	 while (current != NULL) {
	         next = current->next;
	         free(current);

	         current = next;
	     }


     list = NULL;
     

















}
















if(c=0){
			A=N;
			dublication:if(A%B==0){
					A=A/B;
					D+=1;
					goto dublication;}
			while(a->down!=NULL){
				level_head_sayisi+=1;
				a=a->down;}
			a=list->down;
			for(i=0; i<(level_head_sayisi)-D ; i++){
				a=a->down;
			}
			while(a->down!=NULL){
				birinci:if(a->next==NULL){
					
						x=maloc(sizeof(node));
						x->key=key; 
						x->value=strcpy(x,value);
						a->next=x;
						y=x;
						free(x);
						N+=1;
						a=a->down;}
				else{
					b=a->next;
					p=a;
			car:if((b->key)>key){
						x=maloc(sizeof(node));
						x->key=key; 
						x->value=strcpy(x,value);
						x->next=b;
						p->next=x;
						
						N+=1;}
				
				else{
					if(b->next==NULL){}
					b=b->next;
					p=p->next;
					goto car;}
				if(y==NULL){
				y=x;
				free(x);
				a=a->down;
				
				
				}
				else (y!=NULL){
				y->down=x;
				free(y);
				y=x;
				free(x);

				a=a->down;
				}}
		




		}/*while(a->down!=NULL) */
			


}/*if(c=0)*/






			

