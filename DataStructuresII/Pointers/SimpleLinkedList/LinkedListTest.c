#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(){
    //criando uma linked list
   LinkedList list;

    init(&list);

   //usando o malloc para alocar memória do tipo inteiro
   int * number1 = (int *) malloc(sizeof(int));
    *number1 = 1;

    





    


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