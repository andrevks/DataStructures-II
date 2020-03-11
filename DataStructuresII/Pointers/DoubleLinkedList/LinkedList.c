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
    trashNode->

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

//inserir na fila
int enqueue(LinkedList *list, void *data){

    /*Adicina-se sempre no final, que é o tail.
    Quando deseja-se acessar o início, digita-se tail->next*/

    //Uma nova área da memória, suficiente para armazenar um nó
    //é  reservada usando malloc

    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return 0;

    if(isEmpty(list)){
        
          new_node->data = data;
          //Tail aponta para o último
          list->tail = new_node;
          //O Tail->next aponta para o último, pois nesse momento
          //o último é igual o primeiro
          list->tail->next = list->tail;
          list->size++;

    }else{
        //sempre começa apontando o novo nó para a lista
        //para não haver risco de perder o endereço da lista


        //novo nó aponta para o início
        new_node->data = data;
        new_node->next = list->tail->next;
        //inicio aponta para o novo nó
        list->tail->next = new_node;
        //Tail aponta para o último
        list->tail = new_node;

        list->size++;
    }

    //Representa a quantidade de elementos inseridos
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

int push(LinkedList *list, void *data){
    /*Como a função enqueue é igual a push*/
    return enqueue(list,data);
}

void * pop(LinkedList *list){

    Node * aux;

    if(!isEmpty(list)){

        aux = list->tail->next;

        while (aux->next != list->tail) aux = aux->next;


          aux->next = list->tail->next; 
          
          void * data = list->tail->data;

          free(list->tail);

          list->tail = aux;

          return data;
    }

    return NULL;
}

//consulta o último item da pilha
void* top(LinkedList *list){
    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->data;
}

//consulta o primeiro item da lista
void* first(LinkedList *list){

    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->next->data;
}
//Consulta o último item da lista
void* last(LinkedList *list){
    //Como o objetivo é retornar o último
    //a função Top é reaproveitada
    return top(list);

    
}

 int add(LinkedList *list, int pos, void *data){


        if(pos <= 0)return push(list,data);

        Node * aux = getNodeByPos(list,(pos-1));
        if(aux == NULL)return 0;

        Node * new_node =(Node*) malloc(sizeof(Node));

        new_node->data = data;

        new_node->next = aux->next;
        aux->next = new_node;

        list->size++;

        return 1;

 }

 Node* getNodeByPos(LinkedList *list, int pos){

        //Se a lista estiver vazia ou a posição foi maior ou igual ao tamanho
        //retorna NULL
        if(isEmpty(list) || pos >= list->size) return NULL;


        //Se caso não acontecer, continuamos e o aux aponta para o início
        Node * aux = list->tail->next;

        //o contador é criado
        //enquanto a condição do meio acontecer o loop continua
        //Aux aponta para os nós e incrementa o count

        for(int count = 0;(aux!=list->tail && pos!= count);count++, aux = aux->next);
        return aux;
        

 }