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
    e para informar o tamanho na variável size 
    */
   
    typedef struct LinkedList {
        //Node *first;
        Node *tail;
        int size;
    }LinkedList;

    /*Por questões de legidibilidade, algumas funções são reutilizadas*/

    //Qualquer função que alguem implementar
    //que retorne boleano e os tipos
    //das funções sejam iguais 

    //Criando um ponteiro de função 
    //que recebe como parâmetros dois ponteiros void
    //retornando bool

    //Quando utilizar esse tipo compare,
    //suponhe-se que o usuário criou 
    //essa função com o objetivo de comparar
    //dois dados, a vantagem
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

    //Devolver a posição baseado no dado
    //Aqui trabalha somente com o endereço dos dados
    //quem usar a biblioteca, informa o tipo de dado
    //Para resolver esse problema é criado um ponteiro
    //de função

    //Registrador Contador de instrução, guarda o endereço da próxima instrução
    //Aquele endereço de memória pode ter o endereço de um dado
    //ou de uma função
    int indexOf(LinkedList *list, void *data, compare equal);

    //Quer saber endereço do dado guardado
    //da posição escolhida
    void* getPos(LinkedList *list, int pos);
    
    //função utilitária internamente na lista
    //retorna o endereço do Node
    //pela posição informada 
    Node* getNodeByPos(LinkedList *list, int pos);

    //inserir na posição dada pelo usuário
    //deve-se percorrer até a pos-1 para conseguir 
    //adicionar o novo nó
    int add(LinkedList *list, int pos, void *data);

    //adiciona alista de origem na lista destino 
    //ou seja o tail da lista origem vai no início da lista destino
    //Depois início do destino aponta para o final da lista origem 
    //importante incrementar o size na lista de destino 
    int addAll(LinkedList *listDest, int pos, LinkedList *listSource);

    //remove o elemento baseado na posição
    void* removePos(LinkedList *list, int pos);
    bool removeData(LinkedList *list, void *data, compare equal);

    
   
   
    #endif