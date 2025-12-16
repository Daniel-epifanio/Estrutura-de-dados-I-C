/*Problema: Executando o Próximo Comando (Pop)

Contexto: O nosso Arcanista já sabe como adicionar feitiços à sua pilha de comandos (push) e como visualizar a sequência de ações pendentes (mostrar_pilha). Agora é o momento da ação! O Arcanista precisa executar o comando que está no topo da pilha. Lembre-se do princípio LIFO (Last-In, First-Out): o último feitiço adicionado é o primeiro a ser lançado.

Tarefa:
Sua tarefa é finalizar o ciclo de comando do Arcanista, implementando a funcionalidade de "lançar" o próximo feitiço. Isso corresponde à operação pop de uma pilha, onde o elemento do topo é removido e processado.

Requisitos:
Utilize o código da atividade anterior como base.
Modifique o menu para incluir a nova opção: 2: Lançar Próximo Feitiço. As opções "Mostrar Pilha" e "Sair" devem ser ajustadas para 3 e 4, respectivamente.
Implemente uma função Feitico pop(Pilha *p) que:
- Verifica se a pilha não está vazia.
- Se não estiver vazia, remove o nó do topo.
- Libera a memória do nó removido usando free().
- Retorna a struct Feitico que estava no nó removido.
Se a pilha estiver vazia quando a função pop for chamada, ela deve exibir uma mensagem de erro ("A pilha de comandos esta vazia!") e retornar uma struct Feitico indicando a falha (por exemplo, com custo_mana = -1).
No main, ao escolher a opção 2, chame a função pop e, se a operação for bem-sucedida, exiba uma mensagem confirmando qual feitiço foi "lançado" (ex: "Feitiço 'BolaDeFogo' lançado com sucesso!").
Antes de o programa encerrar, crie uma função void liberar_pilha(Pilha *p) que utiliza laços de repetição e a função pop para esvaziar completamente a pilha, garantindo que toda a memória alocada seja liberada.*/
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
    printf("2 - Lançar próximo feitiço (pop)\n");
    printf("3 - Mostrar pilha de comandos\n");
    printf("4 - Finalizar e sair\n");
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

Feitico pop(Pilha *p){
    Feitico falha;
    strcpy(falha.nome, "");
    falha.custo_mana = -1;
    if (p->topo == NULL){
        printf("A pilha de comandos esta vazia!\n");
        return falha;
    }
    No *rem = p->topo;
    Feitico valor = rem->dado;
    p->topo = rem->prox;
    free(rem);
    return valor;
}

void mostrar_pilha(Pilha *p){
    if (p->topo == NULL){
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

void liberar_pilha(Pilha *p){
    while (p->topo != NULL){
        (void)pop(p);
    }
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4){
        if (op == 1){
            Feitico f;
            printf("Informe o nome do feitiço:\n");
            scanf("%99s", f.nome);
            printf("Informe o custo de mana:\n");
            scanf("%d", &f.custo_mana);
            empilhar(&pilha, f);
        }
        else if (op == 2){
            Feitico l = pop(&pilha);
            if (l.custo_mana != -1){
                printf("Feitiço '%s' lançado com sucesso!\n", l.nome);
            }
        }
        else if (op == 3){
            mostrar_pilha(&pilha);
        }
        menu();
        scanf("%d", &op);
    }
    liberar_pilha(&pilha);
    return 0;   
}