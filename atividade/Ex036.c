/*Problema: Coletando Moedas no Nível

Contexto: Você é um desenvolvedor de jogos criando um novo jogo de plataforma. Em cada nível, o jogador pode coletar moedas que estão espalhadas pelo cenário. Cada moeda tem uma posição (coordenadas x e y) e um valor em pontos. Como o número de moedas pode variar de um nível para outro, você precisa de uma forma flexível de armazenar os dados de todas as moedas de um nível. A alocação dinâmica de memória é a solução perfeita para isso!

Tarefa:
Escreva um programa em C que primeiro pergunte ao usuário quantas moedas existem em um nível, 
depois colete os dados (posição x, y e valor) de cada uma delas e, finalmente, calcule e exiba 
o total de pontos que o jogador pode obter ao coletar todas as moedas.

Requisitos:
Estrutura da Moeda: Crie um struct chamado Moeda que contenha três membros: posicao_x (inteiro), 
posicao_y (inteiro) e valor (inteiro).
Pergunte a Quantidade: Pergunte ao usuário quantas moedas serão cadastradas e armazene esse número.
Alocação Dinâmica: Use a função malloc para alocar dinamicamente um vetor de estruturas Moeda com 
o tamanho exato informado pelo usuário. Crie um ponteiro para struct Moeda para receber o endereço 
da memória alocada.
Cadastro das Moedas: Utilize um laço de repetição (for) para pedir ao usuário que digite a posição 
x, a posição y e o valor de cada uma das moedas, armazenando esses dados no vetor alocado.
Cálculo dos Pontos: Utilize outro laço de repetição para percorrer o vetor de moedas e somar o valor 
de todas elas em uma variável total_pontos.
Exibição do Total: Ao final, imprima na tela o valor total de pontos do nível. Ex: "Pontuacao maxima 
do nivel: 150".
Liberar Memória: Não se esqueça de usar a função free() para liberar a memória que foi alocada 
dinamicamente antes de o programa terminar.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int pos_x;
    int pos_y;
    int valor;
}Moeda;


int main(){
    int quantidade_moedas;
    int i;

printf("Quantas moedas serão cadastradas?\n");
scanf("%d", &quantidade_moedas);

Moeda *moeda = (Moeda *) malloc(quantidade_moedas * sizeof(Moeda));

for(i = 0; i < quantidade_moedas; i++){
        printf("Digite a posicao X %d\n", i + 1);
        scanf("%d", &moeda[i].pos_x);

        printf("Digite a posicao Y %d\n", i + 1);
        scanf("%d", &moeda[i].pos_y);

        printf("Digite o valor da moeda %d\n", i + 1);
        scanf("%d", &moeda[i].valor);
}
    int total_pontos = 0;

    for (i = 0; i < quantidade_moedas; i++){
        total_pontos += moeda[i].valor;
    }
    printf("Pontuacao maxima do nivel: %d \n", total_pontos);

    free(moeda);
    return 0;
}