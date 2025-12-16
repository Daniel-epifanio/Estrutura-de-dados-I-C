/*Contexto: Em um RPG, missões (quests) são compostas por uma série de etapas que devem ser completadas em sequência. O sistema de missões é implementado como uma lista encadeada, onde cada nó representa uma etapa da missão (com um ID único e uma descrição). Às vezes, o jogador pode encontrar um atalho ou usar uma habilidade especial que completa uma etapa e, como consequência, a etapa anterior se torna irrelevante e precisa ser removida do diário de missões para evitar confusão. Por exemplo, se a missão é 'Coletar Chave' -> 'Abrir Portão', e o jogador usa uma habilidade de arrombamento para abrir o portão, a etapa 'Coletar Chave' não é mais necessária.

Tarefa:
Sua tarefa é expandir um programa de gerenciamento de missões em C que utiliza uma lista encadeada. Você deve implementar a funcionalidade crucial: deletar a etapa que vem ANTES de uma etapa específica, identificada por seu ID.

Requisitos:
O programa deve usar uma struct para representar uma Etapa de missão, contendo um int id e um char descricao[100].
A lista encadeada deve ser gerenciada através de struct No e struct Lista.
O programa deve apresentar um menu com as seguintes opções:
- Inserir etapa no fim da lista.
- Mostrar todas as etapas da missão.
- Deletar etapa ANTES de um ID específico (o foco do problema).
- Sair.
A função deletar_antes deve tratar corretamente todos os casos especiais discutidos na aula:
- A lista está vazia.
- A etapa de referência é a primeira da lista (não há etapa anterior para deletar).
- A etapa a ser deletada é a primeira da lista (a etapa de referência é a segunda).
- A etapa a ser deletada está no meio da lista (caso geral).
- A etapa de referência informada não existe na lista.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char descricao[100];
} Etapa;

struct No {
    Etapa dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Missao: Etapas ===\n");
    printf("1 - Inserir etapa no fim\n");
    printf("2 - Mostrar todas as etapas\n");
    printf("3 - Deletar etapa ANTES de um ID\n");
    printf("4 - Sair\n");
    printf("======================\n");
}

void ler_etapa(Etapa *pe) {
    scanf("%d %99[^\n]", &pe->id, pe->descricao);
}

void inserir_fim(Lista *plista, Etapa dado) {
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
        printf("%d %s\n", pi->dado.id, pi->dado.descricao);
    }
    if (lista.inicio == NULL) {
        printf("(lista vazia)\n");
    }
}

void deletar_antes(Lista *plista, int id_ref) {

    if (plista->inicio == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    if (plista->inicio->dado.id == id_ref) {
        printf("A etapa %d eh a primeira; nao ha etapa anterior para deletar\n", id_ref);
        return;
    }

    if (plista->inicio->prox != NULL && plista->inicio->prox->dado.id == id_ref) {
        struct No *remover = plista->inicio;
        plista->inicio = remover->prox;
        free(remover);
        printf("Etapa antes de %d removida (era a primeira)\n", id_ref);
        return;
    }

    struct No *anterior = plista->inicio;
    struct No *deletar = plista->inicio->prox;
    struct No *referencia = deletar->prox;

    while (referencia != NULL && referencia->dado.id != id_ref) {
        anterior = deletar;
        deletar = referencia;
        referencia = referencia->prox;
    }

    if (referencia == NULL) {
        printf("Etapa de referencia %d nao encontrada\n", id_ref);
        return;
    }

    anterior->prox = deletar->prox;
    free(deletar);
    printf("Etapa antes de %d removida\n", id_ref);
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
        getchar(); 

        if (op == 1) {
            Etapa e;
            printf("Informe ID e descricao da etapa:\n");
            ler_etapa(&e);
            inserir_fim(&lista, e);
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            int id_ref;
            printf("Informe o ID de referencia (deletar etapa ANTES dele):\n");
            scanf("%d", &id_ref);
            deletar_antes(&lista, id_ref);
            mostrar(lista);
        }
    }
    liberar_lista(&lista);
    return 0;
}