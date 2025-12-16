/*Contexto: Supondo um jogo de arena multiplayer, quando os jogadores entram na fila para uma nova partida, 
eles são adicionados em ordem de chegada. O primeiro a entrar é o primeiro a ser atendido pelo sistema de 
matchmaking. Isso cria uma fila justa, onde novos jogadores sempre vão para o final da linha.

Tarefa:
Você deve criar um programa que simule essa fila de espera. O sistema deve permitir que novos jogadores 
sejam adicionados ao final da fila e que a fila atual seja exibida a qualquer momento, mostrando a ordem 
correta dos jogadores.

Requisitos:
Use uma lista encadeada para representar a fila de jogadores.
Cada jogador deve ser representado por uma struct contendo uma matricula (ID do jogador, int) e um nome (string).
O programa deve apresentar um menu com as seguintes opções:
1 - Adicionar jogador no início da fila (para casos de prioridade)
2 - Adicionar jogador no fim da fila (o caso de uso principal)
3 - Mostrar fila
4 - Sair
A função para inserir no fim deve ser o foco principal. Ela precisa lidar corretamente tanto com uma fila vazia quanto com uma fila que já contém jogadores.
A função de mostrar deve exibir a matrícula e o nome de cada jogador na ordem em que estão na fila.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int mat;
    char nome[50];
}jogador;

struct No{
    jogador dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Adicionar jogador no inicio da fila\n");
    printf("2 - Adicionar jogador no fim da fila\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Sair\n");
    printf("=========================\n");
}

void ler(jogador *pj){
    scanf(" %d %49s", &pj->mat, pj->nome);
}

void inserir_inicio(Lista *plista, jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== Fila de Jogadores ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("=========================\n\n");
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            jogador j;
            printf("Digite a matricula e o nome do jogador: ");
            ler(&j);
            inserir_inicio(&lista, j);
            printf("Jogador adicionado no inicio da fila!\n\n");
        }
        else if (op == 2){
            jogador j;
            printf("Digite a matricula e o nome do jogador: ");
            ler(&j);
            inserir_fim(&lista, j);
            printf("Jogador adicionado no fim da fila!\n\n");
        }
        else if (op == 3){
            mostrar(lista);
        }
    } while (op != 4);

    printf("Programa Finalizado!");
    
    return 0;
}