/*Contexto: Você está desenvolvendo o sistema de leaderboard para um jogo de corrida arcade. O placar sempre exibe os 5 melhores tempos em ordem crescente (do mais rápido para o mais lento). Quando um jogador termina uma corrida com um novo tempo, esse tempo precisa ser inserido na posição correta, mantendo a ordem do placar. Se o novo tempo for bom o suficiente para entrar no top 5, o tempo mais lento (que estava em 5º lugar) é descartado.

Tarefa:
Escreva um programa em C que represente um placar de 5 melhores tempos já ordenado. O programa deve ler um novo tempo de corrida e inseri-lo na posição correta do placar, mantendo a ordem crescente. O placar atualizado com os 5 melhores tempos (incluindo o novo, se aplicável) deve ser impresso no final.

Requisitos:
Declare e inicialize um vetor de inteiros com 5 tempos já ordenados de forma crescente (ex: 120, 125, 130, 142, 150).
Leia um único inteiro, novo_tempo, que representa o tempo do jogador.
Implemente a lógica para inserir novo_tempo no vetor. Esta lógica deve funcionar de trás para frente, comparando novo_tempo com os tempos existentes e deslocando os tempos maiores para a direita para abrir espaço.
Se novo_tempo for mais lento que todos os tempos no placar, o placar não deve ser alterado.
Imprima o vetor de 5 posições atualizado, mostrando o novo placar ordenado.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, novo_tempo;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *tempo = malloc(n*sizeof(int)+1);

    for(i = 0; i < n; i++){
        scanf("%i", &tempo[i]);
    }

    scanf("%d", &novo_tempo);

    for(i = n - 1; i >= 0 && novo_tempo < tempo[i]; i--){
        tempo[i + 1] = tempo[i];
    }
    tempo[i+1] = novo_tempo;

    for ( i = 0; i < n+1; i++){
        printf("%i ", tempo[i]);
    }

    free(tempo);

    return 0;
    
}