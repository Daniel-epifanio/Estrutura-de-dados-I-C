/*Problema: O Inventário de Itens

Contexto: Em um jogo de plataforma, o personagem pode coletar diferentes itens ao longo de uma fase. Cada item tem um nome e um valor em pontos. No final da fase, o jogo precisa verificar todos os itens coletados e identificar qual deles foi o mais valioso (ou seja, o que deu mais pontos) para talvez conceder um bônus especial ao jogador.
Para gerenciar isso, o jogo usa um vetor de estruturas, onde cada posição do vetor representa um item coletado.

Tarefa:
Escreva um programa em C que simule a coleta de 3 itens pelo jogador. O programa deve pedir ao usuário o nome e o valor de cada item e, ao final, informar qual item foi o mais valioso.

Requisitos:
Estrutura do Item: Crie uma struct chamada ItemColetavel que contenha:
Um vetor de char chamado nome com capacidade para 50 caracteres.
Um inteiro chamado valor_pontos.
Vetor de Itens: No main, declare um vetor de ItemColetavel chamado inventario com tamanho 3.
Entrada de Dados: Crie um laço de repetição (for) para preencher o vetor inventario. 
Para cada um dos 3 itens, o programa deve solicitar ao usuário que digite o nome e o 
valor em pontos.
Encontrar o Mais Valioso: Após preencher o vetor, crie a lógica para encontrar o item com o maior valor_pontos.
- Crie uma variável do tipo struct ItemColetavel para armazenar o item mais valioso encontrado até o momento.
- Inicialize-a com o primeiro item do inventário.
- Percorra o restante do vetor e, se encontrar um item com mais pontos, atualize sua variável.
Saída de Dados: Imprima na tela uma mensagem mostrando o nome do item mais valioso. 
A saída deve ser: "O item mais valioso coletado foi: [nome_do_item]"*/
#include <stdio.h>

typedef struct
{
    char nome[50];
    int valor_pontos;
}itemcoletavel;

int main(){

itemcoletavel inventario[3];
int i;

for(i = 0; i < 3; i++){
    printf("Digite o Nome e o valor em pontos\n");
    scanf("%s %d", inventario[i].nome, &inventario[i].valor_pontos);
}
itemcoletavel maior_pontos = inventario[0];

for(i = 0; i < 3; i++){
     if (inventario[i].valor_pontos > maior_pontos.valor_pontos) {
            maior_pontos = inventario[i];
    }
}
    printf("O item mais valioso coletado foi: %s\n", maior_pontos.nome);
    return 0;
}
