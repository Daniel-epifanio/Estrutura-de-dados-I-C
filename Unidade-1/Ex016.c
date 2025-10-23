/*Problema: Inventário do Herói e a Porta Trancada

Contexto: Em um jogo de plataforma, nosso herói precisa coletar itens para progredir.
Em uma fase, ele se depara com uma grande porta de pedra que só pode ser aberta com
um item específico. O herói carrega uma mochila com um número limitado de espaços para
itens. Precisamos criar um sistema simples para verificar se ele possui o item necessário em seu inventário.

Tarefa:
Escreva um programa em C que simule o inventário de um jogador.
O programa deve primeiro ler os itens que o jogador está carregando
e, em seguida, verificar se ele possui um item específico para abrir a porta.

Requisitos:
Declarar o Inventário: Crie um vetor de strings chamado inventario capaz de armazenar 5 nomes de itens.
Cada nome de item pode ter no máximo 19 caracteres (deixando espaço para o caractere nulo \0).
Preencher o Inventário: Peça ao usuário para digitar os 5 itens que estão no inventário e armazene-os no vetor.
Item Necessário: Peça ao usuário para digitar o nome do item necessário para abrir a porta.
Armazene este nome em uma variável separada.
Verificar o Inventário: Percorra o vetor inventario e compare cada item com o item necessário.
Exibir o Resultado:
Se o item necessário for encontrado no inventário, imprima na tela: Porta aberta!
Se o item não for encontrado após verificar todos os espaços do inventário, imprima: Você não tem o item necessário.*/
#include <stdio.h>
#include <string.h>

int main(){

char inventario[5][19];
char item_necessario[19];
int i;
int item_encontrado = 0;

printf("Digite os itens\n");
scanf(" %s %s %s %s %s", inventario[0], inventario[1], inventario[2], inventario[3], inventario[4]);
printf("Pegue o item necessario\n");
scanf("%s", item_necessario);

for(i = 0; i < 5; i++){
    if(strcmp(inventario[i], item_necessario) == 0){
     item_encontrado = 1;
            break;
        }
    }

    if(item_encontrado) {
        printf("Porta aberta!\n");
    } else {
        printf("Voce nao tem o item necessario.\n");
    }

    return 0;
}