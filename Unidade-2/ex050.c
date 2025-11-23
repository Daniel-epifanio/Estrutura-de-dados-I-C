/*Problema: Cálculo de Dano Final do Personagem

Contexto: Em um RPG, o dano que um personagem causa não depende apenas de sua força base. 
Ele é influenciado pelo poder da arma que ele equipa e por buffs mágicos temporários. 
Você precisa criar um sistema que calcule o dano final de um personagem com base nesses três valores fixos.

Tarefa: 
Escreva um programa em C que leia três valores de ponto flutuante: a força base do personagem, 
o bônus de dano da arma e o bônus de um feitiço de 'buff'. O programa deve então calcular e 
imprimir o dano total, que é a soma desses três valores.

Requisitos:
O programa deve ler três números de ponto flutuante.
O programa deve somar os três números.
O programa deve imprimir o resultado da soma com duas casas decimais.
O algoritmo deve ter complexidade de tempo constante, assim como o exemplo da aula.*/
#include<stdio.h>

int main(){
    float forca_personagem;
    float dano_arma;
    float buff_atributos;
    printf("Digite a forca do personagem, o dano da arma e o buff de atributos\n");
    scanf("%f %f %f", &forca_personagem, &dano_arma, &buff_atributos);
    float soma = forca_personagem + dano_arma + buff_atributos;
    printf("Dano totalÇ: %.2f", soma);
}