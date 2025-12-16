/*Problema: Estrutura de Dados Fila: Verificando se a Fila está Vazia

Contexto: No nosso sistema de matchmaking, as operações de adicionar e remover jogadores estão funcionando. No entanto, para otimizar o sistema e evitar operações desnecessárias, é útil ter uma forma rápida e eficiente de saber se há alguém na fila. Por exemplo, o sistema pode querer alocar recursos para monitorar a fila apenas quando ela não estiver vazia.

Tarefa: 
Adicione ao programa uma função dedicada a verificar se a fila de matchmaking está vazia e integre essa verificação ao menu principal.

Requisitos:
Implemente a função int estaVazia(Fila *f).
A função deve retornar 1 (representando 'verdadeiro') se a fila estiver vazia (ou seja, se o ponteiro inicio for NULL), e 0 (representando 'falso') caso contrário.
Atualize o menu no programa principal para incluir uma nova opção: "Verificar se a Fila esta Vazia".
Modifique a função main para que, ao escolher a nova opção, ela chame a função estaVazia e, com base no resultado, imprima uma mensagem clara para o usuário, como "SIM, a fila esta vazia." ou "NAO, a fila contem jogadores.".*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[100];
} Jogador;

struct no{
    Jogador dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;

void ler_jogador(Jogador *j){
    printf("Informe o ID e o nickname:\n");
    scanf("%d %99s", &j->id, j->nickname);
}

void inserir(Fila *pfila, Jogador dado){
    No * novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = NULL;
    if (pfila->inicio == NULL){
        pfila->inicio = novo;
        pfila->fim = novo;
    }
    else{
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
}

void mostrar(Fila *fila){
    if (fila->inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No * pi;
    for (pi = fila->inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nick: %s\n", pi->dado.id, pi->dado.nickname);
    }
}

int estaVazia(Fila *f){
    return (f->inicio == NULL) ? 1 : 0;
}

void remover(Fila *pfila){
    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
    }
    else if (pfila->inicio->prox == NULL){
        No *pi = pfila->inicio;
        pfila->inicio = NULL;
        pfila->fim = NULL;
        free(pi);
    }
    else{
        No * pi = pfila->inicio;
        pfila->inicio = pi->prox;
        free(pi);
    }
}

void menu(){
    printf("=== Fila de Jogadores === \n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar Fila\n");
    printf("3 - Remover\n");
    printf("4 - Verificar se a Fila esta Vazia\n");
    printf("5 - Sair \n");
    printf("=========================\n");
}


int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 5){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(&fila);
        }
        else if(op == 3){
            remover(&fila);
        }
        else if (op == 4){
            if (estaVazia(&fila)){
                printf("SIM, a fila esta vazia.\n");
            }
            else{
                printf("NAO, a fila contem jogadores.\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}