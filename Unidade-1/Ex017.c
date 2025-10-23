/*Contexto: Em jogos de plataforma, os níveis ou mapas são frequentemente construídos
como uma grade bidimensional, que em programação pode ser representada por uma matriz.
Cada célula da matriz pode conter um número que identifica o que existe naquela posição:
0 para um espaço vazio, 1 para uma plataforma sólida, 2 para um espinho perigoso, e assim
por diante. Antes de o jogador começar a fase, o jogo precisa carregar o mapa e saber onde estão os elementos.

Tarefa:
Escreva um programa em C que crie uma pequena representação de um mapa de jogo usando uma matriz.
Após preencher o mapa com valores, o programa deve pesquisar e informar as coordenadas de todos
os espinhos (valor 2) encontrados no mapa.

Requisitos:
Definir o Mapa: Crie uma matriz de inteiros 5x8 (5 linhas e 8 colunas) chamada mapa_fase1.
Inicializar o Mapa: Preencha a matriz com os seguintes valores, que representam o design da fase:
{
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 2, 0, 1, 1},
    {0, 0, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 1, 2, 2, 1, 1}
}
Encontrar os Espinhos: Percorra toda a matriz mapa_fase1 usando laços for aninhados.
Imprimir Coordenadas: Para cada célula da matriz que contiver o valor 2 (representando
um espinho), imprima uma mensagem na tela indicando sua localização (linha e coluna).
A saída deve seguir o formato: "Espinho encontrado na linha X, coluna Y".*/
#include <stdio.h>
#include <string.h>

int main(){

int mapa_fase1[5][8] = {{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0},{1, 1, 0, 0, 2, 0, 1, 1},{0, 0, 1, 1, 0, 1, 0, 0},{1, 1, 1, 1, 2, 2, 1, 1}};
int i, j;
    
    for(i = 0; i < 5; i++){
        for(j = 0; j < 8; j++){
            if(mapa_fase1[i][j] == 2){
                printf("Espinho encontrado na linha %d, coluna %d\n", i, j);
            }
        } 
    }

    return 0;
}