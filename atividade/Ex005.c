/*Problema: Coletando Moedas com Ponteiros

Contexto: Em um jogo de plataforma, o seu personagem precisa coletar moedas para aumentar a pontuação.
Cada moeda coletada vale 10 pontos. No motor do jogo, para garantir que a pontuação seja atualizada
de forma rápida e eficiente, a função responsável por adicionar os pontos de uma moeda não recebe
uma cópia da pontuação, mas sim um "atalho" direto para o local na memória onde a pontuação do jogador
está armazenada. Esse "atalho" em C é um ponteiro.

Tarefa:
Escreva um programa em C que simule um jogador começando com 0 pontos e coletando 3 moedas.
A atualização da pontuação deve ser feita utilizando um ponteiro.

Requisitos:
Variável de Pontuação: Crie uma variável inteira chamada pontuacao e inicialize-a com o valor 0.
Ponteiro de Pontuação: Crie uma variável do tipo "ponteiro para inteiro" chamada ponteiro_pontuacao.
Conecte o Ponteiro: Faça com que ponteiro_pontuacao aponte para o endereço de memória da variável pontuacao.
Imprima a Pontuação Inicial: Mostre na tela a pontuação do jogador antes de coletar qualquer moeda.
A saída deve ser: "Pontuacao inicial: 0"
Simule a Coleta: Usando o ponteiro_pontuacao, adicione 10 pontos à pontuação do jogador.
Repita este processo 3 vezes para simular a coleta de 3 moedas. (Dica: você pode fazer
isso em 3 linhas separadas ou usar um laço for).
Imprima a Pontuação Final: Após simular a coleta das 3 moedas, mostre na tela a pontuação final.
A saída deve ser: "Pontuacao final apos coletar 3 moedas: 30"*/
#include <stdio.h>

int main(){
int pontuacao = 0;
int *pponto = &pontuacao;
    printf("Pontuacao inicial: %d", *pponto);
    for(int i = 0; i < 3; i++){
        *pponto = 10 + *pponto;
}
    printf("Pontuacao final apos coletar 3 moedas: %d", *pponto);

    return 0;
}