/*
Problema: Posicionando um Power-up no Cenário

Contexto: Você é um programador de jogos criando um novo jogo de plataforma.
Uma parte do seu trabalho é carregar o design dos níveis. Um nível é composto
por uma fileira horizontal de blocos. Para simplificar, vamos representar os
blocos com números inteiros: 0 significa um espaço vazio e 1 significa um bloco
de plataforma sólido. Você precisa criar uma função que leia a configuração de
uma fileira de blocos do cenário. Depois que a fileira é lida, seu programa deve
encontrar o primeiro bloco de plataforma (1) e substituí-lo por um bloco de "power-up",
que será representado pelo número 2. O uso de ponteiros é essencial para que a função
de leitura modifique o vetor do cenário diretamente, sem criar cópias desnecessárias na memória, garantindo eficiência.

Tarefa:
Escreva um programa em C que simule a leitura de uma fileira de blocos de um cenário e, em seguida, posicione um power-up.

Requisitos:
1. Função ler_cenario:
Crie uma função chamada ler_cenario que não retorna nada (void).
Ela deve receber dois parâmetros: um inteiro n (o tamanho da fileira) e um ponteiro para
inteiro cenario (que aponta para o início do vetor do cenário).
Dentro desta função, use um laço for para ler n valores inteiros (0 ou 1) do usuário.
Para a leitura de cada valor com scanf, você deve usar aritmética de ponteiros
(ex: cenario + i) para indicar o endereço de memória de cada posição do vetor.
2. Função main:
Peça ao usuário para digitar o número de blocos no cenário (n).
Declare um vetor de inteiros chamado cenario com tamanho n.
Chame a função ler_cenario para preencher o vetor.
Após a leitura, percorra o vetor cenario. Encontre o primeiro bloco que seja uma plataforma (1)
e mude seu valor para 2 (o power-up). Interrompa a busca assim que encontrar o primeiro.
Imprima na tela o vetor do cenário já modificado, com os números separados por um espaço.*/
#include<stdio.h>

void ler_cenario(int n, int *cenario);

int main(){
int n;
int i;
    printf("Digite a quantidade de blocos do cenario\n");
    scanf("%d", &n);
    int cenario[n];
    ler_cenario(n, cenario);

    for(i = 0; i < n; i++){
        if(*(cenario + i) == 1){
        *(cenario + i) = 2;
        break;
    }
 }
    for(i = 0; i < n; i++){
        printf("%d", *(cenario + i));
    }

    return 0;
}
    void ler_cenario(int n, int *cenario){
            int i;
             for (i = 0; i < n; i++) {
            printf("Digite o valor do bloco %d (0 = vazio, 1 = plataforma): ", i);
            scanf("%d", (cenario + i));
    
    
        }

    }