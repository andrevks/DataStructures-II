#include<stdio.h>
#include"Hash.h"
#include<stdlib.h>
#include<string.h>

typedef struct userBanco
{
    char * nome;
    int * money;
}userBanco;

bool comparar(void * data1,void *data2){
    int *d1 = (int*)data1;
    int * d2 = (int*)data2;
    return (*d1 == *d2)? true: false;
}

int main (){
    
    HashStruct  Hash;
    initHash(&Hash);

    userBanco jessica;
    char jessica1[] = "jessica";
    char * ptr = (char*) malloc(sizeof(char)*30);
    ptr = "lolasdfsadfads"; 
    printf("jessica->name:%s\n",ptr);
    
    //printf("PUT:%d\n",put(&Hash,jessica->nome,jessica,comparar);

    
    return 0;
}