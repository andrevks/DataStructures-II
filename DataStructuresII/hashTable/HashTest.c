#include<stdio.h>
#include"Hash.h"
#include<stdlib.h>
#include<string.h>

typedef struct userBanco
{
    char * nome;
    float * saldo;

}userBanco;

bool compararChaves(void * data,void *key){

    char * chave = (char*) key;
    userBanco * cliente = (userBanco*) data;

    return (strcmp(chave,cliente->nome) == 0)?true:false;
    //return (*chave == cliente->nome)? true: false;
}

void imprimirUser(void * user){
    userBanco * user1 = (userBanco*) user;
    printf("Nome:%s e Saldo:%f", user1->nome,user1->saldo);    
}

int main (){
    
   HashStruct Hash;
   initHash(&Hash);

   userBanco jessica;
   userBanco joao;
   userBanco andre;

   jessica.nome =(char*) malloc(30 * sizeof(char));
   strcpy(jessica.nome,"jessica");
   jessica.saldo =(float *) malloc(sizeof(float));
   *jessica.saldo = 7956,95;
   
   joao.nome =(char*) malloc(30 * sizeof(char));
   strcpy(joao.nome,"jessica");
   joao.saldo =(float *) malloc(sizeof(float));
   *joao.saldo = 8567,55;

   andre.nome =(char*) malloc(30 * sizeof(char));
   strcpy(andre.nome,"andre");
   andre.saldo =(float *) malloc(sizeof(float));
   *andre.saldo = 15967,55;


   printf("jessica.nome:%s e jessica.saldo: R$ %.2f\n",jessica.nome,*jessica.saldo); 
   printf("joao.nome:%s e joao.saldo: R$ %.2f\n",joao.nome,*joao.saldo); 
   printf("andre.nome:%s e andre.saldo: R$ %.2f\n",andre.nome,*andre.saldo); 
   
   
    
    printf("PUT:%d\n",put(&Hash,jessica.nome,&jessica,compararChaves));
    printf("PUT:%d\n",put(&Hash,joao.nome,&joao,compararChaves));
    printf("PUT:%d\n",put(&Hash,andre.nome,&andre,compararChaves));

    showHashStruct(&Hash,imprimirUser);

    
    return 0;
}