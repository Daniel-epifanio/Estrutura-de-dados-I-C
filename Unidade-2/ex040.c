/*Problema: Salvando o Recorde do Jogo

Contexto: Suponhamos que você esta desenvolvendo um jogo de corrida arcade, 
'Nitro Dash', ao final de cada sessão com múltiplos jogadores, o sistema deve 
registrar permanentemente o recorde da partida. Em vez de apenas mostrar o 
vencedor na tela, essa informação precisa ser salva em um arquivo de texto 
para que possa ser lida posteriormente pelo menu principal do jogo, exibindo 
o 'High Score' atual.

Tarefa:
Crie um programa em C que leia o nome e a pontuação de um número 'n' de jogadores. 
O programa deve identificar qual jogador obteve a maior pontuação e, em seguida, 
escrever o nome e a pontuação apenas deste jogador em um arquivo chamado highscore.txt.

Requisitos:
O programa deve primeiro ler um número inteiro n, que representa a quantidade de jogadores na partida.
Utilize uma struct para armazenar os dados de cada jogador (nome e pontuação).
Leia os dados dos n jogadores do console e armazene-os em um vetor de structs.
Implemente uma lógica para encontrar o jogador com a maior pontuação.
Abra um arquivo chamado highscore.txt em modo de escrita ("w").
Utilize a função fprintf() para escrever o nome e a pontuação do jogador recordista no arquivo, 
no formato "Nome: [nome], Pontuacao: [pontuacao]".
Feche o arquivo corretamente ao final da operação.*/

#include <stdio.h>

typedef struct
{
    char nome[50];
    float pontuacao;
}Jogador;

int main(){

int n = 0;

printf("digite o número de jogadores\n");
scanf("%d", &n);

Jogador jogadores[n];

for(int i = 0; i < n; i++){
printf("Digite o nome do jogador\n");
scanf("%s", jogadores[i].nome);

printf("Digite a pontuacao do jogador\n");
scanf("%f", &jogadores[i].pontuacao);
}

int recorde = 0;

for(int i = 0; i < n; i++){
if(jogadores[i].pontuacao > jogadores[recorde].pontuacao){
    recorde = i;
    }
}

FILE *file = fopen("highscore.txt", "w");

 if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
}
    fprintf(file, "Nome: %s, Pontuacao: %.2f\n", 
        jogadores[recorde].nome, 
        jogadores[recorde].pontuacao);

    fclose(file);
    return 0;
}