/*Problema: Consultando o Próximo Feitiço (Top/Peek)

Contexto: O Arcanista agora domina a adição, execução e visualização de sua pilha de comandos. No entanto, ser um bom mago não é apenas sobre poder, mas também sobre estratégia. Antes de comprometer-se a lançar um feitiço (removendo-o da pilha com pop), ele gostaria de espiar qual é o próximo comando. Isso permite que ele verifique se tem mana suficiente ou se a situação tática mudou, tornando outro feitiço mais apropriado, tudo isso sem alterar a sequência de comandos já planejada.

Tarefa:
Sua missão é implementar a operação top (também conhecida como peek). Você criará uma função que permite ao Arcanista ver qual feitiço está no topo da pilha de comandos, mas sem removê-lo.

Requisitos:
Utilize o código da atividade anterior como base.
Implemente uma função Feitico top(Pilha *p) que:
- Verifica se a pilha está vazia usando a função vazia().
- Se não estiver vazia, retorna a struct Feitico que está no topo, mas não modifica a pilha (não usa free() e não altera o ponteiro topo).
- Se a pilha estiver vazia, exibe uma mensagem de erro e retorna uma struct Feitico indicando falha (ex: custo_mana = -1).
Modifique o menu para incluir a nova opção: 4: Consultar Próximo Feitiço (Top). As opções subsequentes devem ser reenumeradas.
No main, ao escolher a nova opção 4, chame a função top e, se a operação for bem-sucedida, exiba os detalhes do feitiço consultado (nome e custo de mana).
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
    printf("3 - Remover (pop)\n");
    printf("4 - Consultar próximo feitiço (top)\n");
    printf("5 - Verificar status da pilha\n");
    printf("6 - Finalizar e sair\n");
    printf("===============================\n");
}

void empilhar(Pilha *ppilha, Feitico dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

int vazia(Pilha *p){
    return p->topo == NULL ? 1 : 0;
}

Feitico pop(Pilha *p){
    Feitico falha;
    strcpy(falha.nome, "");
    falha.custo_mana = -1;
    if (vazia(p)){
        printf("A pilha de comandos esta vazia!\n");
        return falha;
    }
    No *rem = p->topo;
    Feitico valor = rem->dado;
    p->topo = rem->prox;
    free(rem);
    return valor;
}

Feitico top(Pilha *p){
    Feitico falha;
    strcpy(falha.nome, "");
    falha.custo_mana = -1;
    if (vazia(p)){
        printf("A pilha de comandos esta vazia!\n");
        return falha;
    }
    return p->topo->dado;
}

void mostrar_pilha(Pilha *p){
    if (vazia(p)){
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
    while (op != 6){
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
        else if (op == 3){
            (void)pop(&pilha);
        }
        else if (op == 4){
            Feitico f = top(&pilha);
            if (f.custo_mana != -1){
                printf("Próximo feitiço: %s | Mana: %d\n", f.nome, f.custo_mana);
            }
        }
        else if (op == 5){
            if (vazia(&pilha)){
                printf("A pilha de comandos está vazia.\n");
            } else {
                printf("A pilha de comandos possui feitiços pendentes.\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}