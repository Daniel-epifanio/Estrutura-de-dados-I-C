/*Problema: O Estado do Personagem em um Jogo de Plataforma

Contexto: Em jogos de plataforma, o personagem principal possui vários atributos que mudam 
constantemente. Por exemplo, sua posição no cenário, sua pontuação e se ele possui algum poder 
especial. Em C, uma struct é a ferramenta perfeita para agrupar todos esses dados em uma única 
variável que representa o nosso herói.

Tarefa:
Escreva um programa em C que defina o estado de um personagem de jogo. O programa deve simular 
o personagem começando o nível, coletando uma moeda e, em seguida, pegando um item de "power-up" 
que lhe concede um pulo duplo.

Requisitos:
Definição da Estrutura: Crie uma struct chamada Jogador que contenha os seguintes membros:
float pos_x; (para a posição horizontal)
int pontuacao;
int tem_pulo_duplo; (use 0 para não e 1 para sim)
Criação do Personagem: No main, crie uma variável do tipo struct Jogador chamada heroi.
Estado Inicial: Inicialize os membros da variável heroi com os seguintes valores, simulando o início da fase:
pos_x deve ser 50.0.
pontuacao deve ser 0.
tem_pulo_duplo deve ser 0.
Imprimir Estado Inicial: Mostre na tela o estado inicial do jogador. A saída deve ser:
Inicio da fase! Posicao X: 50.0, Pontos: 0, Pulo Duplo: Nao
Simular Ações:
- Coletar Moeda: Altere o membro pontuacao do heroi, adicionando 10 pontos.
- Coletar Power-up: Altere o membro tem_pulo_duplo do heroi para 1.
Imprimir Estado Final: Mostre na tela o novo estado do jogador após as ações. A saída deve ser:
Itens coletados! Posicao X: 50.0, Pontos: 10, Pulo Duplo: Sim*/
#include <stdio.h>

struct jogador
{
float pos_x;
int pontuacao;
int tem_pulo_duplo;
};


int main(){

struct jogador heroi;

heroi.pos_x = 50.0;
heroi.pontuacao = 0;
heroi.tem_pulo_duplo = 0;

printf("Inicio da fase! Posicao X: %.1f, Pontos: %d, Pulo Duplo: %d\n", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo);

printf("O Heroi coletou uma moeda!\n");
heroi.pontuacao = 10 + heroi.pontuacao;
printf("O Heroi coletou pulo duplo!\n");
heroi.tem_pulo_duplo = 1 + heroi.tem_pulo_duplo;

printf("Itens coletados! Posicao X: %.1f, Pontos: %d, Pulo Duplo: %d\n", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo);

    return 0;
}