/*Problema: Identificando a Maior Ameaça em uma Horda de Inimigos

Contexto: Suponhamos que em um jogo de Tower Defense, cada onda de ataque é 
definida em um arquivo de texto (wave_data.txt). Este arquivo lista todos os 
inimigos que aparecerão, mas o número de inimigos pode variar de onda para onda. 
Para a IA do jogo priorizar os alvos mais perigosos, o sistema precisa ler 
todos os inimigos da onda e identificar qual deles possui o maior poder de 
ataque.

Tarefa:
Crie um programa em C que leia os dados de um número indeterminado de inimigos 
de um arquivo chamado wave_data.txt. Cada linha do arquivo contém o nome de um 
inimigo (uma única palavra), seus pontos de vida (inteiro) e seu poder de ataque 
(inteiro). O programa deve ler todos os inimigos, encontrar aquele com o maior 
poder de ataque e imprimir seu nome, vida e ataque na tela.

Requisitos:
Defina uma struct chamada Inimigo para armazenar o nome (string com até 50 caracteres), vida (int) e ataque (int).
Use typedef para criar um alias Inimigo para a estrutura.
Abra e leia o arquivo wave_data.txt. Se o arquivo não puder ser aberto, exiba uma mensagem de erro e encerre o programa.
Use um laço while com fscanf() e a verificação != EOF para ler todos os inimigos do arquivo.
Armazene os dados do inimigo mais forte encontrado até o momento em uma variável do tipo Inimigo.
Após ler todo o arquivo, imprima os dados do inimigo com o maior ataque, 
no formato: "Maior Ameaça: [nome], Vida: [vida], Ataque: [ataque]\n".
O arquivo wave_data.txt deve ser criado por você e ter o seguinte formato (o número de linhas é variável):
Goblin 50 10
Orc 120 25
Esqueleto 75 15
Lich 200 50
Gargula 90 22
A saída esperada para o exemplo acima seria: Maior Ameaça: Lich, Vida: 200, Ataque: 50*/

#include <stdio.h>
typedef struct 
{
   char nome[50];
   int vida;
   int ataque;
}Inimigo;

int main(){
    Inimigo inimigo_temp;
    FILE *file = fopen("wawe_data.txt", "r");
    if(file == NULL){
        printf("Erro ao entrar no arquivo");
        return 1;
    }

    Inimigo inimigo_mais_forte;

    while(fscanf(file, "%s %d %d", inimigo_temp.nome, &inimigo_temp.vida, &inimigo_temp.ataque) != EOF ){
        if(inimigo_temp.ataque >= inimigo_mais_forte.ataque){
            inimigo_mais_forte = inimigo_temp;
        }
    }
    printf("Maior Ameaça: [%s], Vida: [%d], Ataque: [%d]\n");
    return 0;
}
