/*Problema: Coletando Moedas com Ponteiros

Contexto: Em um jogo de plataforma, o design de uma fase pode ser representado por um vetor,
onde cada posição simboliza um bloco do cenário. Por exemplo, o número 0 pode ser um espaço
vazio e 1 pode ser uma moeda. O personagem do jogador "caminha" por este vetor, e o jogo
precisa verificar o que há em cada bloco para decidir o que fazer. Para otimizar o acesso
a esses dados, muitos jogos usam ponteiros para percorrer as estruturas do cenário.

Tarefa:
Escreva um programa em C que simule um jogador percorrendo uma fase e coletando todas as moedas.
O programa deve usar aritmética de ponteiros para "caminhar" pela fase e verificar o conteúdo de cada bloco.

Requisitos:
Vetor da Fase: Crie um vetor de inteiros chamado fase com 10 posições. Inicialize-o com o seguinte layout:
{0, 1, 0, 0, 1, 1, 0, 1, 0, 0}.
Ponteiro do Jogador: Crie uma variável do tipo "ponteiro para inteiro" chamada ponteiro_jogador.
Contador de Moedas: Crie uma variável inteira chamada moedas_coletadas e inicialize-a com 0.
Conecte o Ponteiro: Faça com que ponteiro_jogador aponte para o início do vetor fase.
Percorrendo a Fase: Crie um laço de repetição (um for) que percorra todos os 10 blocos da fase.
Lógica de Coleta: Dentro do laço, use aritmética de ponteiros para verificar o valor do bloco atual
(por exemplo, *(ponteiro_jogador + i)). Se o valor for 1 (uma moeda), incremente a variável moedas_coletadas.
Imprima o Resultado: Após o laço, mostre na tela o total de moedas coletadas. A saída deve ser:
"O jogador coletou um total de 4 moedas!"*/
#include <stdio.h>

int main(){

int vet[10] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
int *ponteiro_jogador;
int cont_moedas = 0;
 ponteiro_jogador = vet;

for(int i = 0; i < 10; i++){
    printf("%d \n", *(ponteiro_jogador + i) );
    if(*(ponteiro_jogador + i) == 1){
        cont_moedas += 1;
    }
}
    printf("O jogador coletou um total de %d moedas!", cont_moedas);

    return 0;
}
