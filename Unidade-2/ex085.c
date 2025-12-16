/*
Contexto: Supondo um RPG, o jogador está em uma missão para reforjar uma arma lendária. 
Para isso, ele coleta diversos 'Fragmentos de Poder', que são armazenados em uma lista 
de inventário. Ocasionalmente, o jogador encontra um 'Catalisador Rúnico', um item 
especial que precisa ser combinado com um fragmento específico para amplificar seu 
poder. Para a mecânica do jogo funcionar, o sistema de inventário deve registrar o 
catalisador imediatamente após o fragmento com o qual ele se relaciona.

Tarefa: 
Você deve criar um programa em C que gerencie o inventário de itens de missão do jogador. 
O programa deve apresentar um menu com opções para adicionar itens, sendo a principal delas 
a capacidade de inserir um 'Catalisador Rúnico' após um 'Fragmento de Poder' já existente, 
identificado por seu ID.

Requisitos:
Defina uma struct para representar um Item, contendo um id (inteiro) e um nome (string).
Utilize uma lista encadeada para armazenar os itens do inventário.
Implemente um menu com as seguintes opções:
1 - Inserir item no início (para itens comuns).
2 - Inserir item no fim (para itens comuns).
3 - Inserir catalisador após um fragmento (o foco da tarefa).
4 - Mostrar inventário.
5 - Sair.
Para a opção 3, o programa deve primeiro solicitar os dados do novo item (catalisador) e, em seguida, pedir o id do fragmento após o qual o catalisador deve ser inserido.
Se o id do fragmento não for encontrado na lista, o programa deve informar ao usuário que a inserção não foi possível e não deve adicionar o catalisador ao inventário.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
}Item;

struct No{
    Item dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== INVENTARIO ===\n");
    printf("1 - Inserir item no inicio\n");
    printf("2 - Inserir item no fim\n");
    printf("3 - Inserir catalisador apos fragmento\n");
    printf("4 - Mostrar inventario\n");
    printf("5 - Sair\n");
    printf("==================\n");

}

void ler(Item *pi){
    scanf(" %d %s", &pi->id, pi->nome);
}

void inserir_inicio(Lista *plista, Item dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Item dado){
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

struct No* inserir_apos(Lista *plista, Item dado, int id){
    struct No * pi;
    for (pi = plista->inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    if (pi == NULL){
        return NULL;
    }
    else{
        struct No *novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;  
        novo->prox = pi->prox;
        pi->prox = novo;
        return novo;
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== INVENTARIO ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    printf("==================\n");
}

struct No* pesquisar(Lista lista, int id){
    struct No * pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    return pi;
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Item item;
            printf("\n--- Inserir item no inicio ---\n");
            ler(&item);
            inserir_inicio(&lista, item);
            printf("\nItem adicionado com sucesso!\n");
        }
        else if (op == 2){
            Item item;
            printf("\n--- Inserir item no fim ---\n");
            ler(&item);
            inserir_fim(&lista, item);
            printf("\nItem adicionado com sucesso!\n");
        }
        else if (op == 3){
            Item catalisador;
            printf("\n--- Inserir catalisador apos fragmento ---\n");
            printf("Dados do catalisador:\n");
            ler(&catalisador);
            int id_fragmento;
            printf("\nInforme o ID do fragmento para inserir o catalisador apos: ");
            scanf("%d", &id_fragmento);
            struct No * resultado = inserir_apos(&lista, catalisador, id_fragmento);
            if (resultado == NULL){
                printf("\nNao foi possivel inserir o catalisador. Fragmento com ID %d nao encontrado.\n", id_fragmento);
            }
            else{
                printf("\nCatalisador inserido com sucesso apos o fragmento!\n");
            }
        }
        else if (op == 4){
            mostrar(lista);
        }
    } while (op != 5);

    printf("Programa Encerrado!");
    
    return 0;
}