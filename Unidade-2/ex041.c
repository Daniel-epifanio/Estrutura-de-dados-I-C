/*Problema: Sistema de Log de Eventos para um Jogo

Contexto: Você está desenvolvendo um jogo de aventura e 
precisa criar um sistema de log para registrar eventos 
importantes que ocorrem durante o jogo, como 'Jogador 
encontrou item raro', 'Monstro Elite derrotado' ou 
'Portal descoberto'. Esses eventos devem ser salvos em 
um arquivo de texto chamado game_log.txt de forma 
persistente, ou seja, novos eventos devem ser adicionados 
ao final do arquivo sem apagar os registros anteriores.

Tarefa:
Crie um programa em C que funcione como um sistema de registro de eventos. 
O programa deve apresentar um menu simples ao usuário com as seguintes 
opções: 1 para 'Registrar novo evento' e 2 para 'Sair'.

Requisitos:
O programa deve ser executado em um laço, permitindo que o usuário registre 
múltiplos eventos em uma única execução.
Ao escolher a opção 1, o programa deve solicitar que o usuário digite uma frase 
descrevendo o evento (sem espaços, para simplificar a leitura com scanf).
Cada evento registrado deve ser adicionado em uma nova linha no arquivo game_log.txt.
O programa deve abrir o arquivo no modo correto para adicionar dados ao final dele ('append').
O programa deve ser encerrado quando o usuário digitar a opção 2.*/

#include <stdio.h>
#include <stdlib.h>

void menu(){
    printf("========== Digite a opção ==========\n");
    printf("1 ----- Registrar novo evento\n");
    printf("2 ----- Sair\n");
    printf("====================================\n");
}

int main(){
    FILE *file = fopen("game_log.txt", "a");
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if(op == 1){
            char frase[100];
            printf("Descreva o evento\n");
            scanf("%s", frase);
            fprintf(file, "%s\n", frase);
            fflush(file);
        }
    menu();
    scanf("%d", &op);
    }
    printf("Programa Finalizado");
fclose(file);

return 0;
}