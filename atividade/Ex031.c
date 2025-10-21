/*Problema: Coletável de Pontuação no Jogo

Contexto: Em um jogo de plataforma, o cenário está repleto de itens coletáveis, como moedas ou gemas. Cada tipo de coletável pode ter características diferentes. Por exemplo, uma "gema azul" pode valer mais pontos que uma "moeda de bronze", e cada uma tem uma posição única (X, Y) no mapa do jogo. Para organizar esses dados de forma eficiente, usamos uma estrutura para representar cada item.

Tarefa:
Escreva um programa em C que defina um tipo para um item coletável e depois crie uma instância desse item com os dados fornecidos pelo usuário.

Requisitos:
Definição do Tipo: Usando typedef struct, crie um novo tipo chamado Coletavel.
Membros da Estrutura: A estrutura Coletavel deve conter os seguintes membros:
pontos (um int para o valor do item).
pos_x (um float para a coordenada X).
pos_y (um float para a coordenada Y).
Declaração da Variável: Na sua função main, declare uma variável do tipo Coletavel chamada gema_rara.
Entrada de Dados: Peça ao usuário que digite o valor em pontos, a posição X e a posição Y da gema_rara.
Armazenamento: Utilize a função scanf para ler os dados e armazená-los nos membros correspondentes da variável gema_rara.
Saída de Dados: Ao final, exiba uma mensagem formatada com os dados do item criado. A saída deve ser: 
"Coletável criado! Valor: [pontos] pontos. Posição: (X=[x], Y=[y])".*/
#include <stdio.h>

typedef struct
{
int pontos;
float pos_x;
float pos_y;
}coletavel;

int main(){

coletavel gema_rara;
printf("Digite o valor em pontos, a posição X e a posição Y da gema_rara\n");
scanf("%d %f %f", &gema_rara.pontos, &gema_rara.pos_x, &gema_rara.pos_y);
printf("Coletável criado! Valor: %d pontos. Posição: (X = [%.1f], Y = [%.1f]\n", gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);

    return 0;
}
