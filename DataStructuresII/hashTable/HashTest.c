#include<stdio.h>
#include"Hash.h"


int main (){
    
    HashStruct  Hash;

    initHash(&Hash);
    char * key = "arroz";
    int x = hash(key);
    printf("X Key:%d\n",x);

    return 0;
}