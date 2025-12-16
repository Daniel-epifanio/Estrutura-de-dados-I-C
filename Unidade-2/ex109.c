/*Problema: Estrutura de Dados Fila: Implementação da Operação de Exibição (Travessia)

Contexto: Continuando o desenvolvimento do nosso sistema de matchmaking para o jogo MOBA, agora que os jogadores já podem entrar na fila, é essencial ter uma forma de visualizar quem está esperando e em que ordem. Isso é útil tanto para os administradores do sistema quanto para fornecer uma estimativa de posição para os próprios jogadores.

Tarefa: 
Modifique o programa anterior para adicionar a funcionalidade de exibir todos os jogadores que estão atualmente na fila de matchmaking, na ordem correta em que entraram (do primeiro ao último).

Requisitos:
Implemente uma nova função void mostrar(Fila *f).
Dentro desta função, utilize um ponteiro auxiliar (No *aux) para percorrer a fila, começando pelo inicio.
A função deve iterar por todos os nós até que o ponteiro auxiliar se torne NULL. Em cada iteração, ela deve imprimir os dados (ID e nickname) do jogador contido no nó atual.
A função deve ser capaz de lidar com uma fila vazia. Se a fila não tiver nenhum jogador, ela deve imprimir uma mensagem informativa, como "A fila de matchmaking esta vazia.".
Modifique o menu no programa principal (main) para incluir uma nova opção para "Mostrar Fila". A opção de "Sair" deve ser a última.
- Exemplo de novo menu:
1. Adicionar Jogador na Fila
2. Mostrar Fila
3. Sair
Atualize a estrutura switch na função main para chamar a sua nova função mostrar quando a opção correspondente for selecionada.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[100];
} Jogador;

struct no{
    Jogador dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;

void ler_jogador(Jogador *j){
    printf("Informe o ID e o nickname:\n");
    scanf("%d %99s", &j->id, j->nickname);
}

void inserir(Fila *pfila, Jogador dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = NULL;
    if (pfila->inicio == NULL){
        pfila->inicio = novo;
        pfila->fim = novo;
    }
    else{
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
}

void mostrar(Fila *f){
    if (f->inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No *aux;
    for (aux = f->inicio; aux != NULL; aux = aux->prox){
        printf("ID: %d | Nick: %s\n", aux->dado.id, aux->dado.nickname);
    }
}

void menu(){
    printf("=== Fila de Jogadores ===\n");
    printf("1 - Adicionar Jogador na Fila\n");
    printf("2 - Mostrar Fila\n");
    printf("3 - Sair\n");
    printf("========================\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(&fila);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}