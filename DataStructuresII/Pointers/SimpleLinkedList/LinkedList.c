#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


//Inicializando a lista
void init(LinkedList *list){
   
   
    // //Reservando espaço com o malloc
    // //convertendo para ponteiro do tipo Node
    // Node  * trashNode = (Node *) (malloc(sizeof(Node)));

    // //Verificando o sucesso da alocação
    // //Tendo em vista que o malloc retorna NULL em caso de erro
    // if(trashNode == NULL){
    //     printf("Erro ao alocar o trashNode");
    // }
     
    // //Apontando o dado para NULL
    // //E o next para ele mesmo
    // trashNode->data = NULL;
    // trashNode->next = trashNode;


    // //Tail aponta para o trashnode;
    // list->tail = trashNode;

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

//inserir na fila
int enqueue(LinkedList *list, void *data){
    /*Adicina-se sempre no final, que é o tail.
    Quando queremos acessar o início, digita-se tail->next*/


    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return 0;

    if(isEmpty(list)){
        
          new_node->data = data;
          //Tail aponta para o último
          list->tail = new_node;
          list->tail->next = list->tail;
          list->size++;

    }else{

        //novo nó aponta para o início
        new_node->data = data;
        new_node->next = list->tail->next;
        //inicio aponta para o novo nó
        list->tail->next = new_node;
        //Tail aponta para o último
        list->tail = new_node;

        list->size++;
    }

    return 1;
   

    
}
//remover da fila
void * dequeue(LinkedList *list){
    /*Para remover, deve-se retirar do início*/
      Node * aux;

    if(!isEmpty(list)){
        //aux aponta para o primeiro
        aux = list->tail->next;
        //list->tail->next aponta para o próximo
        list->tail->next = aux->next;
        //o aux-> não aponta mais para o próximo
        aux->next = NULL;

        //Cria-se um var data para liberar o ponteiro aux
        void* data = aux->data;
        free(aux);

        list->size--;
        return data;

    }

       return NULL;
   
}

