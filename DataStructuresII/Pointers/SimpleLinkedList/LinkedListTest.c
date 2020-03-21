#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
   LinkedList list;
   LinkedList list2;
   int x;

    init(&list);
    init(&list2);
    //Como se usa o tipo Void, deve-se alocar um endereço de memória
    //sempre quando retornar algum dado, deve-se converter para o tipo do dado guardado
  
   //usando o malloc para alocar memória  do tipo inteiro
     int *number = (int *) malloc(sizeof(int));

        *number = 55;

      

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


    //   int * number3 = (int *) malloc(sizeof(int));
    //       *number3 = 66;
    //      x = add(&list,1,number3);

    //       (x == 1)?printf("Inserido!!\n"):printf("Não inserido!!\n"); 


    //  int * number4 = (int*) malloc(sizeof(int));
    //  *number4 = 12312321;
    

    //  printf("IndexOf:%d\n",removeData(&list,number4,comparar));



    


    printf("\n----------\n");
    int *number10 = (int *) malloc(sizeof(int));
        *number10 = 10;
      

         x = push(&list2,number10);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 
     

     int * number11 = (int *) malloc(sizeof(int));
         *number11 = 11;
         x = push(&list2,number11);

         (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

      int * number12 = (int *) malloc(sizeof(int));
          *number12 = 12;
         x = push(&list2,number12);
        (x == 1)?printf("Inserido\n"):printf("Não inserido\n"); 

    //     printf("First: %d\n ",*((int*)first(&list2)));

    // printf("Last: %d\n ",*((int*)last(&list2)));

    //  x = addAll(&list,0,&list2);
    //   printf("Elementos Inseridos:%d\n",x);

    
    //  printf("First: %d\n ",*((int*)first(&list2)));
    // printf("Last: %d\n ",*((int*)last(&list2)));

      printf("First: %d\n ",*((int*)first(&list)));
    printf("Last: %d\n ",*((int*)last(&list)));
   

       while(!isEmpty(&list))
       printf("valor retirado: %d\n ",*((int*)dequeue(&list)));  


    //    while(!isEmpty(&list2))
    //    printf("valor retirado: %d\n ",*((int*)dequeue(&list2)));  




    
    return 0;
}


