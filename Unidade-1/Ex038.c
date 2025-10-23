/*Problema: O Estado do Personagem no Jogo de Plataforma

Contexto: Em um jogo de plataforma, o personagem principal pode estar em 
vários estados diferentes: parado, correndo, pulando, etc. O motor do jogo 
precisa saber o estado atual do personagem para aplicar a física correta 
(como a gravidade quando está pulando) e exibir a animação certa. Usar 
números "mágicos" (como 0 para parado, 1 para correndo) pode tornar o 
código confuso e difícil de dar manutenção. Uma enum é a ferramenta 
perfeita para representar esses estados de forma clara e organizada.

Tarefa:
Escreva um programa em C que defina os possíveis estados de um personagem de 
jogo e, com base em uma entrada numérica do usuário, identifique e imprima o 
estado atual do personagem.

Requisitos:
Enum para Estados: Crie uma enum chamada EstadoPersonagem que contenha os 
seguintes estados: PARADO, CORRENDO e PULANDO.
Variável de Estado: Dentro da função main, crie uma variável chamada estado_atual 
do tipo enum EstadoPersonagem.
Entrada do Usuário: Peça ao usuário para digitar um número para definir o estado 
do personagem (0 para PARADO, 1 para CORRENDO, ou 2 para PULANDO).
Leitura e Atribuição: Leia o número inteiro digitado pelo usuário e atribua-o à sua variável estado_atual.
Lógica de Decisão: Utilize uma estrutura if-else if-else para verificar o valor da variável estado_atual.
Saída na Tela:Se o estado for PARADO, imprima a mensagem: "O personagem está parado."
Se o estado for CORRENDO, imprima a mensagem: "O personagem está correndo!"
Se o estado for PULANDO, imprima a mensagem: "O personagem está pulando no ar!"
Se o usuário digitar qualquer outro número, imprima: "Estado inválido!"*/
#include <stdio.h>

enum EstadoPersonagem {PARADO, CORRENDO, PULANDO};

int main(){

enum EstadoPersonagem estado_atual;

    printf("Digite o número que define o estado do personagem: 0 para PARADO, 1 para CORRENDO, ou 2 para PULANDO\n");
    scanf("%d", &estado_atual);
    
    if (estado_atual == PARADO){
        printf("O personagem está parado.\n");
    } else if (estado_atual == CORRENDO){
        printf("O personagem está correndo!\n");
    } else if (estado_atual == PULANDO){
        printf("O personagem está pulando no ar!\n");
    } else{
        printf("Estado inválido!\n");
    }
    return 0;
}