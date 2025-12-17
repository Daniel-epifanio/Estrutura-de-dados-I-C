/*Problema: Estrutura de Dados em C: Recarregando uma Fila a partir de um Arquivo Binário.

Contexto: Após a implementação bem-sucedida de salvar a fila, o passo final para tornar nosso sistema de 
matchmaking resiliente a falhas é carregar essa fila salva quando o servidor é iniciado. Ao executar o 
programa, ele deve verificar se existe um arquivo de salvamento e, se houver, reconstruir a fila exatamente 
como estava antes do encerramento, garantindo que nenhum jogador perca seu lugar.

Tarefa: 
Modifique o programa para que ele tente carregar automaticamente os dados da fila a partir do arquivo 
binário "matchmaking_queue.bin" no momento em que é iniciado.

Requisitos:
Crie uma nova função void carregarFila(Fila *f, const char *nomeArquivo).
Dentro desta função, abra o arquivo especificado em modo de leitura binária ("rb").
A função deve ser robusta: se o arquivo não existir (o que acontecerá na primeira vez que o programa for executado), 
ela deve simplesmente informar ao usuário e retornar, permitindo que o programa continue com uma fila vazia.
Se o arquivo for aberto com sucesso, use um laço while e a função fread() para ler cada struct Jogador do arquivo, uma por vez.
Para cada jogador lido do arquivo, utilize a função inserir() já existente para adicioná-lo à fila, reconstruindo-a na ordem correta.
Após o laço terminar (quando fread() não conseguir ler mais nenhum registro), feche o arquivo.
Na função main, chame a nova função carregarFila uma vez, logo após a inicialização da fila e antes do início do loop do menu.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char nome[50];
} Jogador;

struct no {
    Jogador dado;
    struct no *prox;
};

typedef struct no No;

typedef struct 
{
    No *inicio;
    No *fim;
} Fila;

void ler(Jogador *pj){
    scanf("%d %s", &pj->id, pj->nome);
}

void inserir(Fila *pfila, Jogador dado){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (pfila->inicio == NULL){
        pfila->inicio = novo;
        pfila->fim = novo;
    } else {
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
}

void mostrar(Fila fila){
    No *pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
}

void menu(){
    printf("\n=== MATCHMAKING ===\n");
    printf("1 - Inserir jogador\n");
    printf("2 - Mostrar fila\n");
    printf("3 - Remover jogador\n");
    printf("4 - Fila vazia?\n");
    printf("5 - Jogador no inicio\n");
    printf("6 - Salvar fila\n");
    printf("7 - Ler (nao utilizado)\n");
    printf("8 - Sair\n");
    printf("===================\n");
}

void remover(Fila *pfila){
    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
    } else {
        No *pi = pfila->inicio;
        pfila->inicio = pi->prox;
        if (pfila->inicio == NULL)
            pfila->fim = NULL;
        free(pi);
    }
}

int vazia(Fila fila){
    return fila.inicio == NULL;
}

No *inicio(Fila fila){
    return fila.inicio;
}

void salvar(Fila fila){
    FILE *file = fopen("matchmaking_queue.bin", "wb");
    if (file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    No *pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        fwrite(&pi->dado, sizeof(Jogador), 1, file);
    }

    fclose(file);
    printf("Fila de matchmaking salva com sucesso.\n");
}

void carregarFila(Fila *f, const char *nomeArquivo){
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL){
        printf("Arquivo de salvamento nao encontrado. Iniciando fila vazia.\n");
        return;
    }

    Jogador j;
    while (fread(&j, sizeof(Jogador), 1, file)){
        inserir(f, j);
    }

    fclose(file);
    printf("Fila de matchmaking carregada com sucesso.\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    carregarFila(&fila, "matchmaking_queue.bin");

    int op;
    menu();
    scanf("%d", &op);

    while (op != 8){
        if (op == 1){
            Jogador j;
            printf("Informe os dados do jogador (id nome):\n");
            ler(&j);
            inserir(&fila, j);
        }
        else if (op == 2){
            mostrar(fila);
        }
        else if (op == 3){
            remover(&fila);
        }
        else if (op == 4){
            if (vazia(fila))
                printf("A fila esta vazia\n");
            else
                printf("A fila nao esta vazia\n");
        }
        else if (op == 5){
            No *pi = inicio(fila);
            if (pi != NULL)
                printf("%d %s\n", pi->dado.id, pi->dado.nome);
            else
                printf("Fila vazia\n");
        }
        else if (op == 6){
            salvar(fila);
        }
        else if (op == 7){
            printf("Leitura ocorre automaticamente ao iniciar o programa.\n");
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}