#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

/* Aqui o usuário pode criar uma função com retorno
bool e dois parametros Void*/

bool comparar(void *data0, void *data1){

    //recebe o parâmetro e converte no 
    //tipo de dado desejado 
    int * d0 = (int*) data0;
    int * d1 = (int*) data1;

    return (*d0 == *d1)?true:false;
}

int main(){
  
    //criando uma DoublyLinkedList
   DoublyLinkedList list;
   DoublyLinkedList list2;
   int x;

    init(&list);
    init(&list2);

    //Como se usa o tipo Void, deve-se alocar um endereço de memória
    //sempre quando retornar algum dado, deve-se converter para o tipo do dado guardado
  
   //usando o malloc para alocar memória  do tipo inteiro
     int *number = (int *) malloc(sizeof(int));
        *number = 1001;

         x = enqueue(&list,number);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 
     

     int * number1 = (int *) malloc(sizeof(int));
         *number1 = 1002;
         x = enqueue(&list,number1);

         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number3 = (int *) malloc(sizeof(int));
          *number3 = 1003;
         x = enqueue(&list,number3);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

        //    int * data1 = (int*) (list.tail->data);
        // printf("list->tail->data= %d\n",*data1);
    // int *number3 =  (int*)malloc(sizeof(int));
    // *number3 = 10013;
    // printf("IndexOf:%d\n",*((int*)getPos(&list,4)));

     int *number4 = (int *) malloc(sizeof(int));
        *number4 = 1004;
      
         x = enqueue(&list2,number4);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 
     

     int * number5 = (int *) malloc(sizeof(int));
         *number5 = 1005;
         x = enqueue(&list2,number5);

         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number6 = (int *) malloc(sizeof(int));
          *number6 = 1006;
         x = enqueue(&list2,number6);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

    printf("INICIO: %d\n ",*((int*)first(&list)));
    printf("FINAL: %d\n ",*((int*)last(&list)));

    printf("INICIO: %d\n ",*((int*)first(&list2)));
    printf("FINAL: %d\n ",*((int*)last(&list2)));

      x = addAll(&list,1,&list2);

      printf("\nElementos inseridos: %d\n",x);

    //    printf("INICIO: %d\n ",*((int*)first(&list)));
    //   printf("FINAL: %d\n ",*((int*)last(&list)));

    while(!isEmpty(&list))
        printf("valor retirado: %d\n ",*((int*)dequeue(&list)));

   


    return 0;
}


