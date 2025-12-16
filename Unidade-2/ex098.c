/*Problema: Carregar o Roster de uma Guilda de um Arquivo de Save

Contexto: Em um RPG online, quando um servidor de jogo é reiniciado para manutenção, ele precisa recarregar os dados de todas as guildas salvas para que os jogadores encontrem seus grupos intactos ao voltarem a jogar. As informações dos membros de cada guilda (ID, nome e nível) são salvas em um arquivo binário para garantir um carregamento rápido e eficiente.

Tarefa: 
Sua missão é implementar a funcionalidade que carrega o registro de membros de uma guilda a partir de um arquivo binário guild_roster.b, armazena esses dados em uma lista encadeada e, em seguida, exibe a lista de membros na tela. Este processo simula o carregamento de um 'save game' do estado da guilda.

Requisitos:
Defina uma struct para representar um Membro da guilda, contendo um id (int), nome (char[100]) e nivel (int).
Utilize a implementação padrão de lista encadeada com struct No e struct Lista que você já conhece.
Crie uma função Lista carregar_guilda(). Esta função deve:
a. Abrir o arquivo guild_roster.b em modo de leitura binária ("rb").
b. Criar uma nova lista encadeada vazia.
c. Usar um laço com a função fread() para ler cada Membro do arquivo, um de cada vez.
d. Para cada membro lido, inseri-lo no final da nova lista encadeada.
e. Fechar o arquivo e retornar a lista completamente preenchida.
Na função main, chame a função carregar_guilda() para obter a lista de membros e, em seguida, chame uma função mostrar_guilda() para imprimir os dados de todos os membros carregados, verificando se o processo foi bem-sucedido.
Para testar, você precisará de um arquivo guild_roster.b. Você pode criar uma função auxiliar salvar_guilda_teste() que cria uma lista com 3 membros fixos e a salva no arquivo usando fwrite(), similar ao que foi visto na aula anterior. Chame essa função de salvamento antes da de carregamento para garantir que o arquivo de teste exista.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    int nivel;
} Membro;

struct No {
    Membro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Sistema de Guilda ===\n");
    printf("1 - Criar arquivo de teste\n");
    printf("2 - Carregar guilda do arquivo\n");
    printf("3 - Mostrar guilda\n");
    printf("4 - Sair\n");
    printf("=========================\n");
}

void inserir_fim(Lista *plista, Membro dado) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
        }
        pi->prox = novo;
    }
}

void mostrar_guilda(Lista lista) {
    struct No *pi;
    printf("\n=== Membros da Guilda ===\n");
    int contador = 0;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s | Nivel: %d\n", 
               pi->dado.id, pi->dado.nome, pi->dado.nivel);
        contador++;
    }
    if (lista.inicio == NULL) {
        printf("(guilda vazia)\n");
    } else {
        printf("Total: %d membro(s)\n", contador);
    }
    printf("=========================\n\n");
}

void salvar_guilda_teste() {
    FILE *file = fopen("./../arquivos/guild_roster2.bin", "wb");
    if (file == NULL) {
        printf("Erro ao criar arquivo de teste\n");
        return;
    }

    Membro m1 = {1, "Aragorn", 85};
    Membro m2 = {2, "Legolas", 72};
    Membro m3 = {3, "Gimli", 68};
    
    fwrite(&m1, sizeof(Membro), 1, file);
    fwrite(&m2, sizeof(Membro), 1, file);
    fwrite(&m3, sizeof(Membro), 1, file);
    
    fclose(file);
    printf("Arquivo de teste criado com sucesso!\n");
    printf("3 membros salvos em guild_roster.b\n");
}

Lista carregar_guilda() {

    Lista lista;
    lista.inicio = NULL;

    FILE *file = fopen("./../arquivos/guild_roster2.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir arquivo. Certifique-se de criar o arquivo de teste primeiro.\n");
        return lista;
    }
    
 
    Membro membro;
    int contador = 0;
    while (fread(&membro, sizeof(Membro), 1, file) == 1) {
    
        inserir_fim(&lista, membro);
        contador++;
    }
    
    fclose(file);
    printf("Guilda carregada com sucesso!\n");
    printf("%d membro(s) carregado(s) do arquivo\n", contador);
    
    return lista;
}

void liberar_lista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            salvar_guilda_teste();
        }

        if (op == 2) {

            liberar_lista(&lista);
     
            lista = carregar_guilda();
        }

        if (op == 3) {
            mostrar_guilda(lista);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}