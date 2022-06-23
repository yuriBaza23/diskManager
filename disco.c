#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DIR "./arquivos"

/**************************************
* DADOS
**************************************/
typedef struct nosetor{
    unsigned long inicio;
    unsigned long fim;
    struct nosetor* prox;
    struct nosetor* ant;
} NoSetor;

typedef struct noarquivo{
    char nome[40];
    long int tam;
    NoSetor* setores;
    struct noarquivo* prox;
    struct noarquivo* ant;
} NoArquivo;

typedef struct disco{
    char nome[40];
    void* disco;
    NoSetor* livres;
    NoArquivo* arquivos;
    long int tamDisco;
    long int espacoLivre;
    long int qtdeArquivos;    
} Disco;

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Disco* disco_cria(char* nome, long int tamanho) {
    Disco* disk = (Disco*)malloc(sizeof(Disco));
    strcpy(disk->nome, nome);
    disk->disco = malloc(tamanho * sizeof(void));

    // Create empty sentinel
    NoSetor* empty_sentinel = (NoSetor*)malloc(sizeof(NoSetor));
    NoSetor* first = (NoSetor*)malloc(sizeof(NoSetor));
    empty_sentinel->prox = first;
    empty_sentinel->ant = first;
    first->prox = empty_sentinel;
    first->ant = empty_sentinel;
    first->inicio = 0;
    first->fim = tamanho - 1;

    // Create file sentinel
    NoArquivo* file_sentinel = (NoArquivo*)malloc(sizeof(NoArquivo));
    file_sentinel->setores = NULL;
    file_sentinel->ant = file_sentinel;
    file_sentinel->prox = file_sentinel;

    disk->livres = empty_sentinel;
    disk->arquivos = file_sentinel;
    disk->tamDisco = tamanho;
    disk->espacoLivre = tamanho;
    disk->qtdeArquivos = 0;

    return disk;
}

bool disco_grava(Disco* d, char* arquivo); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_remove(Disco* d, char* nome); // somente o nome do arquivo sem o caminho
bool disco_recupera(Disco* d, char* nome, char* arquivoDestino); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
void disco_lista(Disco* d);