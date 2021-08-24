#include <stdio.h>
#include <stdlib.h>
//Struct definindo os dados recebidos
typedef struct No{
    char letra;
    int indice;
} No; No NULLitem = {' ', -1};

//M é o tamanho da tabela hash, N é o número de elementos dentro da tabela hash
static int M, N;
static No *hashTable;
//Como N não é primo, esotu usando o número sugerido pelo prof
#define getHashKey(index)((618033*(unsigned)index)%M)
//Definindo uma macro para referência do valor do índice de cada letra
#define index(x)(x.indice)
//Definindo macro para achar itens nulos
#define isNull(A)(index(hashTable[A]) == index(NULLitem))

void InitHashTable(int max){
    N = 0;
    M = max;
    hashTable = malloc(M*sizeof(No));
    for(int i = 0; i < M; i++){
        hashTable[i] = NULLitem;
    }
}

int HashTableSize(){
    return N;
}

void HashTableInsert(No caracter){
    int v = index(caracter);
    int i = getHashKey(v);
    while(!isNull(i)){
        i = (i+1)%M;
    }
    hashTable[i] = caracter;
    N++;
}

int main(){
    InitHashTable(1048577);
    No item;
    int teste = 0;
    scanf("%d %c", &item.indice, &item.letra);
    HashTableInsert(item);
    scanf("%d", &teste);
    teste = getHashKey(teste);
    printf("%d %c\n", hashTable[teste].indice, hashTable[teste].letra);
    return 0;
}