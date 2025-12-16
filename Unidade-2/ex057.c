/*Contexto: Supondo um jogo de RPG, um mago precisa avaliar seu estoque de Cristais de 
Mana antes de entrar em uma masmorra perigosa. Cada cristal em seu inventário possui um 
nível de carga de energia, que pode ser positivo (cristal carregado), zero (neutro) ou 
negativo (esgotado). Apenas os cristais com carga positiva podem ser usados para conjurar 
feitiços. Para planejar sua exploração, o mago precisa saber exatamente quantos feitiços 
ele pode lançar, ou seja, quantos cristais carregados ele possui.

Tarefa:
Você deve criar um programa em C que leia o número de cristais no inventário do mago e, 
em seguida, os níveis de carga de cada um. O programa deve usar uma função recursiva para 
contar quantos desses cristais têm um nível de carga estritamente positivo.

Requisitos:
O programa deve primeiro ler um número inteiro n, que representa a quantidade de cristais no inventário.
Em seguida, deve ler n números inteiros, que são os níveis de carga de cada cristal, e armazená-los em um vetor.
Você deve implementar uma função recursiva que receba o vetor, seu tamanho e o índice atual como parâmetros para realizar a contagem.
O programa deve imprimir a quantidade total de cristais com carga positiva.*/

 #include <stdio.h>
 #include <stdlib.h>

 int carga_positiva(int i, int n, int *v){
    if(i == n){
        return 0;
    }
    if(v[i] > 0){
        return 1 + carga_positiva(i + 1, n, v);
    }
    return carga_positiva(i + 1, n, v);
}

int main(){
    int n;
    printf("Digite a quantidade de cristais que você possui\n");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int positivas = carga_positiva(0, n, v);
    printf("Quantidade de cargas positivas: %d\n", positivas);

    free(v);
    return 0;
}