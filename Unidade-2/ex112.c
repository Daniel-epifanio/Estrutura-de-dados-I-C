/*Problema: Estrutura de Dados Fila: Operação para Obter o Início (Peek/Front)

Contexto: Para melhorar a experiência do usuário no lobby do nosso jogo MOBA, a equipe de design quer exibir uma mensagem dinâmica mostrando quem é o próximo jogador na fila. Isso cria uma sensação de progresso e informa aos jogadores que o sistema está ativo. Para fazer isso, precisamos de uma maneira de "espiar" o primeiro jogador da fila sem removê--lo, pois a partida ainda não começou.

Tarefa:
Implemente no programa a funcionalidade de consultar os dados do primeiro jogador da fila sem alterar a fila de forma alguma.

Requisitos:
Crie a função Jogador verInicio(Fila *f). Esta função deve retornar os dados do jogador que está no início da fila.
Importante: A função não deve remover o nó nem modificar qualquer ponteiro da fila (inicio, fim).
A função deve lidar com o caso de uma fila vazia. Se a fila estiver vazia, ela deve retornar uma struct Jogador com um ID inválido (ex: -1) para indicar que não há ninguém na frente.
Atualize o menu no programa principal para incluir uma nova opção, como "Ver quem e o proximo da Fila".
Modifique a função main para que, ao selecionar esta nova opção, ela chame a função verInicio. Se um jogador válido for retornado, exiba uma mensagem como: "O proximo jogador a entrar na partida e: [nickname] (ID: [id])". Se a fila estiver vazia, informe o usuário.*/
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
    No * novo = (No*) malloc(sizeof(No));
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

void mostrar(Fila fila){
    if (fila.inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No * pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nick: %s\n", pi->dado.id, pi->dado.nickname);
    }
}

void menu(){
    printf("=== Fila de Jogadores === \n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - Verificar se a Fila esta Vazia\n");
    printf("5 - Ver quem e o proximo da Fila\n");
    printf("6 - Sair \n");
    printf("=========================\n");
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

Jogador verInicio(Fila *f){
    Jogador falha;
    falha.id = -1;
    strcpy(falha.nickname, "");
    if (f->inicio == NULL){
        return falha;
    }
    return f->inicio->dado;
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 6){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
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
        else if (op == 5){
            Jogador j = verInicio(&fila);
            if (j.id == -1){
                printf("A fila esta vazia, nenhum jogador na frente.\n");
            } else {
                printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}