/*Problema: Leaderboard de Pontuação em Jogo Arcade

Contexto: Você está desenvolvendo o sistema de leaderboard para um jogo de corrida arcade. Ao final de cada partida, o sistema recebe uma lista com o nome e a pontuação final de cada jogador. Para criar um ranking claro e competitivo, a tabela de pontuações precisa ser exibida em ordem decrescente, do jogador com a maior pontuação para o com a menor.

Tarefa:
Escreva um programa em C que primeiro leia um número inteiro N, representando a quantidade de jogadores. Em seguida, o programa deve ler o nome e a pontuação (um número inteiro) de cada um dos N jogadores. Utilizando o algoritmo de Ordenação por Inserção (Insertion Sort), seu programa deve ordenar a lista de jogadores em ordem decrescente de pontuação. Por fim, o programa deve imprimir o ranking final, mostrando a pontuação e o nome de cada jogador, já ordenados.

Requisitos:
Use uma struct para agrupar os dados de cada jogador (nome e pontuação).
Use um vetor de structs para armazenar a lista de todos os jogadores.
Implemente o algoritmo de Ordenação por Inserção (Insertion Sort) para ordenar o vetor.
A ordenação deve ser baseada na pontuação, em ordem decrescente.
Imprima a lista ordenada no formato "[pontuação] [nome]" para cada jogador, um por linha.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogadores;

void ler(Jogadores *jogador){
    scanf("%s %d", &jogador->nome, &jogador->pontuacao);
}

int main(){
    int n, i, j;
    printf("Digite a quantidade de jogadores que deseja cadastrar\n");
    scanf("%d", &n);
    Jogadores *jogador = malloc(n*sizeof(Jogadores));

    for ( i = 0; i < n; i++){
        ler(&jogador[i]);
    }

    for(i = 1; i < n; i++){
        Jogadores x = jogador[i];
        for (j = i - 1; j >= 0 && x.pontuacao < jogador[j].pontuacao; j--){
            jogador[j + 1] = jogador[j];
        }
        jogador[j + 1] = x;
    }

    printf("Imprimindo Jogadores\n");

    for ( i = 0; i < n; i++){
        printf("%s %d\n", jogador[i].nome, jogador[i].pontuacao);
    }

    free(jogador);

    return 0;
    
}