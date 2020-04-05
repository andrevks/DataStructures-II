# A Lista duplamente ligada terá as seguintes funções

typedef bool (*compare)(void*,void*);:white_check_mark:

typedef void (*printNode)(void*);

void init(DoublyLinkedList *list); :white_check_mark:

int enqueue(DoublyLinkedList *list, void *data); :white_check_mark:

void* dequeue(DoublyLinkedList *list); :white_check_mark:

void* first(DoublyLinkedList *list); :white_check_mark:

void* last(DoublyLinkedList *list); :white_check_mark:

int push(DoublyLinkedList *list, void *data); :white_check_mark:

void* pop(DoublyLinkedList *list); :white_check_mark:

void* top(DoublyLinkedList *list); :white_check_mark:

bool isEmpty(DoublyLinkedList *list); :white_check_mark:

int indexOf(DoublyLinkedList *list,void *data, compare equal);:white_check_mark:

Node* getNodeByPos(DoublyLinkedList *list,int pos);:white_check_mark:

void* getPos(DoublyLinkedList *list,int pos);:white_check_mark:

int add(DoublyLinkedList *list, int pos, void *data);:white_check_mark:

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);:white_check_mark:

void* removePos(DoublyLinkedList *list, int pos);:white_check_mark:

bool removeData(DoublyLinkedList *list, void *data, compare equal);:white_check_mark:

void show(DoublyLinkedList *list, printNode print);

void showMem(DoublyLinkedList *list);
