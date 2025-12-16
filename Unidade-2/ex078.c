/*Contexto: Em um jogo de RPG, a lógica para calcular danos, bônus de ataque, penalidades de defesa, etc. 
pode se tornar complexa. Para manter o código do jogo organizado e reutilizável, é uma prática comum criar 
um 'módulo de utilidades de combate' que centraliza todas essas fórmulas. Desta forma, qualquer parte do jogo 
(seja uma habilidade de personagem, um efeito de item ou uma armadilha de ambiente) pode usar essas mesmas 
funções de cálculo, garantindo consistência.

Tarefa:
Você deve criar um programa modular que simule cálculos de combate básicos. O programa será dividido 
em três arquivos: combate.h, combate.c e main.c.

Requisitos:
- Arquivo "combate.h" (Interface do Módulo):
Este arquivo deve conter apenas as declarações (protótipos) de duas funções:
Uma função calcular_ataque_total que recebe o ataque base de um personagem (inteiro) e um bônus de arma (inteiro), e retorna o ataque final.
Uma função aplicar_dano que recebe a vida atual de um alvo (inteiro) e o dano sofrido (inteiro), e retorna a vida restante.
- Arquivo "combate.c" (Implementação do Módulo):
Deve incluir o arquivo combate.h.
Deve conter a implementação (o corpo) das duas funções declaradas em combate.h.
calcular_ataque_total simplesmente soma o ataque base e o bônus.
aplicar_dano subtrai o dano da vida atual. Se a vida ficar negativa, deve retornar 0.
- Arquivo "main.c" (Programa Principal):
Deve incluir as bibliotecas padrão (stdio.h) e o seu módulo (combate.h).
Na função main, leia do usuário os seguintes dados: ataque base do herói, bônus da sua espada, vida inicial do inimigo.
Chame a função calcular_ataque_total para descobrir o dano que o herói irá causar.
Chame a função aplicar_dano para calcular a vida restante do inimigo após o ataque.
Exiba o poder de ataque total do herói e a vida restante do inimigo.*/
#include <stdio.h>
#include "combate.h"

int main(){
    int ataque, bonus, hp_inimigo;
    printf("Digite o ataque base do Herói:\n");
    scanf("%d", &ataque);
    printf("Digite o bônus de ataque da espada:\n");
    scanf("%d", &bonus);
    printf("Digite a vida inicial do inimigo:\n");
    scanf("%d", &hp_inimigo);
    int ataque_total = calcular_ataque_total(ataque, bonus);
    hp_inimigo = aplicar_dano(hp_inimigo, ataque_total);
    printf("Status: Ataque total: %d | Vida do Inimigo: %d\n", ataque_total, hp_inimigo);
    return 0;
}