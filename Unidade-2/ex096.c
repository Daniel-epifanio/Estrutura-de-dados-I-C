/*Contexto: Em um RPG, o jogador mantém um registro de cada monstro que derrotou. Este registro, implementado como uma lista encadeada, cresce dinamicamente à medida que o jogador explora o mundo. Para analisar os inimigos e preparar estratégias, o jogador precisa de uma forma de organizar seu bestiário.

Tarefa: 
Você deve criar um programa em C que permita ao jogador adicionar novos monstros ao seu bestiário e, crucialmente, ordenar essa lista com base no "Nível de Ameaça" de cada monstro. O nível de ameaça é um valor inteiro que representa o quão perigoso é o monstro.

Requisitos:
Defina uma struct Monstro que contenha um id (inteiro representando o nível de ameaça) e um nome (string).
Utilize uma estrutura de lista encadeada para armazenar os registros dos monstros.
Implemente uma função adicionarMonstro que insira um novo monstro no final da lista.
Implemente a função ordenarBestiario, que utiliza o algoritmo Bubble Sort (exatamente como visto na aula) para ordenar a lista de monstros em ordem crescente de id.
Implemente uma função mostrarBestiario para exibir todos os monstros da lista, mostrando seu ID e nome.
Crie um menu principal que permita ao usuário: adicionar um monstro, ordenar o bestiário, mostrar o bestiário e sair.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Monstro;

struct No {
    Monstro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Bestiario de Monstros ===\n");
    printf("1 - Adicionar monstro\n");
    printf("2 - Ordenar bestiario\n");
    printf("3 - Mostrar bestiario\n");
    printf("4 - Sair\n");
    printf("==============================\n");
}

void lerMonstro(Monstro *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
}

void adicionarMonstro(Lista *plista, Monstro dado) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
        }
        pi->prox = novo;
    }
}

void mostrarBestiario(Lista lista) {
    struct No *pi;
    printf("\n=== Bestiario ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(bestiario vazio)\n");
    }
    printf("=================\n\n");
}

void ordenarBestiario(Lista *plista) {
    struct No *pi;
    struct No *pj;
    struct No *pfim = NULL;
    
    if (plista->inicio == NULL) {
        printf("Lista vazia, nada para ordenar\n");
        return;
    }
    
    for (pi = plista->inicio; pi->prox != pfim; pi = plista->inicio) {
        for (pj = plista->inicio; pj->prox != pfim; pj = pj->prox) {
            if (pj->dado.id > pj->prox->dado.id) {
                // Troca os dados dos nós
                Monstro temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
    printf("Bestiario ordenado com sucesso!\n");
}

void liberarLista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Monstro m;
            printf("Informe o ID (nivel de ameaca) e nome do monstro:\n");
            lerMonstro(&m);
            adicionarMonstro(&lista, m);
            printf("Monstro adicionado ao bestiario!\n");
        }

        if (op == 2) {
            ordenarBestiario(&lista);
        }

        if (op == 3) {
            mostrarBestiario(lista);
        }
    }

    liberarLista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}