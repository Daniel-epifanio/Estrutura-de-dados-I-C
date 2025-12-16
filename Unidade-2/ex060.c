/*Problema: Identificar o Alvo Mais Fraco

Contexto: Em um jogo de RPG tático, sua equipe de heróis se depara com uma horda de monstros. Para otimizar a estratégia de ataque, a IA (Inteligência Artificial) da sua equipe precisa identificar rapidamente o alvo mais fraco, ou seja, o monstro com a menor quantidade de Pontos de Vida (HP), para eliminá-lo primeiro.

Tarefa:
Escreva um programa em C que primeiro leia um número inteiro N, representando a quantidade de monstros na horda. Em seguida, o programa deve ler os dados de N monstros, onde cada monstro possui um nome (uma única palavra) e uma quantidade de HP (um número inteiro). Ao final, o programa deve apresentar o nome e o HP do monstro com a menor quantidade de Pontos de Vida.

Requisitos:
Utilize uma struct para representar os dados de um monstro (nome e HP).
Utilize typedef para criar um alias para o tipo da struct.
Armazene os dados dos monstros em um vetor de structs.
Implemente um algoritmo que percorra o vetor para encontrar o monstro com o menor valor de HP.
A saída deve seguir o formato: "Alvo prioritario: [Nome] ([HP] HP)", seguido por uma quebra de linha.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int hp;
} Monstro;

void ler(Monstro *monstros){
    scanf("%s %d", &monstros->nome, &monstros->hp);
}

int main(){
    int n;
    printf("Digite a quantidade de monstros a serem catalogados:\n");
    scanf("%d", &n);
    Monstro *monstros = malloc(n*sizeof(Monstro));
    printf("Digite os dados dos monstros\n");
    for (int i = 0; i < n; i++){
        ler(&monstros[i]);
    }
    Monstro menor = monstros[0];
    for(int i = 1; i < n; i++){
        if (monstros[i].hp < menor.hp){
            menor = monstros[i];
        }
    }
    printf("Alvo prioritario: %s (HP: %i)\n", menor.nome, menor.hp);
    free(monstros);

    return 0;
}