#include <stdio.h>
typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x ,int y){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){
  
  new_node->order_number=x;
  new_node->qty=y;
  new_node->nextPtr=NULL; 
  
  if(q->headPtr==NULL) q->headPtr=new_node; 
  else q->tailPtr->nextPtr=new_node; 
  
  q->tailPtr=new_node;
  q->size++;
  /*Finish enqueue */
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   int price,buy=0,chance;
   if(q->size>0){
      switch(t->order_number){
        case 1: printf("Ramen\n"); 
                price=100*t->qty; 
                printf("You have to pay %d\n",price);
                break;
        
        case 2: printf("SOM TUM\n");
                price=20*t->qty; 
                printf("You have to pay %d\n",price);
                break;
        
        case 3: printf("FRIED CHICKEN\n");
                price=50*t->qty;
                printf("You have to pay %d\n",price);
                break;
        default: printf("No Food\n"); goto ym;
      }
            while(buy<price){
              printf("Cash ");
              scanf("%d",&buy);
             }
              printf("THANK YOU!!!\n");
              if(buy>price){
                chance = buy-price;
                printf("Chance is: %d\n",chance); 
              }
     //int value= t->data; 
      
      ym:

     
     q->headPtr=q->headPtr->nextPtr; 
     if(!q->headPtr) q->tailPtr=NULL; 
     q->size--;
     free(t); 
     /*Finish dequeue */ 
     return price;
   }
   printf("Empty queue");
   return 0;
}

int dequeue2(Queue *q)
{
  NodePtr t=q->headPtr;
  int value= t->data; 
  q->headPtr=q->headPtr->nextPtr; 
     if(!q->headPtr) q->tailPtr=NULL; 
     q->size--;
     free(t); 
     /*Finish dequeue */ 
     return value;
}