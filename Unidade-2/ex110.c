/*Problema: Estrutura de Dados Fila: Implementando a Remoção de Elementos (Dequeue)

Contexto: O sistema de matchmaking do nosso jogo MOBA já permite que jogadores entrem na fila (enqueue) e que os administradores visualizem a fila. O próximo passo crucial é fazer o sistema funcionar: pegar o primeiro jogador da fila para criar uma nova partida. Esta ação deve seguir rigorosamente o princípio FIFO, garantindo que quem esperou por mais tempo seja o primeiro a jogar.

Tarefa: 
Altere o programa anterior para implementar a funcionalidade de remover o primeiro jogador da fila. A função deve retornar os dados do jogador removido para que o sistema possa, por exemplo, confirmar qual jogador foi alocado para uma partida.

Requisitos:
Implemente a função Jogador remover(Fila *f). Esta função deve remover o nó do início da fila e retornar os dados do jogador que estava nesse nó.
Dentro da função, você deve:
a. Tratar o caso de uma fila vazia. Se não houver ninguém para remover, imprima uma mensagem de aviso e retorne uma struct Jogador com um ID inválido (ex: -1) para indicar que a operação falhou.
b. Se a fila não estiver vazia, guarde os dados do primeiro jogador e um ponteiro para o nó a ser removido.
c. Atualize o ponteiro inicio da fila para que ele aponte para o segundo elemento.
d. Caso especial: Se a fila tinha apenas um elemento, após a remoção, o inicio se tornará NULL. Nesse caso, você também deve atualizar o ponteiro fim para NULL.
e. Libere a memória do nó removido usando a função free().
f. Retorne os dados do jogador que foi removido.
Atualize o menu no programa principal (main) para incluir a opção "Remover Jogador da Fila" (ou "Iniciar Partida").
No main, ao chamar a função remover, verifique o ID do jogador retornado. Se o ID não for inválido, imprima uma mensagem de sucesso, como "O jogador [nickname] (ID: [id]) foi removido da fila e entrou em uma partida.".*/
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

void mostrar(Fila *fila){
    if (fila->inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No * pi;
    for (pi = fila->inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nick: %s\n", pi->dado.id, pi->dado.nickname);
    }
}

Jogador remover(Fila *pfila){
    Jogador falha;
    falha.id = -1;
    strcpy(falha.nickname, "");

    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
        return falha;
    }

    No *rem = pfila->inicio;
    Jogador j = rem->dado;

    pfila->inicio = rem->prox;
    if (pfila->inicio == NULL){
        pfila->fim = NULL;
    }

    free(rem);
    return j;
}

void menu(){
    printf("=== Fila de Jogadores === \n");
    printf("1 - Adicionar Jogador na Fila\n");
    printf("2 - Mostrar Fila\n");
    printf("3 - Remover Jogador (Iniciar Partida)\n");
    printf("4 - Sair \n");
    printf("=========================\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(&fila);
        }
        else if(op == 3){
            Jogador j = remover(&fila);
            if (j.id != -1){
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", j.nickname, j.id);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}