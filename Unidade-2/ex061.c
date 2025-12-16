/*Problema: High Score Sorter

Contexto: Supondo um jogo de corrida arcade, ao final de cada partida, 
a tabela de pontuações precisa ser exibida no placar. Para criar um ranking 
claro e competitivo, os scores de todos os jogadores devem ser listados em 
ordem crescente, do menor para o maior.

Tarefa:
Escreva um programa em C que primeiro leia um número inteiro 'N', representando a 
quantidade de jogadores na partida. Em seguida, o programa deve ler 'N' pontuações 
inteiras. Por fim, o programa deve ordenar essas pontuações usando o algoritmo de 
Ordenação por Seleção (Selection Sort) e exibi-las em uma única linha, separadas 
por espaços.

Requisitos:
O programa deve primeiro ler um inteiro 'N'.
Em seguida, deve ler 'N' inteiros e armazená-los em um vetor.
O algoritmo de Ordenação por Seleção (Selection Sort) deve ser implementado para ordenar o vetor.
A saída final deve ser uma única linha contendo os 'N' inteiros ordenados, do menor para o maior, com cada número separado por um espaço.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de n\n");
    scanf("%d", &n);
    int *v = malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++){
        int menor = i;
        for(j = i + 1; j < n; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        int temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }

    printf("Lista Ordenada\n");
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    free(v);
}