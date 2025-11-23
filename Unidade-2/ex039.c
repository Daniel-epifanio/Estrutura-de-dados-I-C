/*Problema: Carregando Atributos de Inimigos de um Arquivo

Contexto: Imagine que você é um desenvolvedor para um novo RPG de fantasia, "Dragon's Grimoire". 
Para balancear o jogo, a equipe de design criou um arquivo de texto contendo os atributos base 
de diferentes tipos de inimigos. Seu trabalho é criar um programa que leia este arquivo, analise 
os dados e identifique quais inimigos são considerados "elite" com base em seus atributos combinados.

Tarefa:
Escreva um programa em C que leia os dados de três tipos de inimigos de um arquivo de texto 
chamado inimigos.txt. Cada linha do arquivo conterá o nome do inimigo (uma única palavra), 
seus pontos de vida (HP) e seu poder de ataque (ATK).

Requisitos:

Defina uma struct para armazenar os dados de um inimigo (nome, HP, ATK).
Crie um arquivo chamado inimigos.txt no mesmo diretório do seu código-fonte com o seguinte conteúdo:
Goblin 80.0 30.5
Orc 150.0 55.0
Dragao 500.0 95.5
Seu programa deve abrir e ler os dados deste arquivo para um vetor de estruturas.
Para cada inimigo, calcule um "Nível de Ameaça" somando seu HP e seu ATK.
Imprima na tela o nome e o Nível de Ameaça apenas dos inimigos considerados "elite", 
ou seja, aqueles cujo Nível de Ameaça seja maior ou igual a 200.
Feche o arquivo corretamente ao final do programa.*/
#include <stdio.h>

typedef struct
{
 char nome[50];
 float HP;
 float ATK;
}inimigos;

int main(){

inimigos monstro01;
inimigos monstro02;
inimigos monstro03;
inimigos Monstros[3] = {monstro01, monstro02, monstro03};
int i;

FILE *file = fopen("inimigos.txt", "r");

for(i = 0; i < 3; i++){
fscanf(file, "%s %f %f", Monstros[i].nome, &Monstros[i].HP, &Monstros[i].ATK);
}

fclose(file);

float elite = 0;
for(i = 0; i < 3; i++){
    elite = Monstros[i].HP + Monstros[i].ATK;
    if(elite >= 200){
        printf("%s - Inimimos elite %.2f\n", Monstros[i].nome, elite);
    }
}

    return 0;
}
