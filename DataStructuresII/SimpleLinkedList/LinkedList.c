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
    Quando deseja-se acessar o início, digita-se list->tail->next*/

    //Uma nova área da memória, suficiente para armazenar um nó
    //é  reservada usando malloc
    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return 0;


    if(isEmpty(list)){
        
          new_node->data = data;
          //Tail aponta para o último
          list->tail = new_node;

          //O Tail->next aponta para o último, pois nesse momento
          //há apenas um elemento
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
        //e o tail->next apontará para 
        //o next do new_node
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
        conta--;
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


//função retirar 
void * pop(LinkedList *list){

    if(!isEmpty(list)){

         Node * aux;
         //aux aponta para o ínicio da lista
        aux = list->tail->next;

        //percorre até o próximo ser o último da lista
        while (aux->next != list->tail) 
            aux = aux->next;

          aux->next = list->tail->next; 
          void * data = list->tail->data;

          free(list->tail);

          list->tail = aux;

          list->size--;


          return data;
    }

    return NULL;
}

//consulta o último item da pilha
void* top(LinkedList *list){
    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))? NULL: list->tail->data;
}

//consulta o primeiro item da lista
void* first(LinkedList *list){

    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))? NULL: list->tail->next->data;
}
//Consulta o último item da lista
void* last(LinkedList *list){
    //Como o objetivo é retornar o último
    //a função Top é reaproveitada
    return top(list);
}

 int add(LinkedList *list, int pos, void *data){

        //Se for o primeiro, é enviado imediatamente
        if(pos <= 0) return push(list,data);

        //senão, é criado um aux que receberá um nó anterior 
        //à posição desejada

        Node * aux = getNodeByPos(list,(pos-1));
        //se houver algum erro retorna 0
        if(aux == NULL)return 0; 
        
        //cria-se um novo nó e aloca um espaço livre 
        Node * new_node = (Node*) malloc(sizeof(Node));

        //o novo nó recebe o endereço do dado
        new_node->data = data;
        
        //o next aponta para o next do aux
        new_node->next = aux->next;
        //Aux next aponta para o novo nó
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

        for(int count = 0; (aux != list->tail && pos != count); count++, aux = aux->next);
    
        return aux;
        

 }

//retorna o index do dado informado
 int indexOf(LinkedList *list, void *data, compare equal){
     
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
 bool removeData(LinkedList *list, void *data, compare equal){

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

  int addAll(LinkedList *listDest, int pos, LinkedList *listSource){

         if(isEmpty(listDest) ||  pos >= listDest->size) return -1;
         if(isEmpty(listSource) ||  pos >= listSource->size) return -2;

        if(pos == 0){
            
            Node * inicioSource = listSource->tail->next;

            listSource->tail->next = listDest->tail->next;
            listDest->tail->next = inicioSource;
            listDest->tail = listSource->tail;

        }else{

            Node * aux = getNodeByPos(listDest,(pos-1));
            Node * inicioSource = listSource->tail->next;
            listSource->tail->next = aux->next;
            aux->next = inicioSource;
        }
        

      
      
     listDest->size += listSource->size;
     return listSource->size;
      
  }


 void* getPos(LinkedList *list, int pos){

      Node * dataPos = getNodeByPos(list,pos);
      return (dataPos == NULL)? NULL:dataPos->data;
  }


void* removePos(LinkedList *list, int pos){
    
    if(isEmpty(list) || pos >= list->size) return NULL;

    Node * aux = getNodeByPos(list,(pos-1));
    if(aux == NULL) return NULL;

    Node * removeData = aux->next;
    aux->next = removeData->next;
    void *data = removeData->data;
    
    free(removeData);

    list->size--;
    return data;
}