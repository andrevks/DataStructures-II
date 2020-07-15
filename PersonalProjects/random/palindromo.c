#include <stdio.h>
#include <string.h>

void palindromo( char palavra[],int tam, int i);

int main(){

    char palavra[100];
    int i,tam;

    printf("Digite uma palavra para saber se é palíndromo:");
    scanf(" %s", palavra);

    tam = strlen(palavra) - 1;
    i = 0;

    palindromo(palavra,tam,i);
    return 0;
}


void palindromo(char palavra[], int tam,int i){

    if(i == tam || i > tam){
        printf("\n É um Palíndromo\n");
    }else
    {
        if( palavra[i] == palavra[tam]){
            palindromo(palavra, tam-1, i+1);
        }
        else
        {
            printf("\nNão é um palíndromo\n");
        }
    }
}