/*Problema: Gerador de Ondas de Inimigos

Contexto: Em um jogo de plataforma, as fases são compostas por "ondas" de inimigos.
Cada onda pode ter uma quantidade diferente de inimigos para desafiar o jogador. Por
exemplo, a primeira onda pode ter 3 inimigos fáceis, enquanto uma onda posterior pode
ter 10 inimigos variados.
Para que o motor do jogo seja eficiente, ele não pode reservar um espaço fixo e muito
grande na memória para os inimigos de todas as ondas. Em vez disso, ele aloca
dinamicamente a memória exata necessária para a quantidade de inimigos da onda atual.

Tarefa:
Escreva um programa em C que simule a criação de uma onda de inimigos. O programa
deve primeiro perguntar ao usuário quantos inimigos a onda terá. Em seguida, deve 
alocar memória para um vetor desse tamanho e permitir que o usuário defina um "ID" 
(um número inteiro) para cada inimigo. Por fim, o programa deve listar os IDs de 
todos os inimigos que foram criados para a onda.

Requisitos:
Variável de Quantidade: Crie uma variável inteira chamada n_inimigos para armazenar 
a quantidade de inimigos.
Ponteiro da Onda: Crie um ponteiro para inteiro chamado ponteiro_onda que irá apontar 
para o nosso vetor de inimigos na memória.
Entrada do Usuário: Peça ao usuário para digitar a quantidade de inimigos da onda e 
armazene o valor em n_inimigos.
Alocação Dinâmica: Use a função malloc() para alocar um bloco de memória que possa 
conter n_inimigos números inteiros. O endereço deste bloco deve ser atribuído a ponteiro_onda.
Populando a Onda: Crie um laço (for) que peça ao usuário para digitar o ID de cada um 
dos n_inimigos e armazene cada ID no vetor alocado.
Listando os Inimigos: Após preencher o vetor, mostre na tela uma mensagem de confirmação, 
seguida pela lista de todos os IDs dos inimigos da onda. Exemplo de saída: "Onda de inimigos 
criada com sucesso! IDs: 101 205 101"*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n_inimigos;
    int *ponteiro_onda = (int *)malloc(n_inimigos* sizeof(int));
     
    if (ponteiro_onda == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("Digite a quantidade de inimigos da onda\n");
    scanf("%d", &n_inimigos);
    int i;
    for(i = 0; i < n_inimigos; i++){
        printf("Digite o ID do inimigo %d\n", i + 1);
        scanf("%d", &ponteiro_onda[i]);
    }
        printf("Onda de inimigos criada com sucesso! IDs:\n");
    for(i = 0; i < n_inimigos; i++){
        printf("%d\n",ponteiro_onda[i]);
    }
    return 0;
}