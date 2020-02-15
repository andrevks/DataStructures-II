#include<stdio.h>


int main(){
    int number = 10;
    int * numberP = &number;
    int **numberPP = &numberP;

    printf("Valor de Number:%d\n",number);
    printf("Endereço de Number:%p \n",&number);
    printf("Endereço apontado por NumberP:%p \n",numberP);
    printf("Endereço de NumberP:%p\n",&numberP);
    printf("Endereço apontado por NumberPP: %p \n",numberPP);
    printf("Endereço de NumberPP:%p\n",&numberPP);
    printf("Valor de **NumberPP:%d\n",**numberPP);

    return 0;
}