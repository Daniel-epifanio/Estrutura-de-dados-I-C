/*Contexto: Em um RPG de gerenciamento, você é o líder de uma guilda de mercenários. Para administrar eficientemente a guilda, você precisa saber a todo momento quantos mercenários estão sob seu comando. Essa informação é crucial para calcular a folha de pagamento, determinar se a guilda tem força suficiente para aceitar contratos perigosos ou se há vagas para recrutar novos membros. O registro da sua guilda é mantido como uma lista encadeada.

Tarefa: 
Você deve completar um programa que gerencia o registro de mercenários. A estrutura básica do programa, incluindo a inserção e exibição de mercenários, já foi fornecida. Sua tarefa é implementar a função tamanho, que percorre a lista encadeada e retorna o número total de mercenários (nós) registrados.

Requisitos:
A função deve se chamar tamanho e retornar um int.
A função deve receber a lista de mercenários como parâmetro.
A função deve percorrer a lista desde o início até o fim.
A função deve usar um contador para rastrear o número de nós.
Se a lista estiver vazia, a função deve retornar 0.
O programa principal deve ter uma opção no menu para chamar sua função e exibir o tamanho atual da guilda.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("=== Guilda de Mercenarios ===\n");
    printf("1 - Contratar mercenario\n");
    printf("2 - Mostrar todos\n");
    printf("3 - Verificar tamanho da guilda\n");
    printf("4 - Sair\n");
    printf("=============================\n");
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

int tamanho(Lista lista) {
    int contador = 0;
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        contador++;
    }
    return contador;
}

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(guilda vazia)\n");
    }
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
            printf("Mercenario contratado com sucesso\n");
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            int tam = tamanho(lista);
            printf("Tamanho atual da guilda: %d mercenario(s)\n", tam);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}