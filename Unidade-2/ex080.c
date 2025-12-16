/*Problema: Refatorando o Gerenciador de Equipes para um TAD

Contexto: Em um RPG tático, o sistema de gerenciamento da equipe (party) precisa ser robusto e reutilizável. Atualmente, toda a lógica para criar, ler e exibir os heróis está misturada no arquivo main.c, tornando o código confuso e difícil de expandir. Para preparar o jogo para futuras funcionalidades (como sistemas de inventário, habilidades, etc.), você precisa refatorar o código, isolando toda a lógica relacionada aos heróis em seu próprio módulo, aplicando os conceitos de Tipo Abstrato de Dados (TAD).

Tarefa:
Você deve criar um módulo chamado personagem para encapsular toda a lógica de gerenciamento dos heróis do jogo. O programa principal (main.c) deve apenas utilizar a interface fornecida pelo seu módulo, sem conhecer os detalhes da implementação.

Requisitos:

Crie um arquivo de cabeçalho personagem.h:
- Este arquivo deve definir a interface do seu TAD.
- Use typedef struct personagem Personagem; para criar um tipo opaco. O main não deve saber o que há dentro da struct.
- Declare os protótipos das seguintes funções:
    Personagem* cria_party(int num_membros); (Aloca dinamicamente memória para a equipe).
    void registra_membros(Personagem* party, int num_membros); (Lê os dados de cada membro da equipe).
    void exibe_relatorio(const Personagem* party, int num_membros); (Exibe os dados de todos os membros da equipe).
    void libera_party(Personagem* party); (Libera a memória alocada para a equipe).
Crie um arquivo de código fonte personagem.c:
- Este arquivo deve conter a implementação do seu TAD.
- Inclua as bibliotecas necessárias (stdio.h, stdlib.h) e o seu próprio cabeçalho ("personagem.h").
- Defina a estrutura struct personagem com os seguintes membros: nome (string), classe (string), nivel (int) e hp (int).
- Implemente as quatro funções declaradas no arquivo .h.
Modifique o arquivo main.c:
- O main.c deve incluir apenas stdio.h e "personagem.h".
- A função main deve:
    Perguntar ao usuário quantos membros a equipe terá.
    Chamar cria_party() para alocar a equipe.
    Chamar registra_membros() para preencher os dados dos heróis.
    Chamar exibe_relatorio() para mostrar as informações da equipe na tela.
    Chamar libera_party() para liberar a memória antes de encerrar.
Seu main.c deve ser limpo e apenas interagir com o seu TAD através das funções da interface, demonstrando o encapsulamento e a separação de responsabilidades.*/
#include <stdio.h>
#include "personagem/personagem.h"

int main(){
    int n;
    printf("Informe quantos membros a equipe tera:\n");
    scanf("%d", &n);

    Personagem *party = cria_party(n);

    if (party == NULL) {
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    registra_membros(party, n);
    exibe_relatorio(party, n);
    libera_party(party);
    return 0;
}