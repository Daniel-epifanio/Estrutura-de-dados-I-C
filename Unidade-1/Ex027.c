/*Problema: Modelando Inimigos do Jogo

Contexto: Você está desenvolvendo um jogo de plataforma e precisa criar diferentes tipos de inimigos.
Cada inimigo no jogo terá um conjunto de atributos: uma quantidade de vida, um valor de ataque e uma 
velocidade de movimento. Por exemplo, um inimigo básico como um "Cogumelo zumbi" pode ter pouca vida 
e ser lento, enquanto um "Cavaleiro esqueleto" pode ter mais vida, um ataque mais forte e se mover mais 
rápido. Usar uma struct é a maneira perfeita de organizar esses atributos para cada tipo de inimigo, 
mantendo o código limpo e lógico.

Tarefa:
Escreva um programa em C que defina um modelo para um inimigo usando uma struct e, em seguida, 
crie e exiba as informações de dois inimigos diferentes.

Requisitos:
Definição da Estrutura: Crie uma struct chamada Inimigo. Ela deve conter os seguintes membros:
Um int chamado vida.
Um int chamado ataque.
Um float chamado velocidade.
Criação dos Inimigos: Na sua função main, declare duas variáveis do tipo struct Inimigo: uma chamada 
cogumelo_zumbi e outra chamada cavaleiro_esqueleto.
Atribuição de Atributos:
Para a variável cogumelo_zumbi, atribua os seguintes valores: vida = 20, ataque = 5, velocidade = 0.8.
Para a variável cavaleiro_esqueleto, atribua os seguintes valores: vida = 80, ataque = 15, velocidade = 1.2.
Exibição dos Dados: Imprima na tela os atributos de cada um dos inimigos de forma organizada. A saída esperada é:
--- Atributos do Inimigo: Cogumelo Zumbi ---
Vida: 20
Ataque: 5
Velocidade: 0.8

--- Atributos do Inimigo: Cavaleiro Esqueleto ---
Vida: 80
Ataque: 15
Velocidade: 1.2*/
#include <stdio.h>

    struct inimigo{
    int vida;
    int ataque;
    float velocidade;
    };
    
int main(){
    struct inimigo cogumelo_zumbi;
    struct inimigo cavaleiro_esqueleto;

    cogumelo_zumbi.vida = 20;
    cogumelo_zumbi.ataque = 5;
    cogumelo_zumbi.velocidade = 0.8;

    cavaleiro_esqueleto.vida = 80;
    cavaleiro_esqueleto.ataque = 15;
    cavaleiro_esqueleto.velocidade = 1.2;

    printf("--- Atributos do Inimigo: Cogumelo Zumbi ---\n");
    printf("Vida: %d\n",cogumelo_zumbi.vida);
    printf("Ataque: %d\n",cogumelo_zumbi.ataque);
    printf("Velocidade: %.1f\n",cogumelo_zumbi.velocidade);

    printf("--- Atributos do Inimigo: Cavaleiro esqueleto ---\n");
    printf("Vida: %d\n",cavaleiro_esqueleto.vida);
    printf("Ataque: %d\n",cavaleiro_esqueleto.ataque);
    printf("Velocidade: %.1f\n",cavaleiro_esqueleto.velocidade);
    return 0;
}