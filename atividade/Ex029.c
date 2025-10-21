/*Problema: Itens Colecionáveis em um Jogo de Plataforma

Contexto: Você está desenvolvendo um jogo de plataforma 2D. No seu jogo, existem diferentes tipos de moedas e itens que o jogador pode coletar. Cada item tem um valor em pontos e um "peso" que, futuramente, poderia ser usado para calcular a velocidade do personagem. Por enquanto, vamos nos concentrar em definir esses itens.

Tarefa:
Escreva um programa em C que defina uma estrutura para os itens colecionáveis e crie três tipos diferentes de itens, inicializando seus valores diretamente. Em seguida, simule o jogador coletando um desses itens e atualize sua pontuação.

Requisitos:
Estrutura do Item: Crie uma struct chamada ItemColetavel que contenha dois membros:
int valor_pontos (quantos pontos o item vale).
float peso (o peso do item).
Criação dos Itens: Dentro da função main, declare e inicialize três variáveis do tipo struct 
ItemColetavel usando a inicialização direta (como visto na aula):
moeda_bronze: Deve valer 10 pontos e ter peso 0.5.
moeda_prata: Deve valer 50 pontos e ter peso 0.7.
moeda_ouro: Deve valer 100 pontos e ter peso 1.0.
Pontuação do Jogador: Crie uma variável inteira chamada pontuacao_jogador e inicialize-a com 0.
Simular Coleta: Simule que o jogador coletou uma moeda_ouro. Para isso, some o valor_pontos 
da variável moeda_ouro à variável pontuacao_jogador.
Exibir Resultado: Mostre na tela a pontuação do jogador após a coleta. A saída deve ser 
exatamente: Moeda de ouro coletada! Pontuação atual: 100*/
#include <stdio.h>

struct ItemColetavel
{
int valor_pontos;
float peso;
};

int main(){

struct ItemColetavel moeda_bronze = {10, 0.5};
struct ItemColetavel moeda_prata = {50, 0.7};
struct ItemColetavel moeda_ouro = {100, 1.0};
int pontuacao_jogador = 0;

printf("O jogador achou uma moeda de ouro!\n");
pontuacao_jogador = moeda_ouro.valor_pontos + pontuacao_jogador;
printf("Moeda de ouro coletada! Pontuação atual: %d\n", pontuacao_jogador);

    return 0;
}