/*Contexto: Em qualquer jogo de RPG, a capacidade de salvar o progresso do jogador é essencial. 
Em vez de usar um arquivo de texto, que pode ser facilmente lido e modificado por jogadores, 
muitos jogos usam um formato binário para armazenar os 'save games'. Isso torna os arquivos mais 
compactos, mais rápidos de carregar e um pouco mais difíceis de adulterar.

Tarefa:
Você deve criar um programa em C que funcione como um sistema de criação de personagens para um RPG. 
O programa deve apresentar um menu com as opções para 'Criar Novo Personagem' ou 'Sair'. Toda vez que 
um novo personagem for criado, suas informações (nome, nível, vida e mana) devem ser salvas em um arquivo 
binário chamado savegame.sav.

Requisitos:
Defina uma struct chamada Personagem para armazenar o nome (string de até 50 caracteres), nível (inteiro), vida (float) e mana (float).
Crie um menu interativo que continue em execução até que o usuário escolha a opção 'Sair'.
Ao escolher 'Criar Novo Personagem', o programa deve solicitar ao usuário que insira as informações do personagem.
As informações de cada personagem criado devem ser escritas em um arquivo binário chamado savegame.sav.
Utilize a função fopen() com o modo correto para escrita binária ("wb").
Utilize a função fwrite() para escrever a estrutura do personagem no arquivo.
O programa deve fechar o arquivo corretamente antes de terminar.*/
#include <stdio.h>

typedef struct{
    char nome[50];
    int nivel;
    float vida;
    float mana;
}Personagem;

void menu(){
    printf("========== Escolha uma opção ==========\n");
    printf("1----- Criar Novo Personagem\n");
    printf("2----- Sair\n");
    printf("=======================================\n");
} 

int main(){
    FILE *file = fopen("savegame.sav", "ab");
    int op;
    scanf("%d", &op);
    while(op != 2){
        if(op == 1){
        Personagem p;
        printf("Insira os dados do personagem\n");
        scanf("%s %d %f %f", p.nome, &p.nivel, &p.vida, &p.mana);
        fwrite(&p, sizeof(Personagem), 1, file);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado");
    fclose(file);

    return 0;
}