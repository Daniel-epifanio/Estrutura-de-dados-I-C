/*Contexto: Em um jogo de luta de ritmo acelerado, os jogadores executam sequências de movimentos chamadas combos. O sistema do jogo precisa rastrear os últimos movimentos realizados para determinar se um ataque especial pode ser ativado. O movimento mais recente é sempre o mais importante e deve ser acessado rapidamente.

Tarefa: 
Você deve criar um sistema que registre os movimentos do jogador. Cada movimento possui um ID numérico único e um nome (ex: 'Soco Rápido', 'Chute Giratório', 'Defesa'). À medida que o jogador executa novos movimentos, eles devem ser adicionados ao início de uma lista que representa o 'histórico do combo'.

Requisitos:
Crie uma struct, usando typedef, chamada Movimento para armazenar o ID (int) e o nome (char nome[50]) de um golpe.
Crie as structs necessárias para implementar uma lista encadeada (No e Lista).
Implemente um programa principal (main) que exiba um menu com as seguintes opções:
1: Inserir novo movimento no início do combo.
2: Sair.
O programa deve continuar executando até que o usuário escolha a opção '2'.
Ao escolher a opção '1', o programa deve ler o ID e o nome de um novo movimento e inseri-lo no início da lista encadeada.
O foco do exercício é a inserção. Não é necessário implementar uma função para imprimir a lista.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Movimento;

struct No {
    Movimento dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void ler(Movimento *pm) {
    scanf("%d %s", &pm->id, pm->nome);
}

void menu() {
    printf("========== Escolha uma opção ==========\n");
    printf("1 - Inserir novo movimento no início do combo\n");
    printf("2 - Sair\n");
    printf("=======================================\n");
}

void inserir_inicio(Lista *lista, Movimento dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    menu();
    scanf("%d", &op);
    
    while (op != 2) {
        if (op == 1) {
            Movimento m;
            ler(&m);
            inserir_inicio(&lista, m);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Operação Finalizada!\n");
    return 0;
}