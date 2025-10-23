/*Problema: Power-up de Pontuação Dupla

Contexto: Em um jogo de plataforma, seu personagem pode coletar um item especial de "power-up"
que dobra a pontuação atual. Para otimizar o jogo, a função que calcula essa pontuação não deve
criar cópias desnecessárias de variáveis. Em vez disso, ela deve receber a localização exata da
pontuação na memória e alterá-la diretamente, garantindo que a mudança seja refletida em todo o jogo.

Tarefa: 
Escreva um programa em C que simule o jogador coletando um item de "power-up" que dobra sua pontuação.

Requisitos:
1. Função Principal (main):
Crie uma variável inteira chamada pontuacao_jogador e inicialize-a com o valor 1500.
Imprima a pontuação do jogador antes de coletar o power-up. A saída deve ser: "Pontuacao antes do power-up: 1500".
Chame a função que aplica o power-up (você a criará no próximo passo).
Imprima a pontuação do jogador após a coleta do power-up para confirmar que o valor foi dobrado.
A saída deve ser: "Pontuacao apos o power-up: 3000".
2. Função do Power-up (aplicar_powerup_pontuacao_dupla):
Crie uma função sem retorno (void) com o nome aplicar_powerup_pontuacao_dupla.
Esta função deve receber um único parâmetro: um ponteiro para um inteiro.
Este ponteiro representará o endereço da variável pontuacao_jogador.
Dentro da função, use o ponteiro para acessar o valor original da pontuação e
multiplique-o por 2, atualizando o valor diretamente na memória.*/
#include <stdio.h>

void apl_power_pt_dp(int *pi);

int main(){

int pontuacao_jogador = 1500; 
int *pi = &pontuacao_jogador;

printf("Pontuacao antes do power-up: %d\n", pontuacao_jogador);

apl_power_pt_dp(pi);

 printf("Pontuacao depois do power-up: %d\n", *pi);
    return 0;
}

void apl_power_pt_dp(int *pi){

    *pi = 2 * *pi;
}