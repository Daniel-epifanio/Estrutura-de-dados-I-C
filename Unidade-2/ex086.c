/*Contexto: Supondo um RPG tático, a ordem dos heróis na formação de batalha é crucial. Heróis na frente absorvem mais dano, enquanto os de trás ficam protegidos. O jogador pode recrutar novos heróis e precisa posicioná-los estrategicamente na formação existente.

Uma das táticas mais importantes é a proteção de um personagem-chave (o 'VIP'). Ao recrutar um 'Guarda-Costas', o jogador deve poder inseri-lo na formação exatamente antes do VIP para interceptar ataques direcionados.

Tarefa: 
Você deve criar um programa em C que gerencie a formação de batalha de uma equipe usando uma lista encadeada. O programa deve apresentar um menu com opções para adicionar heróis e, mais importante, implementar a funcionalidade de 'Inserir Antes'.

Requisitos:
Estrutura de Dados:
Crie uma struct Heroi com id (inteiro) e nome (string).
Implemente uma lista encadeada simples para armazenar os heróis da formação.
Menu de Opções:
1 - Adicionar Herói no Fim da Formação: Adiciona um novo herói ao final da lista.
2 - Adicionar Guarda-Costas (Inserir Antes): Pede os dados de um novo herói (o guarda-costas) e, em seguida, pede o id de um herói já existente (o VIP). O guarda-costas deve ser inserido na lista imediatamente antes do VIP.
3 - Mostrar Formação: Exibe a lista de heróis na ordem atual.
4 - Sair.
Lógica de Inserção:
A função inserir_antes deve lidar com os casos: lista vazia, o 'VIP' ser o primeiro da lista, e o 'VIP' não ser encontrado.
Se o 'VIP' não for encontrado, o programa deve informar o usuário e não realizar a inserção.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
}Heroi;

struct No{
    Heroi dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== FORMACAO DE HEROIS ===\n");
    printf("1 - Adicionar heroi no fim da formacao\n");
    printf("2 - Adicionar guarda-costas (inserir antes)\n");
    printf("3 - Mostrar formacao\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(Heroi *ph){
    scanf(" %d %s", &ph->id, ph->nome);
}

void inserir_inicio(Lista *plista, Heroi dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Heroi dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

struct No* inserir_antes(Lista *plista, Heroi dado, int id){
    if (plista->inicio == NULL){
        return NULL;
    }

    else if (plista->inicio->dado.id == id){
        struct No* novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
        return novo;
    }

    else{
        struct No* pi;
        for (pi = plista->inicio; pi->prox != NULL && pi->prox->dado.id != id; pi = pi->prox);
    
        if (pi->prox == NULL){
            return NULL;
        }
    
        else{
            struct No *novo = (struct No *) malloc(sizeof(struct No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return novo;
        }
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== FORMACAO ATUAL ===\n");
    if (lista.inicio == NULL){
        printf("Nenhum heroi na formacao.\n");
    }
    else{
        for (pi = lista.inicio; pi != NULL; pi = pi->prox){
            printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
        }
    }
    printf("======================\n");
}


int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Heroi h;
            printf("\n--- Adicionar heroi no fim ---\n");
            ler(&h);
            inserir_fim(&lista, h);
            printf("\nHeroi adicionado com sucesso!\n");
        }
        else if (op == 2){
            Heroi guarda_costas;
            printf("\n--- Adicionar guarda-costas ---\n");
            printf("Dados do guarda-costas:\n");
            ler(&guarda_costas);
            int id_vip;
            printf("\nInforme o ID do VIP (heroi a ser protegido): ");
            scanf("%d", &id_vip);
            struct No * resultado = inserir_antes(&lista, guarda_costas, id_vip);
            if (resultado == NULL){
                printf("\nNao foi possivel inserir o guarda-costas. Heroi com ID %d nao encontrado.\n", id_vip);
            }
            else{
                printf("\nGuarda-costas posicionado com sucesso!\n");
            }
        }
        else if (op == 3){
            mostrar(lista);
        }
    } while (op != 4);

    printf("Programa Finalizado!");
    
    return 0;
}