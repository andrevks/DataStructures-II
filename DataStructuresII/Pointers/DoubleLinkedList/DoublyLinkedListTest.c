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
  
    //criando uma linked list
   DoublyLinkedList list;
   int x;

    init(&list);
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

      int * number2 = (int *) malloc(sizeof(int));
          *number2 = 1003;
         x = enqueue(&list,number2);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

        //    int * data1 = (int*) (list.tail->data);
        // printf("list->tail->data= %d\n",*data1);
    int *number3 =  (int*)malloc(sizeof(int));
    *number3 = 1002;
    printf("IndexOf:%d\n",indexOf(&list,number3,comparar));


    // while(!isEmpty(&list))
    //     printf("valor retirado: %d\n ",*((int*)pop(&list)));
        
    //    printf("Last:%d\n",*((int*)last(&list)));
        //    printf("First:%d\n",*((int*)first(&list)));
        // printf("Top:%d\n",*((int*)top(&list)));


    //   int * number4 = (int *) malloc(sizeof(int));
    //       *number4 = 10;

    //     x = add(&list,1,number4);
    //     (x == 1)?printf("Inserido!!\n"):printf("Não inserido!!\n"); 
    // while(!isEmpty(&list))
    //     printf("valor retirado: %d\n ",*((int*)dequeue(&list)));

    // x = indexOf(&list,number4,comparar);
    // printf("IndexOf:%d",x);

    return 0;
}


