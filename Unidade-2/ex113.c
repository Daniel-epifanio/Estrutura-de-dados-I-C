/*Problema: Estrutura de Dados Fila: Salvando a Fila em um Arquivo Binário

Contexto: O nosso sistema de matchmaking está se tornando robusto. No entanto, existe um grande risco: se o servidor do jogo reiniciar ou sofrer uma falha de energia, toda a fila de jogadores é perdida. Isso é frustrante para os jogadores que esperaram por muito tempo. Para resolver isso, precisamos implementar um mecanismo de persistência que salve o estado atual da fila em um arquivo.

Tarefa:
Adicione ao programa a capacidade de salvar todos os jogadores da fila em um arquivo binário. Esta operação garantirá que, mesmo que o programa seja encerrado, a ordem e os dados dos jogadores possam ser recuperados posteriormente.

Requisitos:
Crie uma nova função void salvarFila(Fila *f, const char *nomeArquivo).
Dentro desta função, abra o arquivo especificado em modo de escrita binária ("wb"). É crucial verificar se o arquivo foi aberto com sucesso. Se não, exiba uma mensagem de erro.
Percorra a fila do inicio ao fim usando um ponteiro auxiliar.
Para cada nó da fila, use a função fwrite() para escrever apenas a estrutura Jogador (dado) no arquivo. Não escreva o nó inteiro, pois o ponteiro prox não tem sentido fora da memória do programa.
Após percorrer toda a fila, feche o arquivo com fclose().
Atualize o menu principal (main) para incluir uma nova opção, como "Salvar Fila em Arquivo".
Quando o usuário selecionar essa opção, o programa deve chamar a função salvarFila com um nome de arquivo fixo, por exemplo, "matchmaking_queue.bin".*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[50];
}estudante;

struct no{
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
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
    printf("6 - Salvar Fila em Arquivo\n");
    printf("7 - sair \n");
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

void salvarFila(Fila *f, const char *nomeArquivo){
    FILE *file = fopen(nomeArquivo, "wb");
    if (file == NULL){
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }
    No * pi;
    for (pi = f->inicio; pi != NULL; pi = pi->prox){
        fwrite(&pi->dado, sizeof(estudante), 1, file);
    }
    fclose(file);
    printf("Fila salva com sucesso em %s\n", nomeArquivo);
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 7){
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
            salvarFila(&fila, "matchmaking_queue.bin");
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}
