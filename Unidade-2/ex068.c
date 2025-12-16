/*Contexto: Suponha um jogo de arena de batalha, ao final de cada partida, o sistema precisa exibir o placar final, 
mostrando os jogadores ordenados da maior para a menor pontuação. Isso cria um ranking claro e incentiva a competição. 
Você foi encarregado de implementar a lógica de ordenação do placar.

Tarefa:
Escreva um programa em C que primeiro leia um número inteiro N, representando a quantidade de 
jogadores na partida. Em seguida, o programa deve ler os dados de N jogadores, onde cada jogador 
possui um ID (inteiro) e uma pontuação (inteiro). Finalmente, o programa deve imprimir a lista de 
jogadores ordenada em ordem decrescente de pontuação, exibindo o ID e a pontuação de cada um.

Requisitos:
Use uma struct para representar os dados de um jogador (ID e pontuação).
Utilize a palavra-chave typedef para criar um alias para a sua estrutura.
Implemente o algoritmo de ordenação Bubble Sort para organizar o vetor de jogadores.
A ordenação deve ser em ordem decrescente (do maior para o menor) com base na pontuação.
O programa deve ler a quantidade de jogadores e, em seguida, os dados de cada jogador (ID e pontuação) a partir da entrada padrão.
A saída deve ser a lista de jogadores ordenada, com cada jogador em uma nova linha, no formato: ID Pontuacao.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontuacao;
} Jogadores;

void ler(Jogadores *jogador){
    scanf("%d %d", &jogador->id, &jogador->pontuacao);
}

void bolha(int n, Jogadores v[]){
    int i, j;

    for(i = 0; i < n; i++){
        int trocou = 0;
        for(j = 0; j < n - 1; j++){
            if(v[j].id < v[i + 1].id){
                Jogadores temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if(trocou == 0){
            return;
        }
    }
}

int main(){
    int n, i;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    Jogadores *jogador = malloc(n*sizeof(Jogadores));

    for(i = 0; i < n; i++){
        ler(&jogador[i]);
    }

    bolha(n, jogador);

    for(i = 0; i < n; i++){
        printf("%d %d\n", jogador[i].id, jogador[i].pontuacao);
    }

    free(jogador);

    return 0;

}