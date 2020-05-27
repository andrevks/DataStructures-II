#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>



void initHash(HashStruct *hashStruct){
    DoublyLinkedList * aux;
    aux = hashStruct->hashes;
    for(int i = 0; i<MAX;i++){
        init(aux);
        aux++;
    }
    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct){
    return (hashStruct->size == 0);     
}

int hash(char *key){
    int charSum = 0;
    for(int i = 0;*key != '\0';i++){
        charSum += (*key) * (i+1);
        key++;
    }
    return charSum % MAX;
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
    containsKey = indexOf(matchedList,key,equal); 
    return (containsKey>0)?true:false;    
}

void showHashStruct(HashStruct *hashStruct,printNode print){
   
   DoublyLinkedList * aux;
    for(int i = 0; i<MAX;i++){
        if(hashStruct->hashes[i].size > 0){
            //printf("&hashStruct->hashes[i]:%s e %f",hashStruct->hashes[i].tail->next->next->data);
            //aux = hashStruct->hashes[i].tail->next->next->data
            
            show(&hashStruct->hashes[i],print);
        }
    }
        
}
