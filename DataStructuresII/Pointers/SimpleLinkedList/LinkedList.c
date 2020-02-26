#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


//Inicializando a lista
void init(LinkedList *list){
   
   
    //Reservando espaço com o malloc
    //convertendo para ponteiro do tipo Node
    Node  * trashNode = (Node *) (malloc(sizeof(Node)));

    //Verificando o sucesso da alocação
    //Tendo em vista que o malloc retorn NULL em caso de erro
    if(trashNode == NULL){
        printf("Erro ao alocar o trashNode");
    }
    
    //Apontando o dado para NULL
    //E o next para ele mesmo
    trashNode->data = NULL;
    trashNode->next = trashNode;

    // printf("\n,.,.,,.,,.,.,,.,\n");
    // printf("TrashNode Address Pointed to an Valid area:%p\n", trashNode);
    // printf("TrashNode Address of the next: %p\n",trashNode->next);
    // printf("\n,.,.,,.,,.,.,,.,\n");

    //Tail aponta para o trashnode;
    list->tail = trashNode;
    list->size = 0;

}
//Verificar se a lista está vazia
bool isEmpty(LinkedList *list){

    //se o tail é igual ao "head" 
    //a lista está vazia
    if(list->size = 0){
        return true;
    }else{
        return false;
    }
}
int enqueue(LinkedList *list, void *data){
    
   if(isEmpty){

   }
   

    
}

// void print(LinkedList * list){
//     printf("Endereço Tail: %p\n",(list->tail));
//     printf("Next Address: %p\n",(list->tail->next));
// }
