#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    return (strcmp (chave, c->email) == 0)?true:false;
}

void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("\n{%s,%s}\n - ", cliente->nome, cliente->email);
}

int main() {
    HashStruct hashes;
    initHash(&hashes);
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    strcpy(cliente->nome,"Andre");
    strcpy(cliente->email,"andrevks@gmail.com");
    int x = put(&hashes,cliente->email,cliente,comparaChaves);
    printf("x:%d\n",x);
    
    Cliente *lucas = (Cliente*) malloc(sizeof(Cliente));
    strcpy(lucas->nome,"Lucas");
    strcpy(lucas->email,"lucas@gmail.com");

    x = put(&hashes,lucas->email,lucas,comparaChaves);
    printf("x:%d\n",x);

    Cliente *ze = (Cliente*) malloc(sizeof(Cliente));
    strcpy(ze->nome,"ze");
    strcpy(ze->email,"ze@gmail.com");

    x = put(&hashes,ze->email,ze,comparaChaves);
    printf("x:%d\n",x);

    showHashStruct(&hashes,printCliente);
    //Cliente * clientTest = (Cliente*) malloc(sizeof(Cliente));
    //clientTest = (Cliente*)get(&hashes,ze->email,comparaChaves);
    //printf("Nome:%s e Email:%s",clientTest->nome,clientTest->email);
    removeKey(&hashes,cliente->email,comparaChaves);
    printf("After\n");
    showHashStruct(&hashes,printCliente);

return 0;
}
