#include <stdio.h>
#include "heroi.h"
#include <stdlib.h>

struct heroi{
    char nome[50];
    int hp;
    int ataque;
};

heroi* cria(int n){
    heroi * v = (heroi *) malloc(n * sizeof(heroi));
    return v;
}

void ler(int n, heroi *v){
    printf("Informe os dados dos herois:\n");
    int i;
    for (i = 0; i < n; i++){
        scanf("%s %d %d", v[i].nome, &v[i].hp, &v[i].ataque);
    }
}

void imprimir(int n, heroi *v){
    int i;
    for (i = 0; i < n; i++){
        printf("%s: %d HP, %d ATK\n", v[i].nome, v[i].hp, v[i].ataque);
    }
}