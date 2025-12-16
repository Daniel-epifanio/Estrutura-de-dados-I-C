/*Contexto: Em um RPG online, os jogadores podem gerenciar os membros de sua guilda. Uma funcionalidade importante, mas que precisa de cuidado, é a capacidade de um líder de guilda corrigir ou alterar o nome de um membro no registro oficial. O registro da guilda é implementado como uma lista encadeada, onde cada membro é identificado por um ID numérico único.

Tarefa: 
Você precisa implementar a função que permite essa alteração. O líder da guilda informará o ID do membro cujo nome precisa ser mudado e, em seguida, fornecerá o novo nome. O sistema deve encontrar o membro na lista e atualizar seu nome.

Requisitos:
Defina uma struct para representar um Membro com um id (int) e um nome (char[100]).
Crie uma lista encadeada para armazenar os membros da guilda.
Implemente as funções básicas: inserir_fim para adicionar novos membros e mostrar_lista para exibir o registro atual.
O foco principal é implementar uma função alterar_nome(Lista *lista, int id, char novo_nome[]).
Dentro de alterar_nome, você deve primeiro usar uma função de busca (pesquisar) para encontrar o nó do membro pelo id fornecido.
Se o membro for encontrado, use strcpy() para atualizar seu nome.
Se o membro não for encontrado, exiba uma mensagem de erro apropriada.
Crie um menu simples na função main que permita ao usuário adicionar membros, mostrar a lista, alterar o nome de um membro e sair.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

struct No {
    Membro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Registro da Guilda ===\n");
    printf("1 - Adicionar membro\n");
    printf("2 - Mostrar todos os membros\n");
    printf("3 - Alterar nome de membro\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler_membro(Membro *pm) {
    scanf("%d", &pm->id);
    getchar(); 
    fgets(pm->nome, 100, stdin);
    pm->nome[strcspn(pm->nome, "\n")] = 0;
}

void inserir_fim(Lista *plista, Membro dado) {
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

struct No* pesquisar(Lista lista, int id) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox) {
    }
    return pi;
}

void mostrar_lista(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(lista vazia)\n");
    }
}

void alterar_nome(Lista *plista, int id, char novo_nome[]) {
    struct No *pi = pesquisar(*plista, id);
    if (pi == NULL) {
        printf("Membro com ID %d nao encontrado\n", id);
    } else {
        strcpy(pi->dado.nome, novo_nome);
        printf("Nome atualizado com sucesso\n");
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
        getchar(); 

        if (op == 1) {
            Membro m;
            printf("Informe o ID do membro:\n");
            ler_membro(&m);
            inserir_fim(&lista, m);
            printf("Membro adicionado com sucesso\n");
        }

        if (op == 2) {
            mostrar_lista(lista);
        }

        if (op == 3) {
            int id;
            printf("Informe o ID do membro:\n");
            scanf("%d", &id);
            getchar(); 
            printf("Informe o novo nome:\n");
            char novo_nome[100];
            fgets(novo_nome, 100, stdin);
            novo_nome[strcspn(novo_nome, "\n")] = 0; 
            alterar_nome(&lista, id, novo_nome);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}