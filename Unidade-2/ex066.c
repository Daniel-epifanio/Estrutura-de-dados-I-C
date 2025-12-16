/*Contexto: Você está desenvolvendo um jogo de arena de batalha. Ao final de cada partida, 
o sistema precisa exibir o placar final, mostrando os jogadores ordenados da maior para a menor 
pontuação. Isso cria um ranking claro e incentiva a competição. Você foi encarregado de implementar a 
lógica de ordenação do placar.

Tarefa:
Escreva um programa em C que primeiro leia um número inteiro N, representando a quantidade de 
jogadores na partida. Em seguida, leia N pontuações inteiras (uma para cada jogador). Utilizando 
o algoritmo Bubble Sort (ordenação por trocas sucessivas) apresentado na aula, ordene essas 
pontuações em ordem decrescente (da maior para a menor). Por fim, imprima a lista de pontuações já ordenada.

Requisitos:
O programa deve ler o número de jogadores N e, em seguida, as N pontuações.
É obrigatório o uso do algoritmo Bubble Sort para a ordenação.
A ordenação deve ser em ordem decrescente.
A saída final deve ser uma única linha contendo as pontuações ordenadas, separadas por um espaço. Por exemplo: 1500 1250 1100 980 750
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *vetooor = malloc(n*sizeof(int)); 

    for(i = 0; i < n; i++){
        scanf("%d", &vetooor[i]);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(vetooor[j] > vetooor[j + 1]){
                int temp = vetooor[j];
                vetooor[j] = vetooor[j + 1];
                vetooor[j + 1] = temp;
            }
        }
    }

    printf("Vetor Ordenado\n");
    for ( i = 0; i < n; i++){
        printf("%d ", vetooor[i]);
    }

    free(vetooor);

    return 0;
    
}