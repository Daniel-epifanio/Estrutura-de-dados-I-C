/*Contexto: Supondo um jogo de ação e RPG, existe uma habilidade especial chamada "Golpe Ecoante". Esta habilidade permite ao jogador executar uma sequência de golpes, onde o dano bônus de cada golpe na sequência segue um padrão místico. O dano bônus não é fixo; ele aumenta com base nos dois golpes anteriores, criando um efeito de cascata devastador.

A regra do "Golpe Ecoante" é a seguinte:
O 1º golpe na sequência não tem dano bônus (0 pontos).
O 2º golpe na sequência tem um pequeno bônus de 1 ponto de dano.
A partir do 3º golpe, o dano bônus de um golpe é a soma do dano bônus dos dois golpes imediatamente anteriores.
Tarefa:
Você precisa implementar a lógica que calcula o dano bônus para qualquer golpe na sequência. Para isso, você criará uma função recursiva que modela perfeitamente essa regra de dano crescente. O uso de recursão com múltiplas chamadas é essencial para refletir a dependência de um golpe nos seus antecessores.

Requisitos:
Crie um programa que leia um número inteiro N do usuário, representando o número do golpe na sequência do "Golpe Ecoante".
Implemente uma função recursiva chamada calcularDanoEco(int n).
A função deve ter os seguintes casos base:
Se n for 1, a função deve retornar 0.
Se n for 2, a função deve retornar 1.
Para qualquer n maior que 2, a função deve retornar a soma de calcularDanoEco(n - 1) e calcularDanoEco(n - 2).
Na função main, chame a função recursiva com o número N lido e imprima o valor do dano bônus resultante.*/
#include <stdio.h>
#include <stdlib.h>

int calcularDanoEco(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
}

int main(){
    int n;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    int solucao = calcularDanoEco(n);
    printf("%d", solucao);

    return 0;
}