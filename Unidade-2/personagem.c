#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[30];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    if (num_membros <= 0) {
        return NULL;
    }

    Personagem *party = (Personagem *) malloc(num_membros * sizeof(Personagem));
    return party;

}

void registra_membros(Personagem* party, int num_membros) {
    int i;
    for (i = 0; i < num_membros; i++) {
        printf("Informe nome, classe, nivel e hp do membro %d:\n", i + 1);
        scanf("%49s %29s %d %d", party[i].nome, party[i].classe, &party[i].nivel, &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    int i;
    for (i = 0; i < num_membros; i++) {
        printf("%s (%s) - Nivel: %d | HP: %d\n", party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}

void libera_party(Personagem* party) {
    free(party);
}