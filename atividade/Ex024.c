/*Problema: Construindo o Mapa do Jogo Dinamicamente

Contexto: Você foi contratado como programador júnior para um novo jogo de plataforma 2D.
Sua primeira tarefa é criar a base para o sistema de mapas do jogo. Os designers de nívei
querem poder criar mapas de diferentes tamanhos (alguns mais altos, outros mais largos),
então o mapa não pode ter um tamanho fixo no código. O mapa será representado como uma
grade (matriz) onde cada célula é um número inteiro que representa um tipo de bloco:
0: Espaço Vazio
1: Bloco de Tijolo
2: Moeda

Tarefa:
Escreva um programa em C que primeiro pergunte ao usuário as dimensões do mapa (número de linhas e colunas)
e, em seguida, crie dinamicamente este mapa, preencha-o com dados fornecidos pelo usuário e, por fim, conte 
e exiba quantos blocos de tijolo (1) existem no nível.

Requisitos:
Dimensões do Mapa: Peça ao usuário para digitar o número de linhas e o número de colunas do mapa.
Alocação Dinâmica: Crie a matriz do mapa usando alocação dinâmica com um ponteiro para ponteiro 
(int **mapa). Você precisará usar malloc para alocar o vetor de ponteiros (linhas) e, em seguida, 
um laço para alocar cada linha individualmente.
Preenchimento do Mapa: Peça ao usuário para digitar os valores (0, 1 ou 2) para preencher cada
célula do mapa.
Contagem de Blocos: Percorra toda a matriz e conte quantos elementos são iguais a 1 (Bloco de Tijolo).
Exibição do Resultado: Ao final, mostre na tela a contagem total de blocos de tijolo. A saída deve ser: 
"O mapa possui X blocos de tijolo." (onde X é o número contado).
Liberação de Memória: É fundamental que você libere corretamente toda a memória que foi alocada dinamicamente 
antes de o programa terminar. Lembre-se que o processo de liberação é o inverso do de alocação.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

int linhas, colunas;

printf("Insira quantas linhas e colunas terão");
scanf("%i %i", &linhas, &colunas);
int i, j;
int **map = (int **) malloc(i * sizeof(int *));
     if (map == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    for(i = 0; i < linhas; i++){
        map[i] = (int *) malloc(j * sizeof(int));
         if (map[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        
    }
    
    printf("Digite o valor 0/1/2");
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int tijolo = 0;

    
for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%i ",map[i][j]);
            if(map[i][j] == 1){
                tijolo++;
            }
      
    }
      printf("\n");
} 
printf("Há %i tijolos no mapa", tijolo);

for (i = 0; i < linhas; i++) {
        free(map[i]);
    }
    free(map);


    return 0;
}

