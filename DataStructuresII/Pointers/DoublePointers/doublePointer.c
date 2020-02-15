    
  /*Algoritmo para entendimento de ponteiros duplos em C*/
   
    #include <stdio.h>
    #include <stdlib.h>

    #define TAMANHO 10
    int i;

    //Ponteiro duplo Matriz
    int **matriz;

    int main() {

      //Alocando memória do tipo 
      //Ponteiro inteiro

      //Multiplica-se pelo TAMANHO para criar
      //Ponteiros que serão reservados
      //contiguamente, como um vetor;

      //o retorno void é então 
      //convertido para Pointeiro duplo
      //inteiro
      
      matriz = (int **) malloc(sizeof(int *) * TAMANHO);


      
      if (matriz == NULL) {
        printf("Erro ao alocar memória");
        free(matriz);
      }


      for (i = 0; i < TAMANHO; i++) {
        //A cada espaço reservado da Matriz criada
        //Com o TAMANHO;
        //Reservamos espaço para ponteiros do tipo int;
        //que por sua vez estarão apontando
        //para um endereço da memória que
        //de fato estará apontando para algum endereço de memória, que depois será atribuido
        *(matriz+i) = (int *) malloc( (i+1) * sizeof(int));

        printf("*(matriz+%d) com %d Espaço(s) Reservado(s)\n",i,(i+1));

        if (*(matriz+i) == NULL) {
          printf("Erro ao alocar memória");
          free(matriz);
        }
      }

    printf("\n ----------IMPRESSÂO DA MATRIZ-------------\n");
    int count = 0;
    for(i = 0;i<TAMANHO;i++){
        for(int j=0;j<i+1;j++){

            *(*(matriz+i)+j) = j+1;
           
              printf("%d ",matriz[i][j]);

            
        }
        printf("\n");
    }
    //   *(*(matriz+0)+0) = 1;


    //   *(*(matriz+1)+0) = 3;
    //   *(*(matriz+1)+1) = 4;

    //   *(*(matriz+2)+0) = 7;
    //   *(*(matriz+2)+1) = 8;
    //   *(*(matriz+2)+2) = 8;

    //   *(*(matriz+3)+0) = 9;
    //   *(*(matriz+3)+1) = 10;
    //   *(*(matriz+3)+2) = 11;
    //   *(*(matriz+3)+3) = 12;


      // for(i =0; i<TAMANHO; i++){
      //   for(j = 0; j<)
      // }



    //   printf("%d %d\n", matriz[0][0], matriz[0][1]);
    //   // printf("%d %d\n", matriz[1][0], matriz[1][1]);

    //   printf("%d %d\n", matriz[1][0], matriz[1][1]);

    //   printf("%d %d %d\n", matriz[2][0], matriz[2][1],matriz[2][2]);
      free(matriz);
      return EXIT_SUCCESS;
    }