#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(){
    //criando uma linked list
   LinkedList list;
   int x;

    init(&list);

   //usando o malloc para alocar memória  do tipo inteiro
     int *number = (int *) malloc(sizeof(int));
        *number = 0;
        printf("number:%d",*number);
      

         x = push(&list,number);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 
     

     int * number1 = (int *) malloc(sizeof(int));
         *number1 = 1;
         x = push(&list,number1);

         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number2 = (int *) malloc(sizeof(int));
          *number2 = 2;
          x = push(&list,number2);

           int * data1 = (int*) (list.tail->data);
        printf("list->tail->data= %d\n",*data1);


  

    (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

    while(!isEmpty(&list))
        printf("valor retirado: %d\n ",*((int*)dequeue(&list)));



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