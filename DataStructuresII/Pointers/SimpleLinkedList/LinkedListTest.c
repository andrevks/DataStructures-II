#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(){
    LinkedList list;

    
  
    printf("Tail Address: %p\n",(list.tail));
    printf("Next Address: %p\n",(list.tail->next));
   

    

    init(&list);

    
    printf("Size: %d\n", (list.size));
    printf("Tail Address: %p\n",(list.tail));
   

    return 0;
}