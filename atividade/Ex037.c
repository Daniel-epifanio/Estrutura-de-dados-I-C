/*Problema: Personagem e Seus Atributos

Contexto: Em um jogo de plataforma, o personagem principal possui um conjunto 
de atributos que definem seu estado atual no jogo, como sua vida e pontuação. 
Para organizar melhor o código, é comum agrupar esses atributos em uma estrutura 
própria. A estrutura principal do personagem, então, conteria essa estrutura 
de atributos.

Tarefa:
Escreva um programa em C que modele um personagem e seus atributos usando 
estruturas aninhadas. O programa deve inicializar os atributos, simular o 
personagem coletando um item e sofrendo dano, e depois exibir o status final.

Requisitos:
Estrutura de Atributos: Crie uma estrutura chamada Atributos que contenha:
int vida;
int pontuacao;
Estrutura do Personagem: Crie uma estrutura chamada Personagem que contenha:
char nome[50];
Uma variável do tipo Atributos chamada stats;
No programa principal (main):
- Crie uma variável do tipo Personagem chamada jogador.
- Peça ao usuário para digitar o nome do personagem e armazene-o em jogador.nome.
- Inicialize a vida do jogador em 100 e a pontuação em 0 (acessando através de jogador.stats).
- Imprima o status inicial do jogador. Exemplo de saída:
    Status Inicial -> Nome: Mario | Vida: 100 | Pontuacao: 0
- Simule que o jogador coletou uma moeda: adicione 10 pontos à sua pontuação.
- Simule que o jogador sofreu dano: subtraia 25 da sua vida.
- Imprima o status final do jogador com os valores atualizados. Exemplo de saída:
    Status Final -> Nome: Mario | Vida: 75 | Pontuacao: 10*/

#include <stdio.h>

typedef struct{
    int vida;
    int pontuacao;
}Atributos;

typedef struct{
    char nome[50];
    Atributos stats;
}Personagem;

int main(){
    Personagem jogador;
    printf("Digite o nome do Personagem\n");
    scanf("%s", &jogador.nome);
    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;
    printf("Status Inicial -> Nome: %s | Vida: %d | Pontuacao: %d\n", jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);

    jogador.stats.pontuacao += 10;
    jogador.stats.vida -= 25;
    printf("Status Final -> Nome: %s | Vida: %d | Pontuacao: %d\n", jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    
    return 0;
}
