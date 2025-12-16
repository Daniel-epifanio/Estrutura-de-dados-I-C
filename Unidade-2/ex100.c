/*Problema: Pilha de Ações em Tempo Real

Contexto: Em jogos de estratégia em tempo real (RTS) ou RPGs, as ações do jogador ou de uma unidade são frequentemente processadas em uma ordem específica. Por exemplo, se um jogador emite múltiplos comandos de movimento e ataque, o último comando emitido geralmente tem prioridade e é executado primeiro. Este comportamento é perfeitamente modelado por uma pilha, onde a última ordem dada é a primeira a ser retirada da "fila" de comandos para execução.

Tarefa: 
Você está desenvolvendo o sistema de comando para uma unidade mágica, o 'Arcanista'. O Arcanista pode receber uma sequência de ordens para lançar feitiços. Sua tarefa é criar um programa que simule a pilha de comandos do Arcanista. O programa deve permitir que o jogador insira múltiplos comandos de feitiço na pilha. Ao final, o programa deve simplesmente encerrar, preparando o terreno para uma futura aula onde veremos como 'executar' (remover) esses comandos da pilha.

Requisitos:
Crie uma struct chamada Feitico que armazene o nome do feitiço (string, ex: "BolaDeFogo") e seu custo_mana (inteiro).
Implemente uma Pilha (Stack) usando uma lista encadeada para armazenar os feitiços.
O programa deve apresentar um menu com as seguintes opções:
1: Adicionar um novo feitiço à pilha de comandos.
2: Finalizar a sequência de comandos e sair.
Ao escolher a opção 1, o programa deve solicitar o nome e o custo de mana do feitiço e adicioná-lo ao topo da pilha.
O programa deve continuar executando até que o usuário escolha a opção 2.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int custo_mana;
} Feitico;

struct no{
    Feitico dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
} Pilha;

void menu(){
    printf("==== Comandos de Feiticos ====\n");
    printf("1 - Adicionar feitiço\n");
    printf("2 - Finalizar e sair\n");
    printf("===============================\n");
}

void empilhar(Pilha *ppilha, Feitico dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            Feitico f;
            printf("Informe o nome do feitiço:\n");
            scanf("%99s", f.nome);
            printf("Informe o custo de mana:\n");
            scanf("%d", &f.custo_mana);
            empilhar(&pilha, f);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}