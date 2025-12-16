/*Contexto: Supondo que em um jogo de RPG e gerenciamento, você é o líder de uma guilda de heróis. O salão da guilda tem uma capacidade limitada, e às vezes, para dar lugar a novos talentos ou porque um herói decide se aposentar, você precisa remover um membro do seu registro ativo. O registro da guilda é implementado como uma lista encadeada, onde cada herói é identificado por um ID numérico único.

Tarefa: 
Você deve estender um programa de gerenciamento de guilda existente. Sua principal tarefa é implementar a função dispensar_heroi(), que recebe a lista de heróis e o ID do herói a ser removido. A função deve encontrar o herói com o ID correspondente na lista e removê-lo, liberando a memória alocada para ele e garantindo que a lista permaneça conectada corretamente.

Requisitos:
Defina uma struct Heroi com os campos: id (inteiro) e nome (string).
Use uma lista encadeada para armazenar os heróis da guilda.
Implemente a função void dispensar_heroi(Lista *lista, int id);.
Sua função deve tratar todos os casos possíveis:
Tentar remover de uma lista vazia.
Remover o primeiro herói da lista.
Remover um herói que está no meio ou no final da lista.
Tentar remover um herói com um ID que não existe na lista.
O programa principal deve ter um menu simples para permitir ao usuário: (1) Adicionar um herói, (2) Mostrar todos os heróis, (3) Dispensar um herói por ID, e (4) Sair. Após cada operação de dispensa, a lista atualizada deve ser exibida.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Heroi;

struct No {
    Heroi dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu(){
    printf("=== Guilda de Herois ===\n");
    printf("1 - Adicionar heroi\n");
    printf("2 - Mostrar herois\n");
    printf("3 - Dispensar heroi por ID\n");
    printf("4 - Sair\n");
    printf("========================\n");
}

void ler_heroi(Heroi *ph) {
    scanf("%d %49s", &ph->id, ph->nome);
}

void inserir_fim(Lista *plista, Heroi dado) {
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

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(lista vazia)\n");
    }
}

struct No *pesquisar(Lista lista, int id) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox) {
    }
    return pi;
}

void dispensar_heroi(Lista *plista, int id) {
    if (plista->inicio == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    if (plista->inicio->dado.id == id) {
        struct No *remover = plista->inicio;
        plista->inicio = remover->prox;
        free(remover);
        printf("Heroi %d removido do inicio\n", id);
        return;
    }

    struct No *anterior = plista->inicio;
    struct No *pi = plista->inicio->prox;
    while (pi != NULL && pi->dado.id != id) {
        anterior = pi;
        pi = pi->prox;
    }

    if (pi == NULL) {
        printf("Heroi %d nao encontrado\n", id);
        return;
    }

    anterior->prox = pi->prox;
    free(pi);
    printf("Heroi %d removido\n", id);
}

void liberar_lista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Heroi h;
            printf("Informe ID e nome do heroi:\n");
            ler_heroi(&h);
            inserir_fim(&lista, h);
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            int id;
            printf("Informe o ID para dispensar:\n");
            scanf("%d", &id);
            dispensar_heroi(&lista, id);
            mostrar(lista);
        }
    }
    liberar_lista(&lista);
    return 0;
}