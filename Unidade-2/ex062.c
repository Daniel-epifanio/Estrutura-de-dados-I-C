/*Contexto: Em um jogo de arena de batalha, ao final de cada partida, os resultados dos jogadores precisam ser exibidos em uma tabela de classificação (leaderboard). Esta tabela deve mostrar os jogadores ordenados do maior para o menor número de eliminações ('kills'). Você foi encarregado de criar o sistema que processa os dados brutos da partida e os organiza para exibição.

Tarefa:
Escreva um programa em C que leia os dados de 'N' jogadores (nome e número de eliminações) e os ordene em ordem decrescente com base no número de eliminações, utilizando o algoritmo de Ordenação por Seleção (Selection Sort). Por fim, o programa deve imprimir o leaderboard ordenado.

Requisitos:
Defina uma struct chamada Jogador que contenha um campo para o nome (uma string de até 50 caracteres) e um campo para o número de eliminações (um inteiro).
Utilize typedef para criar um alias Jogador para a sua estrutura.
O programa deve primeiro ler um número inteiro N, que representa a quantidade de jogadores na partida.
Aloque dinamicamente um vetor de Jogador com tamanho N.
Leia o nome e o número de eliminações de cada um dos N jogadores.
Implemente o algoritmo de Ordenação por Seleção (Selection Sort) para ordenar o vetor de jogadores em ordem decrescente de eliminações.
Imprima o nome e as eliminações de cada jogador do vetor já ordenado, um por linha.
Lembre-se de liberar a memória alocada dinamicamente ao final do programa.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int eliminacoes;
} Jogador;

void ler(Jogador *jogador){
    scanf("%49s %d", jogador->nome, &jogador->eliminacoes);
}

void ordenarleaderboard(Jogador *jogadores, int n){
    for(int i = 0; i < n; i++){
        int imaior = i;
        for(int j = i + 1; j < n; j++){
            if(jogadores[j].eliminacoes > jogadores[imaior].eliminacoes){
                imaior = j;
            }
        }
        Jogador temp = jogadores[i];
        jogadores[i] = jogadores[imaior];
        jogadores[imaior] = temp;
    }
}

int main(){
    int n;
    printf("Digite a quantidade de jogadores\n");
    scanf("%d", &n);

    Jogador *jogadores = malloc(n * sizeof(Jogador));

    for(int i = 0; i < n; i++){
        ler(&jogadores[i]);
    }

    ordenarleaderboard(jogadores, n);

    for(int i = 0; i < n; i++){
        printf("%s %d\n", jogadores[i].nome, jogadores[i].eliminacoes);
    }

    free(jogadores);
    return 0;
}