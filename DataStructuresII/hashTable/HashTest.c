#include<stdio.h>
#include"Hash.h"
#include<stdlib.h>

bool comparar(void * data1,void *data2){
    int *d1 = (int*)data1;
    int * d2 = (int*)data2;
    return (*d1 == *d2)? true: false;
}

int main (){
    
    HashStruct  Hash;

    initHash(&Hash);
    char * key = "arroz";
    int x = hash(key);
    printf("X Key:%d\n",x);
    //printf("containsKey:%d",containsKey(&Hash,key,comparar));
    int * data = (int*) malloc(sizeof(int));
    *data = 666;

    printf("PUT:%d\n",put(&Hash,key,data,comparar));

    int * data1 = (int*) malloc(sizeof(int));
    *data1 = 666;
    
    printf("PUT:%d\n",put(&Hash,key,data1,comparar));
    return 0;
}