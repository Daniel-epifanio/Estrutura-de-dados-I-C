/*Contexto: Você está desenvolvendo um jogo de plataforma 2D. No nível atual,
existem 3 salas secretas, e cada sala contém uma quantidade diferente de moedas
para o jogador coletar. Para otimizar o acesso aos dados de cada sala, o motor
do jogo utiliza um "gerenciador de salas" que consiste em um vetor de ponteiros.
Cada ponteiro nesse vetor aponta para um conjunto de moedas de uma sala específica.
Isso permite que o jogo acesse rapidamente as moedas da sala em que o jogador se encontra.

Tarefa:
Escreva um programa em C que simule a criação dos dados das salas secretas e use
um vetor de ponteiros para acessá-los e exibir os valores das moedas.

Requisitos:
Arrays de Moedas: Crie três vetores de inteiros para representar as moedas em cada sala secreta.
sala_1 deve conter os valores: {10, 20, 5}
sala_2 deve conter os valores: {50, 100}
sala_3 deve conter os valores: {5, 5, 5, 10}
Vetor de Ponteiros (Gerenciador de Salas): Crie um vetor de ponteiros para inteiros chamado ponteiro_salas com 3 posições.
Este vetor atuará como nosso gerenciador.
Conecte os Ponteiros: Faça com que cada posição do ponteiro_salas aponte para o início de um dos vetores de moedas.
ponteiro_salas[0] deve apontar para sala_1.
ponteiro_salas[1] deve apontar para sala_2.
ponteiro_salas[2] deve apontar para sala_3.
Acesse e Imprima as Moedas: Usando o vetor de ponteiros ponteiro_salas, acesse os dados e
imprima os valores das moedas de cada sala. A saída do seu programa deve ser exatamente assim:
Moedas na Sala 1: 10 20 5
Moedas na Sala 2: 50 100
Moedas na Sala 3: 5 5 5 10
(Dica: Para imprimir as moedas, crie um loop separado para cada sala. Dentro do loop da Sala 1,
você pode obter seu tamanho com sizeof(sala_1) / sizeof(sala_1[0]), e assim por diante para as
outras salas. Use o ponteiro_salas para acessar os valores. Caso queira fazer uma solução mais
avançada, tente implementar uma forma de imprimir todas as moedas usando um único loop for que itera de 0 a 2)*/
#include <stdio.h>

int main(){
    int sala_1[3] = {10, 20, 5};
    int sala_2[2] = {50, 100};
    int sala_3[4] = {5, 5, 5, 10};

    int *pont_salas[3] = {sala_1, sala_2, sala_3};
    int i;

    for(i = 0; i < sizeof(sala_1)/sizeof(sala_1[0]); i++){
        printf("%d", *(pont_salas[0] + i));
    }
    printf("\n");
    for(i = 0; i < sizeof(sala_2)/sizeof(sala_2[0]); i++){
        printf("%d", *(pont_salas[1] + i));
    }
    printf("\n");
    for(i = 0; i < sizeof(sala_3)/sizeof(sala_3[0]); i++){
        printf("%d", *(pont_salas[2] + i));
    }
    return 0;
}