/*Problema: Modularizando um Grimório de Feitiços em C

Contexto: Suponha um jogo de RPG de fantasia, o grimório (livro de feitiços) de um mago é uma das suas posses mais importantes. Atualmente, toda a lógica para adicionar, encontrar e listar feitiços está misturada no arquivo main.c, o que torna a adição de novas mecânicas de magia (como feitiços de diferentes níveis ou tipos elementais) uma tarefa confusa e propensa a erros. Para organizar o código e prepará-lo para futuras expansões, você precisa refatorar a lógica do grimório, transformando-a em um módulo independente.

Tarefa: 
Você deve criar um sistema modular para gerenciar o grimório de um mago. O grimório será implementado como uma lista encadeada de feitiços.

Requisitos:
1. Crie uma struct Spell que armazene um id (inteiro), name (string de até 50 caracteres) e mana_cost (inteiro).
2. Crie um módulo spellbook composto por dois arquivos:
spellbook.h (Arquivo de Cabeçalho):
- Deve conter as definições das structs necessárias (para o nó da lista e para o Spell).
- Deve conter os protótipos (assinaturas) de todas as funções públicas do módulo.
- Use typedef para criar tipos mais simples, como Spell e Spellbook.
spellbook.c (Arquivo de Implementação):
- Deve conter a implementação (o código) de todas as funções declaradas no .h.
- Funções a serem implementadas:
    Spellbook* create_spellbook(): Aloca e retorna um novo grimório vazio (inicializado com NULL).
    void add_spell(Spellbook* book, int id, const char* name, int mana_cost): Adiciona um novo feitiço ao final do grimório.
    void display_spellbook(Spellbook* book): Percorre a lista e imprime os detalhes de cada feitiço no formato: ID: [id], Feitiço: [name], Custo de Mana: [mana_cost].
    void destroy_spellbook(Spellbook* book): Libera toda a memória alocada para os nós do grimório, evitando vazamentos de memória.
3. Crie um arquivo main.c:
Este arquivo deve ser simples e limpo.
Ele deve incluir o cabeçalho spellbook.h.
Na função main, demonstre o uso do módulo: crie um grimório, adicione pelo menos três feitiços, exiba o grimório completo e, por fim, destrua o grimório para liberar a memória.*/
#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook* my_book = create_spellbook();

    add_spell(my_book, 1, "Bola de Fogo", 30);
    add_spell(my_book, 2, "Cura Menor", 15);
    add_spell(my_book, 3, "Parede de Gelo", 40);

    printf("=== Grimório do Mago ===\n");
    display_spellbook(my_book);

    destroy_spellbook(my_book);

    return 0;
}