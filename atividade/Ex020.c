/*Problema: O Temporizador do Power-Up "Super Salto"

Contexto: Em um jogo de plataforma, o seu personagem pode coletar um "power-up"
que lhe concede a habilidade de "Super Salto" por um tempo limitado. Para controlar
a duração desse efeito, o jogo precisa de um temporizador. Em vez de criar uma
variável separada para cada tipo de temporizador, o motor do jogo usa um sistema
genérico de alocação de memória para guardar a duração restante do efeito,
independentemente de qual seja.

Tarefa:
Escreva um programa em C que simule a ativação de um power-up "Super Salto" com
uma duração inicial e, em seguida, simule a passagem do tempo, atualizando sua duração.

Requisitos:
Inclua as Bibliotecas: Lembre-se de incluir <stdio.h> para as funções de
entrada/saída e <stdlib.h> para a alocação de memória.
Alocação de Memória Genérica: Crie uma variável do tipo "ponteiro genérico"
(void *) chamada ponteiro_duracao. Use a função malloc para alocar memória
suficiente para armazenar um único número inteiro (int).
Ativação do Power-Up: Para definir a duração inicial do "Super Salto",
você precisa:
Fazer um "cast" (conversão de tipo) do seu ponteiro_duracao para um
"ponteiro para inteiro" (int *).f
Usar o operador de indireção (*) para armazenar o valor 10 (representando
10 segundos) na memória alocada.
Imprima a Duração Inicial: Mostre na tela a duração inicial do power-up.
A saída deve ser: "Power-up 'Super Salto' ativado! Duracao: 10 segundos."
(Dica: para imprimir, você precisará fazer o cast e usar o operador de indireção novamente).
Simule a Passagem do Tempo: Diminua o tempo restante em 3 segundos.
Faça isso diretamente na memória usando o ponteiro_duracao (novamente, com cast e indireção).
Imprima a Duração Atualizada: Mostre na tela a duração restante.
A saída deve ser: "3 segundos se passaram... Duracao restante: 7 segundos."
Libere a Memória: Ao final do programa, use a função free() para liberar
a memória que você alocou. Isso é uma boa prática para evitar vazamentos de memória.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

void *ponteiro_duracao = malloc(sizeof (int));

if(ponteiro_duracao != NULL){
    *((int *)ponteiro_duracao) = 10;
    printf("Power-up 'Super Salto' ativado! Duracao: %d segundos.\n", *((int *)ponteiro_duracao));

    *((int *)ponteiro_duracao) -= 3;
    printf ("3 segundos se passaram... Duracao restante: %d segundos.\n", ponteiro_duracao);

    free(ponteiro_duracao);
} 
else {
        printf("Erro ao alocar memoria para o power-up.\n");
    }
    return 0;
}