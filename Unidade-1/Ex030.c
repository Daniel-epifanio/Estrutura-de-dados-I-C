/*Problema: Criando o Personagem do Jogo

Contexto: Você está desenvolvendo um novo jogo de plataforma! O primeiro passo é 
criar a tela de "Criação de Personagem". Neste jogo, cada personagem é definido 
por um nome, uma quantidade inicial de vidas e uma pontuação que começa em zero. 
Para organizar esses dados, você usará uma struct. O programa deve pedir ao jogador 
que digite o nome desejado e, em seguida, usar esse nome para configurar a estrutura 
de dados do personagem.

Tarefa:
Escreva um programa em C que crie uma estrutura para um jogador, defina seus atributos 
iniciais, leia o nome digitado pelo usuário e o armazene corretamente na estrutura.

Requisitos:
Bibliotecas: Inclua as bibliotecas stdio.h e string.h.
Estrutura do Jogador: Defina uma struct chamada Jogador que contenha os seguintes membros:
- Um array de char chamado nome com capacidade para 50 caracteres.
- Um int chamado vidas.
- Um int chamado pontuacao.
Função Principal (main):
- Declare uma variável do tipo struct Jogador chamada player1.
- Inicialize os Atributos: Defina o valor de player1.vidas como 3 e player1.pontuacao como 0.
- Variável Temporária: Crie um array de char local chamado nome_digitado com 50 posições para 
armazenar temporariamente o nome que o usuário digitará.
- Peça o Nome: Mostre uma mensagem na tela pedindo para o usuário digitar o nome do personagem. 
Ex: "Digite o nome do seu personagem: "
- Leia o Nome: Use scanf para ler a string digitada pelo usuário e armazená-la na variável 
nome_digitado.
- Copie para a Estrutura: Utilize a função strcpy para copiar o nome de nome_digitado para 
o membro player1.nome.
- Confirmação: Imprima uma mensagem de boas-vindas que mostre todos os dados armazenados na struct, 
para confirmar que a operação foi bem-sucedida. A saída deve ser parecida com: "Personagem criado! 
Bem-vindo, [NomeDoJogador]! Vidas: 3, Pontuação: 0"*/
#include <stdio.h>
#include <string.h>

struct jogador
{
    char nome[50];
    int vidas;
    int pontuacao;
};

int main(){
    struct jogador player1;

    player1.vidas = 3;
    player1.pontuacao = 0;

    char nome_digitado[50];
    
    printf("Digite o nome do player\n");
    scanf("%s", nome_digitado);
    strcpy(player1.nome, nome_digitado);
    printf("Personagem criado! Bem-vindo, %s! Vidas: %d, Pontuação: %d\n", player1.nome, player1.vidas, player1.pontuacao);


    return 0;
}