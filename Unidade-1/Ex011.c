/*Problema: Gerenciando o Inventário de Munição

Contexto: Em um jogo de plataforma, seu personagem possui um inventário com diferentes tipos
de munição. Para otimizar o desempenho, o jogo não manipula cópias dos dados, mas sim ponteiros
que apontam diretamente para a quantidade de cada munição. Você tem três tipos de munição, cada
um com uma quantidade atual e uma capacidade máxima:
1. Balas: 30 de 30
2. Granadas: 5 de 5
3. Foguetes: 2 de 2
Sua tarefa é criar um sistema que gerencie esse inventário usando um vetor de ponteiros e,
em seguida, simular o uso de uma unidade de cada tipo de munição usando aritmética de ponteiros.

Tarefa:
Escreva um programa em C que organize a munição do jogador em um inventário e atualize as quantidades após o uso.

Requisitos:
Vetores de Munição: Crie três vetores de inteiros de tamanho 2 para cada tipo de munição: balas,
granadas e foguetes. O primeiro elemento (índice 0) deve ser a quantidade atual e o segundo (índice 1)
a capacidade máxima. Inicialize-os com os valores do contexto.
Vetor de Ponteiros (Inventário): Crie um vetor de ponteiros para inteiros chamado inventario com 3 posições.
Conecte o Inventário: Faça com que cada posição do inventario aponte para o vetor de munição
correspondente (posição 0 para balas, 1 para granadas, 2 para foguetes).
Imprima o Estado Inicial: Mostre na tela a quantidade de cada munição antes do uso. A saída deve ser:
Inventario Inicial:
Balas: 30
Granadas: 5
Foguetes: 2
Simule o Uso com Aritmética de Ponteiros: Crie um laço de repetição (for) que percorra o inventario.
Dentro do laço, use aritmética de ponteiros e o operador de indireção (*) para decrementar em 1 a
quantidade atual (o primeiro elemento) de cada tipo de munição.
Imprima o Estado Final: Mostre na tela a quantidade de cada munição após o uso,
para confirmar que a alteração foi bem-sucedida. A saída deve ser:
Inventario Apos o Uso:
Balas: 29
Granadas: 4
Foguetes: 1*/
#include <stdio.h>

int main(){

    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};

    int *inventario[3] = {balas, granadas, foguetes};
    int i;
    printf("inventario antes do uso:\n");
    printf("%d\n", *(inventario[0] + 0));
    printf("%d\n", *(inventario[1] + 0));
    printf("%d\n", *(inventario[2] + 0));

      for(i = 0; i < 3; i++){
        (*(inventario[i] + 0))--;
      }
    printf("inventario depois do uso:\n");
    printf("%d\n", *(inventario[0] + 0));
    printf("%d\n", *(inventario[1] + 0));
    printf("%d\n", *(inventario[2] + 0));



    return 0;
}