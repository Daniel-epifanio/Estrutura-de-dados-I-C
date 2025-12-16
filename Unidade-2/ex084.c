/*Problema: Desenvolver um sistema de gerenciamento para um diário de missões (Quest Log) de um jogo de RPG, 
utilizando uma lista encadeada. O sistema deve permitir adicionar novas missões, exibir todas as missões ativas 
e, o mais importante, buscar uma missão específica pelo seu ID para que o jogador possa ver seus detalhes.

Contexto: Suponha um RPG onde o jogador mantém um diário de missões. Cada missão tem um ID numérico único, um 
título e um status (ex: 'Ativa', 'Concluída'). Quando o jogador interage com um NPC para entregar uma missão, 
o sistema precisa primeiro encontrar essa missão no diário usando o ID dela para então poder atualizar seu status.

Tarefa:
Crie um programa em C que simule a gestão de um diário de missões. O programa deve apresentar um menu com as seguintes opções:
Adicionar Missão: Adiciona uma nova missão ao final do diário (lista).
Mostrar Missões: Exibe todas as missões presentes no diário.
Buscar Missão por ID: Pede ao usuário um ID e procura a missão correspondente na lista.
Sair: Encerra o programa.
Requisitos:
Defina uma struct para representar uma Missao, contendo um id (inteiro), um titulo (string) e um status (string).
Utilize uma lista encadeada para armazenar as missões.
Implemente uma função pesquisar_missao que receba a lista e um id como parâmetros. A função deve retornar um ponteiro para o nó que contém a missão, se encontrada, ou NULL, caso contrário.
Na opção de busca, se a missão for encontrada, o programa deve exibir todos os seus dados (ID, título e status). Se não for encontrada, deve exibir a mensagem 'Missao nao encontrada!'.
O programa deve continuar executando e mostrando o menu até que o usuário escolha a opção de sair.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char titulo[50];
    char status[30];
}Missao;

struct No{
    Missao dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== SISTEMA DE MISSOES ===\n");
    printf("1 - Adicionar missao no inicio\n");
    printf("2 - Adicionar missao no fim\n");
    printf("3 - Mostrar todas as missoes\n");
    printf("4 - Pesquisar missao por ID\n");
    printf("5 - Sair\n");
    printf("==========================\n");
}

void ler(Missao *pm){
    printf("Digite o ID da missao: ");
    scanf(" %d", &pm->id);
    printf("Digite o titulo da missao: ");
    scanf(" %49s", pm->titulo);
    printf("Digite o status da missao: ");
    scanf(" %29s", pm->status);
}

void inserir_inicio(Lista *plista, Missao dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Missao dado){
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
    printf("\n=== LISTA DE MISSOES ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Titulo: %s | Status: %s\n", pi->dado.id, pi->dado.titulo, pi->dado.status);
    }
    printf("========================\n");
}

struct No* pesquisar_missao(Lista lista, int id){
    struct No * pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    return pi;
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Missao m;
            printf("\n--- Adicionar missao no inicio ---\n");
            ler(&m);
            inserir_inicio(&lista, m);
            printf("\nMissao adicionada com sucesso!\n");
        }
        else if (op == 2){
            Missao m;
            printf("\n--- Adicionar missao no fim ---\n");
            ler(&m);
            inserir_fim(&lista, m);
            printf("\nMissao adicionada com sucesso!\n");
        }
        else if (op == 3){
            mostrar(lista);
        }
        else if (op == 4){
            int id;
            printf("\nInforme o ID da missao: ");
            scanf("%d", &id);
            struct No * pi = pesquisar_missao(lista, id);
            if (pi != NULL){
                printf("\n=== MISSAO ENCONTRADA ===\n");
                printf("ID: %d\n", pi->dado.id);
                printf("Titulo: %s\n", pi->dado.titulo);
                printf("Status: %s\n", pi->dado.status);
                printf("=========================\n");
            }
            else{
                printf("\nMissao nao encontrada!\n");
            }
        }
    } while (op != 5);
    
    return 0;
}