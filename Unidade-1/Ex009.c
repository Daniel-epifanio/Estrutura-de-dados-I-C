/*Problema: O Rastro de Moedas do Jogador

Contexto: Em um jogo de plataforma, nosso herói corre por um nível e coleta moedas.
Cada moeda tem um valor diferente. Para otimizar o código do jogo, em vez de usar
um índice para percorrer a lista de moedas coletadas, o motor do jogo usará um ponteiro.
Isso permite acessar diretamente a próxima moeda na memória, o que pode ser mais eficiente.
Sua tarefa é criar um programa que simule o cálculo da pontuação total de um nível
usando aritmética de ponteiros para percorrer um vetor de moedas coletadas.

Tarefa:
Escreva um programa em C que some os valores de todas as moedas coletadas em um vetor,
mas a iteração deve ser feita exclusivamente incrementando um ponteiro, sem usar um contador de índice como v[i].

Requisitos:
Vetor de Moedas: Crie um vetor de inteiros chamado moedas_coletadas e inicialize-o com
os seguintes valores, que representam o valor de cada moeda: {10, 50, 20, 5, 100}.
Variável de Pontuação: Crie uma variável inteira pontuacao_total e inicialize-a com 0.
Ponteiro para Moedas: Crie um ponteiro para inteiro chamado ponteiro_moeda.
Apontar para o Início: Faça com que ponteiro_moeda aponte para o endereço do primeiro elemento do vetor moedas_coletadas.
Loop com Ponteiro: Crie um laço for ou while que percorra todos os 5 elementos do vetor.
A condição de parada do laço deve comparar o endereço do ponteiro atual com o endereço final do vetor. A cada iteração, você deve:
- Usar o operador de indireção (*) para obter o valor da moeda atual e somá-lo à pontuacao_total.
- Incrementar o ponteiro_moeda (ponteiro_moeda++) para que ele aponte para a próxima moeda.
Imprimir o Resultado: Após o laço terminar, imprima a pontuação final. A saída deve ser exatamente: Pontuação total do nível: 185*/
#include <stdio.h>

int main(){

int moedas_coletadas[5] = {10, 50, 20, 5, 100};
int pontuacao_total = 0;
int *pont_moeda;

    for(int *pont_moeda = moedas_coletadas; pont_moeda < moedas_coletadas + 5; pont_moeda++ ){
            printf("%d \n", *(pont_moeda));
           pontuacao_total += *pont_moeda;
    }
     printf("Pontuacao total do nivel: %d\n", pontuacao_total);


return 0;
}