/*Problema: Gerenciamento de Inimigos em uma Fase

Contexto: Em um jogo de plataforma, cada fase pode ter um número diferente de inimigos. 
Em uma fase na floresta, podem existir 10 inimigos, enquanto em uma fase no castelo podem 
existir 50. Usar um vetor de tamanho fixo para armazenar o status de cada inimigo (por exemplo, 
vivo ou derrotado) seria ineficiente. A solução ideal é alocar a memória necessária para os 
inimigos dinamicamente, apenas quando a fase é carregada.
A função calloc é especialmente útil aqui. Além de alocar a memória, ela inicializa todos 
os espaços com o valor 0. Em nosso jogo, podemos usar 0 para representar um inimigo "inativo" 
ou "derrotado" e 1 para um inimigo "ativo" ou "vivo". Assim, ao carregar a fase, todos os 
inimigos já começam no estado "inativo" por padrão, e depois podemos "ativá-los" conforme 
necessário.

Tarefa:
Escreva um programa em C que simule o carregamento de uma fase de um jogo. 
O programa deve perguntar quantos inimigos a fase terá, alocar memória para 
eles usando calloc, e depois "ativar" todos eles.

Requisitos:
Quantidade de Inimigos: Peça ao usuário para digitar um número inteiro que 
representará a quantidade de inimigos na fase. Armazene este valor em uma variável.
Ponteiro para Inimigos: Crie uma variável do tipo "ponteiro para inteiro" 
chamada status_inimigos.
Alocação com calloc: Use a função calloc para alocar um espaço de memória 
para a quantidade de inimigos informada. Cada inimigo precisa de espaço para um único int.
Verificação Pós-Alocação: Imediatamente após a alocação, use um laço de 
repetição (for) para percorrer o vetor e imprimir o status de cada inimigo. 
A saída esperada é que todos os status sejam 0, mostrando o efeito da inicialização 
do calloc. A saída para cada inimigo deve ser: Inimigo X: Inativo (0)
Ativação dos Inimigos: Use outro laço de repetição para percorrer o vetor e 
mudar o status de cada inimigo de 0 para 1.
Relatório Final: Após ativar todos os inimigos, use um último laço de repetição 
para imprimir o novo status de cada um. A saída para cada inimigo deve ser: Inimigo X: Ativo (1)
Liberar Memória: Ao final do programa, não se esqueça de usar a função free 
para liberar a memória que foi alocada dinamicamente.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

int qinimigos;
printf("Digite a quantidade de inimigos");
scanf("%d", &qinimigos);

int *status_inimigos = (int *) calloc(qinimigos, sizeof(int));
int i;
    for(i = 0; i < qinimigos; i++){
    printf("Inimigo X: Inativo %d", status_inimigos[i]);
    printf("\n");
    }
    for(i = 0; i < qinimigos; i++){
        status_inimigos[i] = 1;
    }
    for(i = 0; i < qinimigos; i++){
        printf("Inimigo X: Ativo %d", status_inimigos[i]);
        printf("\n");
    }
    free(status_inimigos);

    return 0;
}