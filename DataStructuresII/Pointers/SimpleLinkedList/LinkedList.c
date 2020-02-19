#include <sdtio.h>
#include <stdlib.h>
#include "LinkedList.h"


void init(LinkedList *list){

    //Inicializando a lista
    list->first = NULL;
    list->size = 0;
}

int enqueue(LinkedList *list, void *data){
    //procura espaço reservado do tamanho da
    //struct da lista ligada
    list = (LinkedList*) (malloc(sizeof(LinkedList)));

    
}