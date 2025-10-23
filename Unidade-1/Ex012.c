/*Problema: Validação do Nome do Personagem

Contexto: Você está desenvolvendo um novo jogo de plataforma. Na tela de criação de personagem,
o jogador precisa escolher um nome. Para garantir que o nome não quebre o layout da interface do
jogo, foi decidido que o nome do personagem não pode ter mais de 15 caracteres. Nomes com espaços
são permitidos, como "Sir Lancelot".

Tarefa:
Escreva um programa em C que peça ao jogador para digitar o nome do seu personagem.
O programa deve ler o nome completo (incluindo espaços) e, em seguida, verificar se
o seu tamanho é válido (ou seja, menor ou igual a 15 caracteres).

Requisitos:
Inclusão de Bibliotecas: Inclua as bibliotecas necessárias para entrada/saída (stdio.h)
e para manipulação de strings (string.h).
Variável para o Nome: Crie uma variável do tipo char (um vetor de caracteres) chamada
nome_jogador com tamanho suficiente para armazenar o nome (ex: 50 caracteres).
Entrada do Usuário: Mostre uma mensagem na tela pedindo para o jogador digitar um nome.
Leitura do Nome: Use scanf para ler a linha inteira que o jogador digitar, armazenando-a
na variável nome_jogador. Lembre-se de como ler textos com espaços, como mostrado na aula.
Verificação do Tamanho: Utilize a função strlen() para obter o número de caracteres do nome digitado.
Lógica de Decisão: Use uma estrutura if-else para verificar se o tamanho do nome é menor ou igual a 15.
Saída:
Se o nome for válido, imprima na tela: Nome valido! Bem-vindo ao jogo, [nome do jogador]!
Se o nome for muito longo, imprima na tela: Nome muito longo! Por favor, escolha um nome com ate 15 caracteres.*/
#include <stdio.h>
#include <string.h>

int main(){

char nome_jogador[50];

printf("Digite seu nome de jogador\n");
scanf(" %[^\n]s", nome_jogador);
printf("%s\n", nome_jogador);
if (strlen(nome_jogador) <= 15){
    printf("Nome valido! Bem-vindo ao jogo %s \n", nome_jogador);
}
else{
    printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres\n");
}
    return 0;
}