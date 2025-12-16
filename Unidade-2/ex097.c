/*Problema: Implementar a funcionalidade de salvar o estado de uma guilda de jogadores em um arquivo binário.
Contexto: Em um jogo de RPG online (MMORPG), a capacidade de salvar o estado de uma 'guilda' (um grupo de jogadores) é crucial. Quando o servidor precisa ser reiniciado para manutenção, ele deve salvar todos os registros de guildas para que possam ser recarregados quando o servidor voltar a funcionar. Armazenar esses dados em um formato binário compacto e eficiente é a prática padrão da indústria para garantir rapidez e segurança.

Tarefa: 
Sua missão é implementar a funcionalidade de 'salvar' para o registro de uma guilda, que é gerenciado como uma lista encadeada. Você irá estender um programa existente que já manipula a lista de membros, adicionando uma nova opção no menu para escrever toda a lista de membros em um arquivo binário chamado guild_roster.bin.

Requisitos:
O programa deve gerenciar uma lista encadeada de Membro structs, onde cada membro possui um ID (inteiro) e um nome (string).
Crie uma nova função, salvar_guild_arquivo(Lista lista), que recebe a lista de membros como parâmetro.
Dentro desta função, abra um arquivo chamado guild_roster.bin em modo de escrita binária ("wb").
A função deve percorrer a lista encadeada do início ao fim.
Para cada nó da lista, utilize a função fwrite() para escrever a struct Membro (os dados do jogador) no arquivo.
É fundamental que apenas os dados do membro sejam salvos. Os ponteiros prox que formam a estrutura da lista não devem ser escritos no arquivo.
Após escrever todos os membros, o arquivo deve ser devidamente fechado com fclose().
Integre a chamada a esta nova função no menu principal do programa.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Membro;

struct No {
    Membro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Roster da Guilda ===\n");
    printf("1 - Adicionar membro\n");
    printf("2 - Mostrar todos os membros\n");
    printf("3 - Salvar roster em arquivo\n");
    printf("4 - Sair\n");
    printf("========================\n");
}

void ler_membro(Membro *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
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

void mostrar(Lista lista) {
    struct No *pi;
    printf("\n=== Membros da Guilda ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(roster vazio)\n");
    }
    printf("=========================\n\n");
}

void salvar_guild_arquivo(Lista lista) {
    FILE *file = fopen("./../arquivos/guild_roster.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }
    
    struct No *pi;
    int contador = 0;
    
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        
        fwrite(&pi->dado, sizeof(Membro), 1, file);
        contador++;
    }
    
    fclose(file);
    printf("Roster salvo com sucesso! %d membro(s) gravado(s) em guild_roster.bin\n", contador);
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
            Membro m;
            printf("Informe o ID e nome do membro:\n");
            ler_membro(&m);
            inserir_fim(&lista, m);
            printf("Membro adicionado ao roster!\n");
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            salvar_guild_arquivo(lista);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}