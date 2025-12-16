/*Contexto: Supondo que em um RPG, um mago domina um feitiço chamado 'Ataque em Cascata'. 
A cada nível que o mago possui, o feitiço se torna mais poderoso, adicionando um 'eco' de 
dano extra. O dano total é a soma do dano do nível atual mais a soma de todos os danos dos 
níveis anteriores. Por exemplo, no nível 5, o dano total é 5 (nível atual) + 4 + 3 + 2 + 1 = 15.

Tarefa:
Crie um programa que calcule o dano total do 'Ataque em Cascata' para um determinado nível do mago. 
O programa deve receber o nível do mago como entrada e imprimir o dano total.

Requisitos:
Você deve implementar a solução usando uma função recursiva. A função deve ter um caso 
base para o nível 1 e um passo recursivo para os demais níveis.*/

#include <stdio.h>


int cascata(int n){
     if(n == 1){
        return 1;
    }

    return n + soma(n -1);
}
int main(){
    int n;
    printf("Digite o valor de n\n");
    scanf("%d", &n);
    int solucao = cascata(n);
    printf("%d\n", solucao);

    return 0;
}