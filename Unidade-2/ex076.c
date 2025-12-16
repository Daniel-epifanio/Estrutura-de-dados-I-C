/*Contexto: Supondo um "online multiplayer arena game", o sistema de ranking precisa processar 
e ordenar as pontuações dos jogadores ao final de cada partida para exibir o placar final. As 
pontuações podem chegar em qualquer ordem, e às vezes, chegam quase ordenadas (por exemplo, se 
os jogadores com melhor desempenho terminam a partida primeiro). Para garantir que o algoritmo 
de ordenação seja eficiente e não caia em casos de pior desempenho (complexidade O(n²)) com dados 
quase ordenados, você decide implementar o Quick Sort com um pivô aleatório.

Tarefa:
Crie um programa em C que leia o número de jogadores, em seguida a pontuação de cada um, e os 
ordene em ordem crescente usando o algoritmo Quick Sort com a estratégia de seleção de pivô aleatório.

Requisitos:
O programa deve primeiro ler um número inteiro N, representando o número de jogadores.
Em seguida, deve ler N pontuações inteiras e armazená-las em um vetor.
Implemente o algoritmo Quick Sort.
A função de partição deve selecionar um pivô de forma aleatória dentro dos limites do subvetor atual.
Utilize as bibliotecas <stdlib.h> e <time.h> para a geração dos números aleatórios.
Ao final, o programa deve imprimir as pontuações ordenadas em uma única linha, separadas por espaços.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
    int idx = e + (rand() % (d - e + 1)); 
    int temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;

    int pivo = v[d];
    int j = e - 1;

    for (int i = e; i < d; i++) {
        if (v[i] < pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }

    }

    temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;

    return j + 1;
}

void quicksort(int e, int d, int v[]) {
    if (e < d) {
        int p = particao(e, d, v);
        quicksort(e, p - 1, v);
        quicksort(p + 1, d, v);
    }


}

int main() {
    srand(time(NULL));  

    int n, i;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);

    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    quicksort(0, n - 1, v);

    printf("Imprimindo o vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}