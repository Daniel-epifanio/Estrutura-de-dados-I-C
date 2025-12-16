/*Problema: Implementar a função demitir_todos_mercenarios que libera toda a memória alocada para uma lista de mercenários em um jogo.

Contexto: Em um jogo de estratégia e aventura, o jogador gerencia uma companhia de mercenários. Cada mercenário contratado é adicionado a uma lista dinâmica (uma lista encadeada). No entanto, se o jogador ficar sem ouro para pagar os salários, a companhia inteira se dissolve. Nesse momento, o sistema do jogo precisa limpar eficientemente o registro, liberando a memória de todos os mercenários contratados para evitar vazamentos de memória (memory leaks) que poderiam travar o jogo.

Tarefa:
Você deve criar um programa em C que simule o gerenciamento dessa companhia. O programa deve ter um menu com as seguintes opções:
1. Contratar mercenário (inserir no fim da lista).
2. Exibir companhia (mostrar a lista de mercenários).
3. Declarar falência (deletar a lista inteira).
4. Sair.
Requisitos:
Use uma struct para representar um mercenário, que deve conter um id (inteiro) e um nome (string).
A lista de mercenários deve ser uma lista encadeada simples.
A função demitir_todos_mercenarios deve percorrer a lista, liberando a memória de cada nó com free() até que a lista esteja completamente vazia.
O programa deve confirmar que a lista está vazia após a função de demissão ser chamada.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Mercenario;

struct No {
    Mercenario dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Gerenciador de Mercenarios ===\n");
    printf("1 - Contratar mercenario (inserir no fim)\n");
    printf("2 - Mostrar todos os mercenarios\n");
    printf("3 - Demitir todos os mercenarios\n");
    printf("4 - Sair\n");
    printf("==================================\n");
}

void ler_mercenario(Mercenario *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
}

void inserir_fim(Lista *plista, Mercenario dado) {
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

void demitir_todos_mercenarios(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *temp = pi;
        pi = pi->prox;
        free(temp);
    }
    plista->inicio = NULL;
    printf("Todos os mercenarios foram demitidos\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Mercenario m;
            printf("Informe ID e nome do mercenario:\n");
            ler_mercenario(&m);
            inserir_fim(&lista, m);
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            demitir_todos_mercenarios(&lista);
            printf("Confirmacao - Lista apos demissao:\n");
            mostrar(lista);
        }
    }
    demitir_todos_mercenarios(&lista);
    printf("Programa finalizado...\n");
    return 0;
}