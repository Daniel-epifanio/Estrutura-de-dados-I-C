/*Contexto: Em um RPG, você precisa gerenciar o grupo (ou 'party') de aventureiros que acompanha o jogador principal. Novos heróis podem se juntar ao grupo a qualquer momento, e o líder do grupo precisa de uma forma rápida de verificar quem está atualmente na equipe. A tradição local dita que o recém-chegado sempre assume a liderança temporária, ficando na frente do grupo.

Tarefa:
Crie um programa em C que simule o gerenciamento deste grupo de aventureiros. O programa deve apresentar um menu com as seguintes opções:
Adicionar Aventureiro: Solicita o ID (um número inteiro) e o nome do novo aventureiro. Este aventureiro deve ser adicionado no início da lista (do grupo).
Mostrar Grupo: Exibe a lista de todos os aventureiros atualmente no grupo, na ordem em que estão (o mais recente primeiro).
Sair: Encerra o programa.

Requisitos:
Utilize uma lista encadeada para armazenar os aventureiros.
Cada aventureiro deve ser representado por uma struct contendo um ID (inteiro) e um nome (string).
A inserção de um novo aventureiro deve ser sempre no início da lista.
A função para mostrar o grupo deve percorrer a lista do início ao fim, imprimindo a ID e o nome de cada membro.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} aventureiro;

struct No{
    aventureiro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Adicionar aventureiro\n");
    printf("2 - Mostrar grupo\n");
    printf("3 - Sair\n");
    printf("=========================\n");
}

void ler(aventureiro *pa){
    scanf("%d %49s", &pa->id, pa->nome);  // lê id e depois nome, limitando 49 chars
}

void inserir_inicio(Lista *plista, aventureiro dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void mostrar(Lista lista){
    struct No *pi = lista.inicio;
    while (pi != NULL){
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
        pi = pi->prox;
    }
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    menu();
    scanf("%d", &op);
    
    while (op != 3){
        if (op == 1){
            aventureiro a;
            ler(&a);
            inserir_inicio(&lista, a);
        }
        else if (op == 2){
            mostrar(lista);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Operação Finalizada!");
    
    return 0;
}