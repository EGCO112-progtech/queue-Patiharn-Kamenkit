#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
   NodePtr headPtr=NULL;
   NodePtr tailPtr=NULL;
/* For struct Queue*/
  Queue  q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;
   int i,x,numcustomer=1;
   

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
          printf("Customer No: %d\n",numcustomer);
            x=dequeue_struct(&q);
          numcustomer++;
        }
        else {
            enqueue_struct(&q, atoi(argv[i]),atoi(argv[i+1]));
            i++;
            }
 }
  printf("===============================\n");
  printf("There are %d ppl left in the game\n",q.size);

  printf("Clearing queue\n");
  while(q.size>0)
    dequeue_struct(&q);
  return 0;
  }

