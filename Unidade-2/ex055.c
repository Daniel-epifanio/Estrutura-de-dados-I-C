/*Contexto: Em um grande RPG Online (MMORPG), o servidor precisa gerenciar 
milhares de contas de jogadores. Cada jogador possui um ID numérico único. 
Quando um administrador de jogo (GM) precisa aplicar uma penalidade ou dar 
uma recompensa a um jogador específico, ele precisa encontrar a conta do 
jogador rapidamente usando seu ID. Como os IDs são armazenados em ordem 
numérica, a busca binária é o método ideal para localizar qualquer jogador 
em uma fração de segundo, mesmo em um banco de dados com milhões de entradas.

Tarefa:
Sua tarefa é criar um programa que simule essa ferramenta de GM. 
O programa irá ler uma lista de jogadores (ID, nickname e 'pontos 
de reputação'). Em seguida, o GM poderá pesquisar por um ID, e se 
o jogador for encontrado, o programa adicionará 100 pontos à sua 
reputação e exibirá o novo total.

Requisitos:
Crie uma struct chamada Jogador para armazenar um ID (int), um nickname (char[50]) e 
os pontos de reputação (int).
O programa deve primeiro ler um número N de jogadores a serem cadastrados.
Em seguida, leia os dados dos N jogadores. Importante: Assuma que os jogadores serão 
inseridos com IDs em ordem crescente (ex: 1001, 1002, 1005, 1010...).
Após o cadastro, o programa deve entrar em um loop com um menu de opções:
1 - Adicionar Reputação
2 - Sair
Ao escolher a opção 1, o programa deve solicitar o ID do jogador a ser modificado.
Implemente uma função de busca binária que receba o ID, o vetor de jogadores e o 
número de jogadores, e retorne o índice do jogador no vetor. Se não encontrar, 
deve retornar -1.
Se o jogador for encontrado, adicione 100 à sua reputação e imprima uma mensagem 
no formato: Nickname: [nickname], Nova Reputacao: [reputacao_atualizada]\n.
Se o jogador não for encontrado, imprima: Jogador com ID [id_pesquisado] nao encontrado.\n.
O programa deve continuar exibindo o menu até que a opção 2 (Sair) seja escolhida.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nickname[50];
    int reputacao;
} Jogador;

void lerDados(Jogador *jog) {
    scanf("%d %s %d", &jog->id, jog->nickname, &jog->reputacao);
}

void menu() {
    printf("========== MENU ==========\n");
    printf("1 - Adicionar Reputacao\n");
    printf("2 - Sair\n");
    printf("===========================\n");
}

int buscaBinaria(int id, Jogador jogs[], int n) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (jogs[meio].id == id) {
            return meio;
        }
        else if (id < jogs[meio].id) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return -1; 
}

int main() {
    int n;
    printf("Informe o número de jogadores: ");
    scanf("%d", &n);

    Jogador *jogs = malloc(n * sizeof(Jogador));

    for (int i = 0; i < n; i++) {
        lerDados(&jogs[i]);
    }

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            int idBusca;
            printf("Digite o ID do jogador: ");
            scanf("%d", &idBusca);

            int idx = buscaBinaria(idBusca, jogs, n);

            if (idx != -1) {
                jogs[idx].reputacao += 100;
                printf("Nickname: %s, Nova Reputacao: %d\n",
                       jogs[idx].nickname, jogs[idx].reputacao);
            }
            else {
                printf("Jogador com ID %d nao encontrado.\n", idBusca);
            }
        }
    } while (opcao != 2);

    printf("Fim do programa!\n");
    free(jogs);
    return 0;
}
