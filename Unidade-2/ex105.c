/*Problema: Revertendo a Estratégia (Inverter Pilha)

Contexto: O Arcanista, em meio a uma batalha, percebe que sua estratégia inicial foi equivocada. Os feitiços que ele preparou primeiro (e que agora estão no fundo da pilha) são exatamente os que ele precisa lançar agora. Os comandos mais recentes, no topo da pilha, são menos importantes no momento. Ele precisa de um meta-feitiço, um "Encantamento de Reversão Temporal", que inverta toda a sua sequência de comandos planejada, fazendo com que o primeiro feitiço pensado se torne o próximo a ser lançado.

Tarefa:
Sua tarefa é implementar esta poderosa habilidade. Você criará uma função que inverte a ordem de todos os feitiços na pilha de comandos. Para fazer isso, você usará de uma pilha auxiliar temporária.

Requisitos:
Utilize o código da atividade anterior como base.
Implemente uma função void inverter_pilha(Pilha *p).
Dentro desta função, você deve:
- Criar e inicializar uma nova pilha, local, que servirá como auxiliar.
- Usar um laço de repetição que, enquanto a pilha original não estiver vazia, remove (pop) um feitiço da pilha original e o insere (push) na pilha auxiliar.
- Ao final do laço, a pilha original estará vazia e a auxiliar conterá todos os feitiços na ordem inversa.
- Finalmente, faça com que o topo da pilha original aponte para o topo da pilha auxiliar, efetivamente substituindo a pilha antiga pela nova, invertida.
Adicione uma nova opção ao menu para "Inverter Ordem dos Feitiços".
Ao chamar a função, se a pilha não estiver vazia, exiba uma mensagem de sucesso, como "Ordem dos feitiços invertida!". Se estiver vazia, informe que não há nada para inverter.
Após a inversão, o usuário deve ser capaz de usar a opção "Mostrar Pilha" para verificar que a ordem foi, de fato, alterada.*/
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
    printf("6 - Inverter ordem dos feitiços\n");
    printf("7 - Finalizar e sair\n");
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

void inverter_pilha(Pilha *p){
    if (vazia(p)){
        printf("A pilha de comandos esta vazia. Nada a inverter.\n");
        return;
    }
    Pilha aux;
    aux.topo = NULL;
    while (!vazia(p)){
        Feitico f = pop(p);
        empilhar(&aux, f);
    }
    p->topo = aux.topo;
    printf("Ordem dos feitiços invertida!\n");
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 7){
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
        else if (op == 6){
            inverter_pilha(&pilha);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}