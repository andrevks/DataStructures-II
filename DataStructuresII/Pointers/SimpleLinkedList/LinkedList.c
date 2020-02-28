#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


//Inicializando a lista
void init(LinkedList *list){
   
   
    //Reservando espaço com o malloc
    //convertendo para ponteiro do tipo Node
    Node  * trashNode = (Node *) (malloc(sizeof(Node)));

    //Verificando o sucesso da alocação
    //Tendo em vista que o malloc retorna NULL em caso de erro
    if(trashNode == NULL){
        printf("Erro ao alocar o trashNode");
    }
     
    //Apontando o dado para NULL
    //E o next para ele mesmo
    trashNode->data = NULL;
    trashNode->next = trashNode;


    //Tail aponta para o trashnode;
    list->tail = trashNode;
    list->size = 0;

}
//Verificar se a lista está vazia
bool isEmpty(LinkedList *list){

    //Se o tamanho é igual a zero a lista está vazia
    if(list->size == 0){
        return true;
    }else{
        return false;
    }
}
int enqueue(LinkedList *list, void *data){
    
    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return 0;

    if(isEmpty){
          new_node->next = NULL;
          new_node->data = data;
            //Head(tail->next) aponta para o primeiro nó
          list->tail->next = new_node;
          //Tail aponta para o último
          list->tail = new_node;
          list->size++;

    }else{
        //novo nó aponta para o início
        new_node->data = data;
        new_node->next = list->tail->next;
        //Head aponta para o novo nó
        list->tail->next = new_node;
        list->size++;
    }
  
    return 1;
   

    
}

// void print(LinkedList * list){
//     printf("Endereço Tail: %p\n",(list->tail));
//     printf("Next Address: %p\n",(list->tail->next));
// }
