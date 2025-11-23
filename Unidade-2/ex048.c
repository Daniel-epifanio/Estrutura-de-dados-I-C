/*Contexto: Supondo que você esta desenvolvendo um jogo de arena de batalha, antes de cada partida, 
o sistema precisa carregar os dados do esquadrão pré-selecionado pelo jogador. As informações de 
cada campeão (nome, vida e poder de ataque) são armazenadas de forma compacta e eficiente em um 
arquivo binário chamado squad.dat.

Tarefa: Você deve escrever um programa em C que leia os dados de um esquadrão de 3 campeões a partir 
do arquivo binário squad.dat. Após carregar os dados para um vetor de estruturas, o programa deve 
identificar e imprimir na tela o nome do campeão com a maior quantidade de pontos de vida (HP), 
designando-o como o 'Tanque' do esquadrão.

Requisitos:
Defina uma struct chamada Campeao com os seguintes membros: char nome[50], int vida, int ataque.
Use typedef para criar um alias Campeao para a sua struct.
O programa deve abrir o arquivo squad.dat em modo de leitura binária ('rb').
Use a função fread() para ler os dados dos 3 campeões do arquivo diretamente para um vetor de Campeao em uma única operação.
Após a leitura, feche o arquivo.
Itere sobre o vetor para encontrar o campeão com o maior valor no membro vida.
Imprima o nome do campeão encontrado, seguido pela frase ': Tanque do esquadrão.'.
Importante: Para que seu programa funcione, você precisará de um arquivo squad.dat. 
Você pode criar este arquivo executando um programa auxiliar (não precisa entregar este auxiliar) 
que usa fwrite() para salvar 3 structs Campeao nele. Exemplo de dados a serem salvos:
Garen, 620, 69
Lux, 530, 55
Ashe, 590, 61*/
#include <stdio.h>

typedef struct
{
    char nome[50];
    int vida;
    int ataque;
}Campeao;

int main(){
    FILE *file = fopen("squad.dat", "rb");
    Campeao camp[3];
    fread(camp, sizeof(Campeao), 3, file);
    fclose(file);
    int i; 
    int tanque_do_esquadrao = 0;
    for(i = 0; i < 3; i++)
    {
        if(camp[i].vida > camp[tanque_do_esquadrao].vida){
            tanque_do_esquadrao = i;
        }
    }
    printf("Tanque do esquadrão: %s\n", camp[tanque_do_esquadrao].nome);
  

    return 0;
}
