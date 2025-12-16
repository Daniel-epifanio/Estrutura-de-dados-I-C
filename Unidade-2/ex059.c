/*Contexto: Supondo um jogo de RPG de mundo aberto, o jogador mantém um Bestiário, 
um catálogo digital de todos os monstros que já encontrou. À medida que o jogo avança, 
este catálogo pode crescer para centenas de entradas. Para que a interface do Bestiário 
seja rápida e responsiva, o sistema de busca precisa ser extremamente eficiente. 
Os monstros no Bestiário são sempre armazenados de forma ordenada pelo seu ID numérico único.

Tarefa:
Você deve criar um programa que simule o sistema de busca do Bestiário. O programa 
primeiro registrará um conjunto de monstros (fornecidos em ordem crescente de ID) e, 
em seguida, permitirá que o jogador procure por um monstro específico usando seu ID.

Requisitos:
Defina uma struct chamada Monstro para armazenar os dados de cada criatura: um id 
(inteiro), um nome (string com no máximo 50 caracteres), hp (inteiro) e ataque (inteiro).
O programa deve primeiro ler um número N de monstros a serem catalogados.
Em seguida, leia os dados dos N monstros (ID, nome, HP, ataque) para um vetor de structs. 
Assuma que os dados de entrada já estarão ordenados pelo id do monstro.
Implemente uma função de Busca Binária Recursiva que receba o ID a ser procurado, o vetor de monstros e os limites da busca. 
A função deve retornar o índice do monstro no vetor se ele for encontrado, ou -1 caso contrário.
Após catalogar os monstros, o programa deve entrar em um loop onde o jogador pode digitar um ID para buscar. 
O loop deve continuar até que o jogador digite 0.
Para cada ID buscado, chame sua função de busca binária. Se o monstro for encontrado, 
imprima seus dados no formato: Monstro Encontrado: [Nome] (ID: [id]) - HP: [hp], Ataque: [ataque].
Se o monstro não for encontrado, imprima a mensagem: Monstro com ID [id] nao encontrado.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;

void ler(Monstro *monstro){
    scanf("%d %49s %d %d", &monstro->id, monstro->nome, &monstro->hp, &monstro->ataque);
}

void menu(){
    printf("======================= Escolha uma opção =======================\n");
    printf("1 - Pesquisar\n");
    printf("2 - Finalizar\n");
    printf("================================================================\n");
}

int buscarMonstroPorId(int id, Monstro *monstros, int i, int f){
    if(i > f) return -1;

    int meio = (i + f) / 2;

    if(monstros[meio].id == id){
        return meio;
    }

    if(monstros[meio].id < id){
        return buscarMonstroPorId(id, monstros, meio + 1, f);
    }

    return buscarMonstroPorId(id, monstros, i, meio - 1);
}

int main(){
    int n;
    printf("Digite a quantidade de monstros a serem catalogados:\n");
    scanf("%d", &n);

    Monstro *monstros = malloc(n * sizeof(Monstro));

    printf("Digite os dados dos monstros\n");
    for (int i = 0; i < n; i++){
        ler(&monstros[i]);
    }

    int opcao;
    menu();
    scanf("%d", &opcao);

    while (opcao != 2){

        if(opcao == 1){
            int id;
            printf("Digite o id do monstro que você deseja encontrar\n");
            scanf("%d", &id);

            int idx = buscarMonstroPorId(id, monstros, 0, n - 1);

            if(idx != -1){
                printf("Monstro Encontrado: %s (ID: %i) - HP: %i, Ataque: %i\n",
                       monstros[idx].nome,
                       monstros[idx].id,
                       monstros[idx].hp,
                       monstros[idx].ataque);
            } else {
                printf("Monstro com ID %i nao encontrado.\n", id);
            }
        }

        menu();
        scanf("%d", &opcao);
    }
    printf("Operação Finalizada!\n");
    free(monstros);
    return 0;
}