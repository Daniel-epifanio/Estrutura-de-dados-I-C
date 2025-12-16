/*Problema: Recuperando a Sabedoria do Grimório (Carregar Pilha de Arquivo)

Contexto: O Arcanista retorna de seu descanso, pronto para continuar sua jornada. Ele abre seu grimório mágico, esperando encontrar a sequência de feitiços que ele tão cuidadosamente planejou e salvou. Agora é a hora de trazer esse conhecimento de volta à sua mente (a memória do programa), reconstruindo a pilha de comandos exatamente como estava antes. Esta é a etapa final para alcançar a persistência de dados.

Tarefa:
Sua tarefa é implementar a funcionalidade que permite ao programa carregar a pilha de comandos a partir do arquivo "grimorio.bin" no momento em que o programa é iniciado.

Requisitos:
Utilize o código da atividade anterior como base. Você precisará da função inverter_pilha de uma aula passada.
Implemente uma nova função void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo).
Dentro desta função, você deve:
- Abrir o arquivo especificado no modo de leitura binária ("rb").
- Importante: Se o arquivo não existir (fopen retornar NULL), a função deve simplesmente retornar sem erro, exibindo uma mensagem como "Nenhum grimório encontrado, iniciando com uma pilha vazia.". Isso é esperado na primeira vez que o programa roda.
- Use um laço de repetição com fread para ler uma struct Feitico de cada vez do arquivo.
- Para cada feitiço lido, adicione-o à pilha usando a função push.
- Após o laço terminar, feche o arquivo.
Ponto Crítico: Ao ler do arquivo e empilhar, a ordem dos feitiços será invertida (o primeiro feitiço no arquivo, que era o topo, será o primeiro a ser empilhado, tornando-se a base). Após carregar todos os feitiços, você deve chamar a função inverter_pilha() para restaurar a ordem original correta.
No main, chame a nova função carregar_pilha_de_arquivo() logo após a inicialização da pilha e antes de o menu principal ser exibido. Isso garante que o estado anterior seja restaurado no início de cada sessão.*/
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
    printf("6 - Carregar sequência do Grimório\n");
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

void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo){
    FILE *file = fopen(nome_arquivo, "rb");
    if (file == NULL){
        printf("Nenhum grimório encontrado, iniciando com uma pilha vazia.\n");
        return;
    }
    Feitico f;
    while (fread(&f, sizeof(Feitico), 1, file) == 1){
        empilhar(p, f);
    }
    fclose(file);
    inverter_pilha(p);
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;

    carregar_pilha_de_arquivo(&pilha, "./../arquivos/grimorio.bin");

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
            inverter_pilha(&pilha);
        }
        else if (op == 5){
            salvar_pilha_em_arquivo(&pilha, "./../arquivos/grimorio.bin");
        }
        else if (op == 6){
            carregar_pilha_de_arquivo(&pilha, "./../arquivos/grimorio.bin");
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}