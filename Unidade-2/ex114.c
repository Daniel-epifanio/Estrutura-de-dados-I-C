/*Problema: Estrutura de Dados em C: Recarregando uma Fila a partir de um Arquivo Binário.

Contexto: Após a implementação bem-sucedida de salvar a fila, o passo final para tornar nosso sistema de matchmaking resiliente a falhas é carregar essa fila salva quando o servidor é iniciado. Ao executar o programa, ele deve verificar se existe um arquivo de salvamento e, se houver, reconstruir a fila exatamente como estava antes do encerramento, garantindo que nenhum jogador perca seu lugar.

Tarefa: 
Modifique o programa para que ele tente carregar automaticamente os dados da fila a partir do arquivo binário "matchmaking_queue.bin" no momento em que é iniciado.

Requisitos:
Crie uma nova função void carregarFila(Fila *f, const char *nomeArquivo).
Dentro desta função, abra o arquivo especificado em modo de leitura binária ("rb").
A função deve ser robusta: se o arquivo não existir (o que acontecerá na primeira vez que o programa for executado), ela deve simplesmente informar ao usuário e retornar, permitindo que o programa continue com uma fila vazia.
Se o arquivo for aberto com sucesso, use um laço while e a função fread() para ler cada struct Jogador do arquivo, uma por vez.
Para cada jogador lido do arquivo, utilize a função inserir() já existente para adicioná-lo à fila, reconstruindo-a na ordem correta.
Após o laço terminar (quando fread() não conseguir ler mais nenhum registro), feche o arquivo.
Na função main, chame a nova função carregarFila uma vez, logo após a inicialização da fila e antes do início do loop do menu.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

struct no{
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct 
{
    No * inicio;
    No * fim;
}Fila;

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir(Fila *pfila, estudante dado){
    No * novo = (No*) malloc(sizeof(No));
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

void mostrar(Fila fila){
    No * pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

void menu(){
    printf("=== escolha uma opcao === \n");
    printf("1 - inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - Vazia\n");
    printf("5 - Inicio\n");
    printf("6 - Salvar\n");
    printf("7 - Ler\n");
    printf("8 - sair \n");
    printf("=========================");
}

void remover(Fila *pfila){
    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
    }
    else if (pfila->inicio->prox == NULL){
        pfila->inicio = NULL;
        pfila->fim = NULL;
    }
    else{
        No * pi = pfila->inicio;
        pfila->inicio = pi->prox;
        free(pi);
    }
}

int vazia(Fila fila){
    if (fila.inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

No * inicio(Fila fila){
    return fila.inicio;
}

void salvar (Fila fila){
    FILE *file = fopen("./estudantes.b", "wb");
    if (file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    No * pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        fwrite(&pi->dado, sizeof(estudante), 1, file);
    }
    fclose(file);
    printf("Fila salva com sucesso.\n");
}

void carregarFila(Fila *f, const char *nomeArquivo){
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL){
        printf("Arquivo %s nao encontrado. Continuando com fila vazia.\n", nomeArquivo);
        return;
    }
    estudante e;
    while (fread(&e, sizeof(estudante), 1, file)){
        inserir(f, e);
    }
    fclose(file);
    printf("Fila carregada com sucesso.\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    carregarFila(&fila, "./estudantes.b");
    int op;
    menu();
    scanf("%d", &op);
    while (op != 8){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante:\n");
            ler(&e);
            inserir(&fila, e);
        }
        else if(op == 2){
            mostrar(fila);
        }
        else if(op == 3){
            remover(&fila);
        }
        else if (op == 4){
            int r;
            r = vazia(fila);
            if (r == 1){
                printf("A fila esta vazia\n");
            }
            else{
                printf("A fila nao esta vazia\n");
            }
        }
        else if(op == 5){
            No * pi = inicio(fila);
            if (pi != NULL){
                printf("%d %s\n", pi->dado.mat, pi->dado.nome);
            }
            else{
                printf("fila vazia\n");
            }
        }
        else if (op == 6){
            salvar(fila);
        }
        else if (op == 7){
            printf("Opcao de leitura nao mais necessaria. Use o menu para carregar dados ao iniciar.\n");
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}