#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


//Inicializando a lista
void init(DoublyLinkedList *list){
   
   
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
    trashNode->previous = trashNode;

    //Tail aponta para o trashnode;
    list->tail = trashNode;

    list->size = 0;

}
//Verificar se a lista está vazia
bool isEmpty(DoublyLinkedList *list){

    //Se o tamanho é igual a zero a lista está vazia
    if(list->size == 0){
        return true;
    }else{
        return false;
    }
}

//inserir na fila
int enqueue(DoublyLinkedList *list, void *data){

    /*Adicina-se sempre no final, que é o tail.
    Quando deseja-se acessar o início, digita-se tail->next*/

    //Uma nova área da memória, suficiente para armazenar um nó
    //é  reservada usando malloc

    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return -2;

        //novo nó aponta para o início
        new_node->data = data;
        new_node->next = list->tail->next;
        list->tail->next->previous = new_node;
        new_node->previous = list->tail;

        //inicio aponta para o novo nó
        list->tail->next = new_node;
        //Tail aponta para o último
        list->tail = new_node;

        list->size++;

    //Representa a quantidade de elementos inseridos
    return 1;
}

//remover da fila
void * dequeue(DoublyLinkedList *list){

       if(isEmpty(list))return NULL;
       
    /*Para remover, deve-se retirar do início*/
      Node * auxFirst;
      Node * trash;
      if(auxFirst == NULL)return NULL;
      if(trash == NULL)return NULL;

 
        //trash aponta para o inicio que possui o trashNode
        trash = list->tail->next;
        //o auxFirst aponta para o próximo Nó válido
        auxFirst = trash->next;
        //o next aponta para o elemento depois do auxFirst
        trash->next = auxFirst->next;
        //aux->next->previous aponta para o que está antes dele
        auxFirst->next->previous = trash;

        auxFirst->next = NULL;
        auxFirst->previous = NULL;

        //Cria-se um var data para liberar o ponteiro aux
        void* data = auxFirst->data;
        free(auxFirst);

        list->size--;
        return data;
}

int push(DoublyLinkedList *list, void *data){
    /*Como a função enqueue é igual a push*/
    return enqueue(list,data);
}

void * pop(DoublyLinkedList *list){

    Node * aux;

    if(!isEmpty(list)) return NULL;

    



        // aux = list->tail->next;

        // while (aux->next != list->tail) aux = aux->next;


        //   aux->next = list->tail->next; 
          
        //   void * data = list->tail->data;

        //   free(list->tail);

        //   list->tail = aux;

          return data;
    

}

//consulta o último item da pilha
void* top(DoublyLinkedList *list){
    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->data;
}

//consulta o primeiro item da lista
void* first(DoublyLinkedList *list){

    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->next->data;
}
//Consulta o último item da lista
void* last(DoublyLinkedList *list){
    //Como o objetivo é retornar o último
    //a função Top é reaproveitada
    return top(list);

    
}

 int add(DoublyLinkedList *list, int pos, void *data){


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

  Node* getNodeByPos(DoublyLinkedList *list, int pos){

        //Se a lista estiver vazia ou a posição foi maior ou igual ao tamanho
        //retorna NULL
        if(isEmpty(list) || pos >= list->size) return NULL;


        //Se caso não acontecer, continuamos e o aux aponta para o início
        Node * aux = list->tail->next;

        //o contador é criado
        //enquanto a condição do meio acontecer o loop continua
        //Aux aponta para os nós e incrementa o count

        for(int count = 0; (aux != list->tail && pos != count); count++, aux = aux->next);
    
        return aux;
        

 }

//retorna o index do dado informado
 int indexOf(DoublyLinkedList *list, void *data, compare equal){
     
     //se a lista está vazia retorna -1
     if(isEmpty(list))return -1;
     
     //se o primeiro item do início é igual então retorna a pos 0
     if(equal(list->tail->next->data,data)) return 0;

     //Senão, o aux é criado e a lista é percorrida
     //a partir do segundo elemento.
     int i;

     Node * aux;
     aux = list->tail->next;
     aux = aux->next;
    
     for(i=1;(aux != list->tail->next && !equal(aux->data,data)); i++, aux = aux->next);
    
    //Se o aux aponta o início, então percorreu a lista sem encontrar nada
    return (aux == list->tail->next)?-1:i;
 }

 //remove o nó baseado no dado
 bool removeData(DoublyLinkedList *list, void *data, compare equal){

     //testa se a lista está vazia
     if(isEmpty(list))return false;

    //Se o dado do inicio for igual 
     if(equal(list->tail->next->data,data)){

         Node * aux;
         aux = list->tail->next;
         list->tail->next = aux->next;

         aux->next = NULL;
         free(aux->data);
         free(aux);

         list->size--;

         return true;
     }

        //senão
         Node * aux;
         Node * remove;

         aux = list->tail->next;

        //A lista é percorrida até chegar ao final ou até achar o dado
        for(int i = 0;(aux->next != list->tail->next && !equal(aux->next->data,data)); i++, aux = aux->next);

        //caso a lista for percorrida até voltar ao início, retorna-se falso   
        if(aux->next == list->tail->next)return false;
       
        //caso achou algum valor:
        remove = aux->next;

        //Se for o último, o Tail tem que apontar para o penúltimo
        if(aux->next == list->tail)list->tail = aux;
        aux->next = remove->next;
       
        remove->next = NULL;
        free(remove->data);
        free(remove);
        list->size--;  

        return true;
 }

  int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){

         if(isEmpty(listDest) ||  pos >= listDest->size) return -1;
         if(isEmpty(listSource) ||  pos >= listSource->size) return -2;
       
        // Node *aux = getNodeByPos(listDest,(pos-1));
        // if(aux==NULL)return -1;

        // listSource->tail->next = aux->next;
        // aux->next = listSource->tail->next->next;
        // listDest->size += listSource->size;
        // return listSource->size;

        if(pos == 0){

            printf("listSource->tail: %p\n",listSource->tail);
            printf("listSource->tail->next: %p\n",listSource->tail->next);
            printf("listDest->tail->next: %p\n",listDest->tail->next);
            printf("listDest->tail: %p\n",listDest->tail);
            printf("\n listDest->size: %d",listDest->size);
            printf("\n--------------\n");
          
            Node * aux;
            aux = listSource->tail->next;

            listSource->tail->next = listDest->tail->next;

            listDest->tail->next = aux;
        
           
        }

      
      
      
     listDest->size += listSource->size;
     return listSource->size;
      
  }