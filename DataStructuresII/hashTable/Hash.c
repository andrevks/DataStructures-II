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
    for(; *key != '\0';count+= *key,key++);

    return count % MAX;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    
    if(!containsKey(hashStruct,key,equal)){

        int hashValue = hash(key);
        DoublyLinkedList * matchedList;
        matchedList = &hashStruct->hashes[hashValue];
        int sucess = enqueue(matchedList,data);
        if(sucess == 1) hashStruct->size++;
        return sucess;
    }
        
        return -3;
    
    
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    
    DoublyLinkedList * matchedList;
    int hashValue ,containsKey;

    hashValue = hash(key);
    matchedList = &hashStruct->hashes[hashValue];

    //printf("matchedList    -   hashStruct->hashes[hashValue]\n"); 
    //printf("%p   -       %p\n",matchedList,&hashStruct->hashes[hashValue]);

    containsKey = indexOf(matchedList,key,equal); 
    return (containsKey>0)?true:false;    
}

void showHashStruct(HashStruct *hashStruct,printNode print){
    
    for(int i = 0; i<MAX;i++){
        if(hashStruct->hashes[i].size > 0){
            show(&hashStruct->hashes[i],print);
        }
    }
        
}
