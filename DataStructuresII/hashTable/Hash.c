#include "Hash.h"
#include<stdio.h>
#include<stdlib.h>



void initHash(HashStruct *hashStruct){

    DoublyLinkedList * aux;
    aux = hashStruct->hashes;
    //printf("hashStruct in BYTES:%ld\n",sizeof(hashStruct));
    
    //printf("Aux in BYTES:%ld\n",sizeof(aux));
    for(int i = 0; i<MAX;i++){

        init(aux);
        //printf("Hashes:%p\n",aux);
        aux++;
        
    }

    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct){
    return (hashStruct->size == 0);     
}

int hash(char *key){
    int count = 0;

    for(; *key != '\0';key++){
        printf(" %d:\n",*key);
        count+= *key;
    }    

    return count % MAX;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){

    hashStruct->hashes[2];

}