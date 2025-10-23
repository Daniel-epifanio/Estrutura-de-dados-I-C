/*Problema: A Jornada do Saltador

Contexto: Em um jogo de plataforma, nosso herói precisa atravessar um abismo pulando sobre uma sequência de plataformas
mágicas. Cada plataforma fornece um impulso de salto diferente. Para otimizar o cálculo do trajeto, o motor do jogo usa aritmética de ponteiros para "caminhar" pela lista de plataformas e somar os impulsos.
Sua tarefa é simular essa lógica, calculando a altura total que o jogador alcança após saltar sobre todas as plataformas.

Tarefa:
Escreva um programa em C que calcule e exiba a altura total do salto do personagem usando
aritmética de ponteiros para percorrer um vetor de plataformas.

Requisitos:
Vetor de Plataformas: Crie um vetor de inteiros chamado plataformas e inicialize-o com
os seguintes valores de impulso: {10, 20, 5, 15, 30}.
Ponteiro para Plataforma: Crie uma variável do tipo "ponteiro para inteiro" chamada ponteiro_plataforma.
Variável de Altura: Crie uma variável inteira chamada altura_total e inicialize-a com 0.
Loop com Aritmética de Ponteiros: Crie um laço for que itere por todas as plataformas do vetor.
Dentro do laço, você deve usar aritmética de ponteiros para acessar o valor de impulso de cada
plataforma e somá-lo à variável altura_total. Dica: Em vez de usar plataformas[i], acesse o valor
usando a expressão *(plataformas + i).
Imprima o Resultado: Após o laço, mostre na tela a altura total alcançada.
A saída deve ser exatamente: Altura total do salto: 80 metros!*/
#include <stdio.h>

int main(){

    int plataformas[5] = {10, 20, 5, 15, 30};
    int *ponteiro_plataforma;
    ponteiro_plataforma = plataformas;
    int altura_total = 0;
    int i;

    for(i = 0; i < 5; i++){
      altura_total += *(ponteiro_plataforma + i);
    
    }
    printf("Altura total do salto: %d metros!", altura_total);
    return 0;
}