/*Problema: O Nome e o Título do Herói

Contexto: Em um jogo de plataforma RPG, o jogador pode escolher um nome para seu personagem.
Após derrotar o primeiro chefe, o personagem ganha um título especial, como "OValente" ou
"OConquistador". O sistema do jogo precisa combinar o nome original do jogador com um espaço
e o título recém-adquirido para exibi-lo na tela.

Tarefa:
Escreva um programa em C que simule a criação do nome completo de um herói.
 O programa deve primeiro ler o nome do personagem, depois o título que ele ganhou,
e então unir os dois para formar uma única string no formato "Nome Título".

Requisitos:
Variáveis de Texto: Crie duas variáveis do tipo char[] (vetor de char) chamadas nome_jogador e titulo_conquistado.
Ambas devem ter tamanho suficiente para armazenar nomes e títulos (ex: 50 caracteres).
Entrada do Nome: Peça ao usuário para digitar o nome do herói e armazene-o na variável nome_jogador.
Entrada do Título: Peça ao usuário para digitar o título conquistado e armazene-o na variável titulo_conquistado.
Adicionar Espaçamento: Antes de unir o título, você precisa adicionar um espaço após o nome do jogador.
Use a função strcat para concatenar a string " " (um espaço) ao final da variável nome_jogador.
Unir o Título: Após adicionar o espaço, use a função strcat novamente para concatenar o conteúdo
de titulo_conquistado ao final de nome_jogador.
Exibir Resultado: Mostre na tela o nome completo e final do herói. A saída deve ser algo como:
"O herói agora é conhecido como: [Nome] [Título]"*/
#include <stdio.h>
#include <string.h>

int main(){

char nome_jogador[50], titulo_conquistado[50];

printf("Digite o nome do heroi\n");
scanf("%s", nome_jogador);
printf("Digite o titulo conquistado\n");
scanf("%s", titulo_conquistado);
strcat(nome_jogador, " " );
strcat(nome_jogador, titulo_conquistado);
printf("O heroi agora e conhecido como: %s\n", nome_jogador);



    return 0;
}