/*Problema: Estrutura de Dados Fila: Implementação da Operação de Inserção (Enqueue)

Contexto: Em um jogo de arena multiplayer online (MOBA) como 'League of Legends' ou 'Dota 2', quando os jogadores clicam para entrar em uma partida, eles são colocados em uma fila de matchmaking. O sistema do jogo precisa gerenciar essa fila de forma justa, garantindo que o primeiro jogador a entrar seja o primeiro a ser considerado para uma nova partida (princípio FIFO - First-In, First-Out). Você foi encarregado de construir a base desse sistema.

Tarefa:
Crie um programa em C que simule a entrada de jogadores em uma fila de matchmaking. O programa deve apresentar um menu com opções para adicionar um novo jogador à fila ou sair. Cada jogador possui um ID numérico e um nickname.

Requisitos:
Utilize uma struct para representar um jogador, contendo um int para o ID e um char[] para o nickname.
Implemente a fila usando uma lista encadeada. Crie uma struct para o nó (No), que armazena os dados do jogador e um ponteiro para o próximo nó.
Crie uma struct para a Fila (Fila), que deve conter dois ponteiros: inicio e fim.
Implemente a função void inserir(Fila *f, Jogador j) que aloca um novo nó, armazena os dados do jogador nele e o adiciona corretamente ao final da fila.
O programa principal (main) deve inicializar uma fila vazia e entrar em um loop que exibe o menu. Se o usuário escolher 'inserir', o programa deve ler os dados de um novo jogador e chamar a função inserir. O loop deve terminar quando o usuário escolher 'sair'.
A inserção deve funcionar corretamente tanto para uma fila vazia quanto para uma fila que já contém jogadores.
Comentários da turma
Seus trabalhos
Atribuído
Aula 108 - Adicionando um elemento a uma fila
Vídeo do YouTube • 2 dúvidas

Comentários particulares*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[100];
} Jogador;

struct no{
    Jogador dado;
    struct no *prox;
};

typedef struct no No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void ler_jogador(Jogador *j){
    printf("Informe o ID e o nickname:\n");
    scanf("%d %99s", &j->id, j->nickname);
}

void inserir(Fila *pfila, Jogador dado){
    No *novo = (No*) malloc(sizeof(No));
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

void menu(){
    printf("=== Fila de Jogadores ===\n");
    printf("1 - Inserir jogador\n");
    printf("2 - Sair\n");
    printf("========================\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}