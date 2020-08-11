#include "Blockchain.h"
#include <string.h>
#include "sha-256.h"
#include <time.h>


//Procedimento p/ transformar hash de 32 bytes p/ string 64 caracteres
static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    //monta string com 64 caracteres hexadecimais
    for(i = 0; i < 32; i++){
        //02x hexadecimal em 2 caracteres
        string += sprintf(string, "%02x", hash[i]);
    }
}
void initBlockchain(Blockchain *blockchain){

}
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data){
    char input[1024];
    sprintf(input, "%i%s%lu%.8f", index, previousHash,timestamp, data);

    uint8_t hash[32];//vetor de 32 bytes de inteiros unsigned [0-255] (256/8 =32)
    //char hash_string[65];
    char * hash_string = (char*) malloc(sizeof(char)*65);
    //realiza a função hash
    calc_sha_256(hash,input,strlen(input));
    //transforma o hash em uma string de 64 caracteres
    hash_to_string(hash_string,hash);

    return hash_string;
}
Block* generateNextBlock(Blockchain *blockchain, float data){
    
}
Block* getLatestBlock(Blockchain *blockchain){

}
bool isValidNewBlock(Block* newBlock, Block* previousBlock){

}
bool isBlockchainValid(Blockchain *blockchain){

}
int addBlock(Blockchain *blockchain, Block *newBlock){

}