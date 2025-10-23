/*Problema: Movimentando o Personagem no Mapa

Contexto: Em um jogo de plataforma, a posição do personagem na tela é 
constantemente atualizada. Essa posição é geralmente armazenada como 
um par de coordenadas (X e Y). Para que o jogo funcione de forma fluida, 
as funções que calculam o movimento do personagem (como pular, correr, 
etc.) precisam ser muito rápidas. Uma forma de otimizar isso em C é 
criar uma função que recebe um ponteiro para a posição do personagem 
e a atualiza diretamente, em vez de criar cópias desnecessárias das 
coordenadas.

Tarefa:
Escreva um programa em C que defina a posição inicial de um personagem, 
chame uma função para movê-lo para uma nova posição e, em seguida, exiba 
suas coordenadas finais. A movimentação deve ser feita através de uma 
função que manipula um ponteiro.

Requisitos:
Estrutura de Posição: Crie uma struct chamada Posicao que contenha dois 
membros inteiros: x e y.
Variável do Jogador: Na função main, crie uma variável do 
tipo struct Posicao chamada posicao_jogador e inicialize 
suas coordenadas em x = 0 e y = 0.
Ponteiro para Posição: Ainda no main, crie um ponteiro 
chamado ponteiro_posicao que aponte para o endereço de 
memória da variável posicao_jogador.
Exiba a Posição Inicial: Mostre na tela a posição inicial do jogador. 
A saída deve ser: "Posicao inicial do jogador: X=0, Y=0"
Função de Movimento: Crie uma função chamada mover_personagem que 
não retorne nenhum valor (void) e receba dois argumentos:
Um ponteiro para uma struct Posicao.
Um inteiro movimento_x para a quantidade a ser movida no eixo X.
Um inteiro movimento_y para a quantidade a ser movida no eixo Y.
Lógica da Função: Dentro da função mover_personagem, use o ponteiro recebido 
para somar movimento_x à coordenada x e movimento_y à coordenada y da struct 
original.
Chame a Função: Na função main, chame mover_personagem passando o ponteiro 
ponteiro_posicao, e mova o personagem 10 unidades em X e 5 unidades em Y.
Exiba a Posição Final: Após a chamada da função, mostre na tela a nova posição 
do jogador. A saída deve ser: "Posicao final do jogador: X=10, Y=5"*/
#include <stdio.h>

typedef struct
{
int x;
int y;
}posicao;

void mover_personagem(posicao *p, int movimento_x, int movimento_y);

int main(){

posicao posicao_jogador;
posicao_jogador.x = 0;
posicao_jogador.y = 0;
posicao *ponteiro_posicao = &posicao_jogador;

printf("Posicao inicial do Jogador: X = %d, Y = %d\n", ponteiro_posicao->x, ponteiro_posicao->y);
mover_personagem(ponteiro_posicao, 10, 5);
printf("Posicao final do Jogador: X = %d , Y = %d\n",ponteiro_posicao->x, ponteiro_posicao->y);
    return 0;
}

void mover_personagem(posicao *p, int movimento_x, int movimento_y){
p->x += movimento_x;
p->y += movimento_y;

}