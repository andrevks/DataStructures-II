#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/* Aqui o usuário pode criar uma função com retorno
bool e dois parametros Void*/

int main(){
  
    //criando uma linked list
   LinkedList list;
   int x;

    init(&list);
    //Como se usa o tipo Void, deve-se alocar um endereço de memória
    //sempre quando retornar algum dado, deve-se converter para o tipo do dado guardado
  
   //usando o malloc para alocar memória  do tipo inteiro
     int *number = (int *) malloc(sizeof(int));
        *number = 55;
        printf("number:%d\n",*number);
      

         x = push(&list,number);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 
     

     int * number1 = (int *) malloc(sizeof(int));
         *number1 = 77;
         x = push(&list,number1);

         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number2 = (int *) malloc(sizeof(int));
          *number2 = 99;
         x = push(&list,number2);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

        //    int * data1 = (int*) (list.tail->data);
        // printf("list->tail->data= %d\n",*data1);


      int * number3 = (int *) malloc(sizeof(int));
          *number3 = 66;
         x = add(&list,1,number3);

          (x == 1)?printf("Inserido!!\n"):printf("Não inserido!!\n"); 


    

 

    while(!isEmpty(&list))
        printf("valor retirado: %d\n ",*((int*)dequeue(&list)));
     
    


    //  printf("LAST:%d\n",*((int*)last(&list)));

    
   


    



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


