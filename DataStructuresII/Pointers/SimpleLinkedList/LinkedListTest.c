#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(){
    //criando uma linked list
   LinkedList list;
   int x;

    init(&list);

   //usando o malloc para alocar memória  do tipo inteiro
     int * number = (int *) malloc(sizeof(int));
        *number = 0;

         x = enqueue(&list,&number);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

     int * number1 = (int *) malloc(sizeof(int));
         *number1 = 1;
         x = enqueue(&list,&number1);
      
         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number2 = (int *) malloc(sizeof(int));
          *number2 = 2;
          x = enqueue(&list,&number2);
  

    (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

     int * y = (int *) dequeue(&list);
     printf("\ny(ADDRESS)=%p\n",y);
     printf("y=%d\n",*y);

     int a = 10; 
     void *ptr = &a; 
      rintf("%d\n", *(int *)ptr); 
    

    // for(int i=0;i<9;i++){
      
         
    //       x = enqueue(&list,vetor);
        
    //       if(x){
    //           printf("ok\n");
    //       }else{
    //           printf("No way!\n");
    //       }

    //       i++;
    // }
    
    


    // printf("Tail Real Address: %p\n",(&list.tail));
    // printf("Pointed Tail Address: %p\n",(list.tail));
    // printf("Real Next Address: %p\n",(&list.tail->next));

    //  init(&list);
    // printf("\n-----------------\n");

    // printf("Tail Real Address: %p\n",(&list.tail));
    // printf("Pointed Tail Address: %p\n",(list.tail));
    // printf("Real Next Address: %p\n",(&list.tail->next));
    // printf("Data from the Address pointed:%p\n",list.tail->data);
    // printf("Next pointed Address :%p\n",list.tail->next);
 
   

    return 0;
}