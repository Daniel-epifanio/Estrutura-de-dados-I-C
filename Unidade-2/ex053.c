/*Problema: O Ritual de Diminuição Arcana

Contexto: Supondo um jogo de fantasia, um Mago do Tempo pode lançar o "Ritual de Diminuição Arcana". 
Este feitiço afeta um Golem mágico, cuja energia vital é representada por um número. A cada pulso do 
ritual, a energia do Golem é reduzida pela metade (usando divisão inteira). O ritual continua enquanto 
a energia do Golem for maior que 1.

Tarefa:
Crie um programa que simule este ritual. O programa deve ler o nível de energia inicial do Golem e, 
em seguida, imprimir o nível de energia a cada pulso do ritual, até que a condição de parada seja 
atingida. Este tipo de algoritmo, que reduz o problema pela metade a cada passo, é um exemplo clássico 
de complexidade de tempo logarítmica.

Requisitos:
Leia um número inteiro n que representa a energia inicial do Golem.
Use um laço de repetição (for ou while).
A cada iteração, imprima o valor atual da energia seguido por uma quebra de linha.
Após a impressão, o valor da energia deve ser atualizado para a metade do seu valor atual para a próxima iteração.
O laço deve continuar enquanto o valor da energia for maior que 1.*/
#include <stdio.h>

int main(){

int n;
printf("Digite a quantidade de energia do Sneaky Golem\n");
scanf("%d", &n);
for(int i = n; i > 1; i = i/2){
    printf("%d\n", i);
}

    return 0;
}
