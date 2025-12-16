/*Problema: Arquivando a Sabedoria no Grimório (Salvar Pilha em Arquivo)

Contexto: O Arcanista dedicou tempo planejando uma sequência complexa e poderosa de feitiços. Seria uma grande perda de tempo e esforço se ele tivesse que refazer tudo cada vez que precisasse descansar (ou seja, fechar o programa). Para evitar isso, ele precisa de uma forma de registrar seus planos em seu grimório mágico. Isso permitirá que ele salve seu estado atual e, em uma futura aventura (ou aula), recupere exatamente de onde parou.

Tarefa:
Sua tarefa final nesta saga é implementar a funcionalidade de salvar a pilha de comandos do Arcanista em um arquivo binário. Isso garantirá que a sequência de feitiços possa ser armazenada permanentemente no disco.

Requisitos:
Utilize o código da atividade anterior como base.
Implemente uma função void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo).
Dentro desta função, você deve:
- Abrir um arquivo no modo de escrita binária ("wb"). Lembre-se de verificar se o arquivo foi aberto com sucesso.
- Percorrer toda a pilha, do topo à base, usando um ponteiro auxiliar.
- Para cada nó na pilha, use a função fwrite() para escrever apenas a estrutura Feitico (aux->dado) no arquivo. Não salve os ponteiros!
- Após percorrer toda a pilha, feche o arquivo com fclose().
Adicione uma nova opção ao menu, como 5: Salvar Sequência no Grimório. Reenumere a opção de sair.
Ao selecionar a nova opção, o programa deve chamar a função salvar_pilha_em_arquivo, usando um nome de arquivo fixo, como "grimorio.bin".
Exiba uma mensagem de sucesso ao usuário após salvar, ou uma mensagem de erro caso não seja possível abrir o arquivo.*/
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
    printf("4 - Inverter ordem dos feitiços\n");
    printf("5 - Salvar sequência no Grimório\n");
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

void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo){

    FILE *file = fopen(nome_arquivo, "wb");
    if (file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    No *aux;
    
    for (aux = p->topo; aux != NULL; aux = aux->prox){
        fwrite(&aux->dado, sizeof(Feitico), 1, file);
    }

    fclose(file);
    printf("Sequência salva com sucesso em %s\n", nome_arquivo);
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
            inverter_pilha(&pilha);
        }
        else if (op == 5){
            salvar_pilha_em_arquivo(&pilha, "./../arquivos/grimorio.bin");
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}