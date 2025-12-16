/*
Contexto: Em um jogo de estratégia em tempo real, antes de iniciar uma batalha, a 
sua IA precisa fazer um reconhecimento rápido do esquadrão inimigo para exibir um 
relatório na tela. O número de unidades no esquadrão inimigo pode variar a cada partida.

Tarefa:
Crie um programa em C que primeiro leia um número inteiro n, representando a quantidade 
de unidades inimigas no campo de batalha. Em seguida, o programa deve ler os dados de 
cada uma das n unidades. Para cada unidade, leia seu tipo (uma única palavra, como "Orc", 
"Goblin", "Troll") e seus pontos de vida (HP), que é um número inteiro.

Requisitos:
Defina uma struct chamada Inimigo para armazenar o tipo (string com no máximo 50 caracteres) 
e o HP (inteiro) de uma unidade.
Leia o número n de unidades.
Utilize um laço de repetição (for ou while) para ler os dados de todas as n unidades.
Para cada unidade lida, imprima imediatamente seu tipo e HP no formato: "Inimigo: [tipo], HP: [hp]\n".
O programa deve ser capaz de lidar com qualquer número n de inimigos, demonstrando uma complexidade de tempo linear.*/
#include <stdio.h>

typedef struct{
    char tipo[50];
    int hp;
}Inimigo;

int main(){
int n;
printf("Quantas unidades inimigas existem no campo?\n");
scanf("%d", &n);

Inimigo oponente;
int i; 
for(i = 0; i < n; i++){
    scanf("%s %d", oponente.tipo, &oponente.hp);
    printf("Inimigo: %s, %d\n", oponente.tipo, oponente.hp);
}
    return 0;
}