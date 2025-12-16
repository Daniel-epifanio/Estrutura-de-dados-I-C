/*Contexto: Supondo um jogo de arena de batalha multiplayer, o placar final de cada partida 
é um dos momentos mais importantes para os jogadores. O sistema precisa processar rapidamente 
a pontuação de todos os participantes e exibir um ranking ordenado, do jogador com a maior 
pontuação para o com a menor. Usar um algoritmo de ordenação eficiente como o Quick Sort é 
crucial para garantir que o placar apareça instantaneamente, mesmo em partidas com muitos jogadores.

Tarefa:
Você deve criar um programa em C que leia os dados de vários jogadores (ID e pontuação) e os 
ordene em ordem decrescente de pontuação usando o algoritmo Quick Sort. A estrutura de dados 
de cada jogador já está definida para você.

Requisitos:
Defina uma struct chamada Jogador que contenha um id (inteiro) e uma pontuacao (inteiro).
Use typedef para criar um alias Jogador para struct Jogador.
Implemente o algoritmo Quick Sort de forma recursiva.
Sua implementação do Quick Sort deve ordenar o vetor de jogadores com base no campo pontuacao em ordem decrescente (do maior para o menor).
O programa primeiro deve ler um número inteiro n, que representa a quantidade de jogadores na partida.
Em seguida, o programa deve ler os dados (ID e pontuação) dos n jogadores.
Após a ordenação, o programa deve imprimir a lista de jogadores ordenada, mostrando o ID e a pontuação de cada um, um por linha.*/
#include <stdio.h>

typedef struct {
    int pontuacao;
    char nome[50];
} Jogadores;

int particiona(int e, int d, Jogadores v[]){
    Jogadores pivo = v[d];
    int j = e - 1;
    int i;

    for (i = e; i < d; i++){
        if (v[i].pontuacao <= pivo.pontuacao){
            j++;
            Jogadores temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }

    }

    Jogadores temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;
    return j + 1;
}

void quicksort(int i, int f, Jogadores v[]){
    if (i < f){
        int p = particiona(i, f, v);
        quicksort(i, p - 1, v);
        quicksort(p + 1, f, v);
    }
    
}

void ler(Jogadores *pe){
    scanf("%d %s", &pe->pontuacao, pe->nome);
}

int main(){
    int n, i;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    Jogadores v[n];
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    quicksort(0, n-1, v);

    for (i = 0; i < n; i++){
        printf("%s: %d\n", v[i].nome, v[i].pontuacao);
    }
    return 0;
}