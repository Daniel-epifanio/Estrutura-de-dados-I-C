/*Problema: A Mochila Expansível do Aventureiro

Contexto: Em um jogo de plataforma, nosso herói começa sua jornada com uma pequena 
mochila para guardar os itens que encontra. Inicialmente, a mochila tem espaço para 
apenas 3 itens. No entanto, ao encontrar um item especial de "expansão de mochila", 
o espaço dela dobra, permitindo que ele carregue mais tesouros. Para que o jogo seja 
eficiente, não queremos criar uma mochila nova e copiar os itens um por um; queremos 
"esticar" a mochila existente.

Tarefa:
Escreva um programa em C que simule o herói coletando itens, expandindo sua mochila 
usando realloc(), e depois coletando mais itens.

Requisitos:
Mochila Inicial: Crie um ponteiro para inteiro chamado mochila. Use malloc() para 
alocar espaço para 3 itens (inteiros).
Primeira Coleta: Peça ao usuário para digitar os valores dos 3 primeiros itens 
encontrados e armazene-os na mochila.
Mostrar Itens: Imprima na tela os itens que estão atualmente na mochila.
Expandir a Mochila: Simule que o herói encontrou o item de expansão. Use realloc() 
para dobrar o tamanho da mochila, que agora deverá ter espaço para 6 itens.
Segunda Coleta: Peça ao usuário para digitar os valores dos 3 novos itens e armazene-os 
no novo espaço disponível na mochila. (Dica: os novos itens começarão na posição 3).
Mostrar Mochila Completa: Imprima na tela todos os 6 itens para provar que os itens 
antigos foram mantidos e os novos foram adicionados com sucesso.
Limpar Memória: Ao final do programa, não se esqueça de usar free() para liberar a 
memória alocada para a mochila.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

int *mochila = (int*) malloc(3 * sizeof(int));
int i;
if(mochila == NULL){
    printf("Erro no programa");
    return 1;
}
    printf("Digite os itens encontrados\n");
    for(i = 0; i < 3; i++){
        printf("item %d ", i + 1);
        scanf("%d ", &mochila[i]);
}
    for(i = 0; i < 3; i++){
        printf("%i ",mochila[i]);
    }
    printf("\n");

    mochila = realloc(mochila, 6 * sizeof(int));
    if(mochila == NULL){
        printf("Erro no programa");
        return 1;
    }
    for(i = 3; i < 6; i++){
        printf("Item %d ", i + 1);
        scanf("%d", &mochila[i]);
    }
    for(i = 0; i < 6; i++){
        printf("%d ", mochila[i]);
    }
    printf("\n");

    free(mochila);


    return 0;
}