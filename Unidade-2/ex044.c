/*Problema: Atualização de Log de Sessão de Jogo

Contexto: Suponhamos que você esta desenvolvendo um sistema para um RPG, que registra as conquistas do jogador em tempo real em um arquivo de texto chamado player_log.txt. Ao final de cada sessão de jogo, o sistema precisa ler este log para calcular algumas estatísticas e, em seguida, anexar um marcador de 'Sessão Concluída' ao mesmo arquivo, sem apagar o conteúdo original.

Tarefa:
Crie um programa em C que leia os dados de player_log.txt. O arquivo começa com um número inteiro N, 
indicando o número total de conquistas registradas na sessão. Cada uma das N linhas seguintes contém 
dois inteiros: um ID de conquista e os pontos de experiência ganhos. O programa deve ler todas as N 
conquistas, calcular o total de pontos de experiência ganhos na sessão e imprimir esse total no console.
Em seguida, o programa deve acrescentar a string "\n--- SESSION CONCLUDED ---" ao final do arquivo player_log.txt.

Requisitos:
Utilize uma struct para representar uma conquista (contendo id e pontos).
O arquivo player_log.txt deve ser aberto em um modo que permita tanto a leitura quanto a escrita.
Utilize fscanf para ler os dados do arquivo.
Utilize fprintf para escrever a mensagem final no arquivo.
Gerencie corretamente o ponteiro do arquivo para poder escrever após ter lido todo o seu conteúdo.*/

#include <stdio.h>

typedef struct
{
    int id;
    int pontos;
}Conquista;

int main(){

FILE *file = fopen("player_log.txt", "r+");
int n;
fscanf(file, "%d", &n);
Conquista conquistas[n];
int total = 0;
for(int i = 0; i < n; i++){
    fscanf(file, "%d %d", &conquistas[i].id, &conquistas[i].pontos);
    total += conquistas[i].pontos;
}
printf("Total de pontos: %d\n", total);
fseek(file, 0, SEEK_END);
fprintf(file, "\n--- SESSION CONCLUDED ---");
fclose(file);
    return 0;
}