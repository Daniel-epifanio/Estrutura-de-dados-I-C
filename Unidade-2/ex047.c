/*Contexto: Em um jogo de estratégia tática como 'XCOM' ou 'Final Fantasy Tactics', o jogador monta um esquadrão de unidades antes de cada missão. O estado completo deste esquadrão (com todos os seus membros) precisa ser salvo em um arquivo para que a missão possa ser carregada. Usar um arquivo binário é ideal para isso, pois é rápido e eficiente.

Tarefa:
Crie um programa que permita ao jogador montar um esquadrão. O programa deve primeiro 
perguntar quantas unidades o jogador deseja incluir no esquadrão. Em seguida, para cada 
unidade, o programa deve ler seu nome (uma única palavra), seu nível de vida (HP) e seu 
poder de ataque (ATK).

Após ler os dados de todas as unidades para um vetor de estruturas, o programa deve salvar 
o vetor inteiro de uma só vez em um arquivo binário chamado squad.dat. Finalmente, o programa 
deve percorrer o vetor na memória e imprimir na tela o nome da unidade com o maior poder de ataque (ATK).

Requisitos:
Defina uma struct chamada Unidade para armazenar o nome (string de até 50 caracteres), a vida (inteiro) e o ataque (inteiro) de uma unidade.
Use typedef para criar um alias Unidade para a sua struct.
O programa deve primeiro ler um número inteiro n que representa o número de unidades no esquadrão.
Aloque dinamicamente um vetor de n estruturas do tipo Unidade.
Use um laço for para preencher o vetor com os dados das n unidades lidos do teclado.
Abra um arquivo chamado squad.dat em modo de escrita binária ("wb").
Use uma única chamada da função fwrite() para escrever o vetor inteiro no arquivo.
Após a escrita, feche o arquivo.
Percorra o vetor em memória para encontrar a unidade com o maior valor de ATK.
Imprima o nome da unidade com o maior ATK na tela.
Libere a memória alocada dinamicamente antes de encerrar o programa.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[50];
    int vida;
    int ataque;
}Unidade;

int main(){

    printf("Quantas unidades terá o esquadrão\n");
    int n;
    scanf("%d", &n);
FILE *file = fopen("squad.dat", "wb");

     Unidade *uni = (Unidade*) malloc(n * sizeof(Unidade));
int i;
for(i = 0; i < n; i++){
    scanf("%s %d %d", uni[i].nome, &uni[i].vida, &uni[i].ataque);
}

    fwrite(uni, sizeof(Unidade), n, file);
    fclose(file);
int maior_ataque = 0;
for(i = 0; i < n; i++){
    if(uni[i].ataque > uni[maior_ataque].ataque){
        i = maior_ataque;
    }
}
   printf("\nA unidade com maior ATK é: %s\n", uni[maior_ataque].nome);
   free(uni);

    return 0;
}