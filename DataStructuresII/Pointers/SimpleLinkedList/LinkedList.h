    #ifndef DataStructure_LinkedList_h
    #define DataStructure_LinkedList_h

    enum boolean {
        true = 1, false = 0
    };

    typedef enum boolean bool;
    
    /* */
    typedef struct Node {
        void *data;
        struct Node *next;
    }Node;

    /*Tail aponta para o final da lista
    e para informar o tamanho foi criado a variável size 
    */
   
    typedef struct LinkedList {
        //Node *first;
        Node *tail;
        int size;
    }LinkedList;

    /*Por questões de legidibilidade, algumas funções são reutilizadas*/
    //no LinkedListTest.c:
    //Qualquer função que alguem implementar
    //que retorne boleano e os tipos
    //das funções sejam iguais 
    

    //Aqui:
    //Criando um ponteiro de função 
    //que recebe como parâmetros dois ponteiros void
    //retornando bool

    //OBS:
    //Quando utilizar esse tipo "compare",
    //suponha-se que o usuário criou 
    //essa função com o objetivo de comparar
    //dois dados, a vantagem é que a biblioteca
    //serve para qualquer tipo de dado
    typedef bool (*compare)(void*,void*);

    //Inicializa a lista
    //Caso fosse 
    void init(LinkedList *list);
    int enqueue(LinkedList *list, void *data);
    void* dequeue(LinkedList *list);
    void* first(LinkedList *list);
    void* last(LinkedList *list);
    int push(LinkedList *list, void *data);
    void* pop(LinkedList *list);
    void* top(LinkedList *list);
    bool isEmpty(LinkedList *list);

    
    //IndexOf:
    //Curiosidade: O Registrador Contador de instrução, guarda o endereço da próxima instrução
    //Esse endereço de memória pode ter o endereço de um dado
    //ou de uma função.

    
    //Para resolver esse problema é criado um ponteiro
    //de função para devolver a posição baseado no dado 

    //Devolve a posição baseado no dado
    //Aqui trabalha somente com o endereço dos dados
    //quem usar a biblioteca, informa o tipo de dado.
    int indexOf(LinkedList *list, void *data, compare equal);//OK

    //Quer saber endereço do dado guardado
    //da posição escolhida
    void* getPos(LinkedList *list, int pos);
    
    //função utilitária internamente na lista
    //retorna o endereço do Node
    //pela posição informada 
    Node* getNodeByPos(LinkedList *list, int pos);//OK

    //inserir na posição dada pelo usuário.
    //Deve-se percorrer até a pos-1 para conseguir 
    //adicionar o novo nó
    int add(LinkedList *list, int pos, void *data);//OK

    //Adiciona a lista de origem na lista destino 
    //ou seja o tail da lista origem vai no início da lista destino
    //Depois início do destino aponta para o final da lista origem 
    //importante incrementar o size na lista de destino 
    int addAll(LinkedList *listDest, int pos, LinkedList *listSource);

    //remove o elemento baseado na posição
    void* removePos(LinkedList *list, int pos);
    
    //remove o elemento baseado no dado
    bool removeData(LinkedList *list, void *data, compare equal);//OK

    
   
   
    #endif