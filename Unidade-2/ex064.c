/*Contexto: Suponhamos um jogo de RPG, ao derrotar um monstro poderoso, ele pode deixar cair um número variável de 'Fragmentos de Alma', cada um com um nível de poder diferente. Para realizar um poderoso 'Ritual de Encantamento', os fragmentos precisam ser organizados em ordem crescente de poder dentro da sua 'Bolsa de Runas'.

Tarefa:
Você deve criar um programa em C que simule a organização desses fragmentos. O programa primeiro perguntará quantos fragmentos foram coletados e, em seguida, lerá o nível de poder de cada um. Utilizando o algoritmo de Ordenação por Inserção (Insertion Sort), você deve ordenar esses fragmentos e, ao final, exibir a lista de poderes em ordem crescente, pronta para o ritual.

Requisitos:
O programa deve primeiro ler um número inteiro n, que representa a quantidade de fragmentos.
Em seguida, deve ler n números inteiros, correspondendo ao poder de cada fragmento, e armazená-los em um vetor.
Utilize o algoritmo de Ordenação por Inserção (Insertion Sort), exatamente como demonstrado na aula, para ordenar o vetor.
Ao final, imprima os elementos do vetor já ordenados, separados por um espaço.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *runas = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%i", &runas[i]);
    }

    for(i = 1; i < n; i++){
        int x = runas[i];
        for(j = i - 1; j >= 0 && x < runas[j]; j--){
            runas[j + 1] = runas[j];
        }
        runas[j + 1] = x;
    }

    for(i = 0; i < n; i++){
        printf("%i ", runas[i]);
    }

    free(runas);
    return 0;
}