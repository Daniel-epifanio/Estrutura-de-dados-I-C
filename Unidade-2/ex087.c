/*Contexto: Em jogos multiplayer online, quando um jogador decide entrar em uma partida, ele é colocado em uma fila de matchmaking. O sistema então forma as partidas pegando os jogadores que estão há mais tempo na fila, ou seja, os primeiros que entraram. Este comportamento é classicamente conhecido como 'primeiro a entrar, primeiro a sair' (FIFO - First-In, First-Out).

Uma lista encadeada é uma estrutura de dados perfeita para implementar essa fila, onde adicionar um novo jogador ao final da fila corresponde a uma inserção no fim, e remover um jogador para colocá-lo em uma partida corresponde a deletar o nó do início da lista.

Tarefa: 
Você foi encarregado de desenvolver o núcleo do sistema de fila de matchmaking. Seu programa deve gerenciar uma lista de jogadores esperando para entrar em uma partida. A principal funcionalidade a ser implementada nesta tarefa é a remoção do primeiro jogador da fila para iniciar um novo jogo.

Requisitos:
Crie uma struct Jogador que armazene um id (inteiro) e um nome (string).
Use as structs No e Lista para implementar a lista encadeada.
Implemente um menu com as seguintes opções:
1: Adicionar jogador ao fim da fila (inserir no fim).
2: Iniciar partida (deletar o primeiro jogador da fila).
3: Mostrar fila de espera.
4: Sair.
A função para 'Iniciar partida' deve remover o primeiro Jogador da lista. Se a fila estiver vazia, o programa deve informar que 'Não há jogadores na fila'.
O programa deve rodar em um loop, permitindo que o usuário realize múltiplas operações até escolher a opção de sair.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
}Jogador;

struct No{
    Jogador dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== FILA DE ESPERA ===\n");
    printf("1 - Adicionar jogador ao fim da fila\n");
    printf("2 - Iniciar partida\n");
    printf("3 - Mostrar fila de espera\n");
    printf("4 - Sair\n");
    printf("======================\n");;
}

void ler(Jogador *pj){
    scanf(" %d %s", &pj->id, pj->nome);
}

void inserir_inicio(Lista *plista, Jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void deletar_inicio(Lista *plista){
    if (plista->inicio == NULL){
        printf("\nNao ha jogadores na fila\n");
    }
    else{
        struct No * pi = plista->inicio;
        printf("\n=== PARTIDA INICIADA ===\n");
        printf("Jogador: %s (ID: %d) entrou em jogo!\n", pi->dado.nome, pi->dado.id);
        printf("========================\n");
        plista->inicio = pi->prox;
        free(pi);
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== FILA DE ESPERA ATUAL ===\n");
    if (lista.inicio == NULL){
        printf("Nenhum jogador aguardando.\n");
    }
    else{
        int posicao = 1;
        for (pi = lista.inicio; pi != NULL; pi = pi->prox){
            printf("Posicao %d - ID: %d | Nome: %s\n", posicao, pi->dado.id, pi->dado.nome);
            posicao++;
        }
    }
    printf("=============================\n");
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Jogador j;
            printf("\n--- Adicionar jogador ao fim da fila ---\n");
            ler(&j);
            inserir_fim(&lista, j);
            printf("\nJogador adicionado a fila com sucesso!\n");
        }
        else if (op == 2){
            deletar_inicio(&lista);
        }
        else if (op == 3){
            mostrar(lista);
        }
    } while (op != 4);
    
    printf("Programa Encerrado!");

    return 0;
}