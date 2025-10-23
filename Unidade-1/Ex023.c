/*Problema: Construindo o Chão de uma Fase

Contexto: Em jogos de plataforma, o cenário (ou "level") é frequentemente representado
como uma grade bidimensional (uma matriz). Cada célula da grade pode conter um valor que
representa o que há naquele local: ar (0), uma plataforma (1), uma moeda (2), etc. Para
otimizar o desempenho e o uso de memória, muitos motores de jogo alocam o mapa inteiro
como um único e contínuo bloco de memória, em vez de múltiplas partes separadas.

Tarefa:
Sua missão é criar a base de um nível para um jogo. Você vai escrever um programa em C
que aloca dinamicamente a memória para um mapa de jogo e, em seguida, constrói o "chão"
da fase na última linha da matriz.

Requisitos:
Constantes do Nível: Use #define para criar duas constantes: LINHAS com valor 5 e COLUNAS com valor 10.
Alocação Dinâmica: Crie um ponteiro para inteiro chamado level_map. Use a função malloc para alocar
um único bloco de memória contínuo que possa armazenar toda a matriz LINHAS x COLUNAS.
Verificação de Alocação: Verifique se malloc retornou um ponteiro válido. Se for nulo, exiba uma 
mensagem de erro e encerre o programa.
Construção do Chão: Usando laços de repetição (for), percorra a matriz. Para cada célula:
Se a célula estiver na última linha (i == LINHAS - 1), atribua o valor 1 (chão).
Para todas as outras linhas, atribua o valor 0 (ar).
Importante: Para acessar e modificar a célula na linha i e coluna j, você deve usar aritmética 
de ponteiros. A fórmula é *(level_map + i * COLUNAS + j).
Exibição do Nível: Após preencher a matriz, imprima o nível na tela para que ele se pareça com 
uma grade.
Liberação de Memória: Ao final do programa, use a função free() para liberar a memória que foi 
alocada para level_map.*/
#include <stdio.h>
#include <stdlib.h>
#define linhas 5
#define colunas 10
int main(){
int i, j;
int *level_map = (int *) malloc(linhas * colunas * sizeof(int));
if(level_map == NULL){
    printf("erro no programa");
    return 1;
}
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(i == linhas -1){
                *(level_map + i * colunas + j) = 1;
            }
                else{
                    *(level_map + i * colunas + j) = 0;
                }
        }
        
    }
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%d ", *(level_map + i * colunas + j));
            
        }
        printf("\n");
    }
    free(level_map);

}