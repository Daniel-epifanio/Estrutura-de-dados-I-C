/*Problema: Visualizando a Pilha de Ações.

Contexto: Na aula anterior, criamos a base para a pilha de comandos do Arcanista. Agora, antes de executar os feitiços, o Arcanista precisa de uma forma de revisar a sequência de comandos que ele enfileirou. Isso é crucial para que o jogador possa verificar se a ordem das ações está correta, especialmente porque o último comando dado será o primeiro a ser executado (LIFO).

Tarefa: 
Sua tarefa é estender o programa anterior. Você adicionará a funcionalidade de visualizar todos os feitiços atualmente na pilha de comandos. A exibição deve refletir a ordem de execução, ou seja, do topo para a base da pilha.

Requisitos:
Utilize o código da atividade anterior como base.
Modifique o menu para incluir uma nova opção: 2: Mostrar Pilha de Comandos. A opção de sair deve se tornar a 3.
Implemente uma função void mostrar_pilha(Pilha *p) que percorre e imprime todos os feitiços da pilha, do topo para a base.
A impressão deve ser clara, mostrando o nome e o custo de mana de cada feitiço.
Se a pilha estiver vazia, a função deve exibir uma mensagem como "A pilha de comandos esta vazia.".
O programa deve continuar executando até que o usuário escolha a nova opção de sair.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int custo_mana;
} Feitico;

struct no{
    Feitico dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
} Pilha;

void menu(){
    printf("==== Comandos de Feiticos ====\n");
    printf("1 - Adicionar feitiço\n");
    printf("2 - Mostrar pilha de comandos\n");
    printf("3 - Finalizar e sair\n");
    printf("===============================\n");
}

void empilhar(Pilha *ppilha, Feitico dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

void mostrar_pilha(Pilha *p){
    if (p->topo == NULL) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }
    printf("\nTopo ->\n");
    No *pi;
    for (pi = p->topo; pi != NULL; pi = pi->prox){
        printf("Feitiço: %s | Mana: %d\n", pi->dado.nome, pi->dado.custo_mana);
    }
    printf("<- Base\n\n");
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            Feitico f;
            printf("Informe o nome do feitiço:\n");
            scanf("%99s", f.nome);
            printf("Informe o custo de mana:\n");
            scanf("%d", &f.custo_mana);
            empilhar(&pilha, f);
        }
        else if (op == 2){
            mostrar_pilha(&pilha);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}