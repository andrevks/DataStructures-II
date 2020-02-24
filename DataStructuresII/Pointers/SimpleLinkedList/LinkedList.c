#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void init(LinkedList *list){
    int da = 4;
    //Inicializando a lista
    list->size = 0;//setando o size para 0
    list->tail = list->tail->next;//Do tail apontando para o próximo node
    list->tail->data = NULL;//Estando no node, apontando o data para NULL(ERRO DE SEGMENTION FAULT NESSA LINHA)
}

// void print(LinkedList * list){
//     printf("Endereço Tail: %p\n",(list->tail));
//     printf("Next Address: %p\n",(list->tail->next));
// }

// int enqueue(LinkedList *list, void *data){
//     //procura espaço reservado do tamanho da
//     //struct da lista ligada
//     list = (LinkedList*) (malloc(sizeof(LinkedList)));

    
// }