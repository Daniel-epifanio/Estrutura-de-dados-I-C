/*Contexto: Em um jogo online competitivo, o sistema de matchmaking é responsável 
por criar partidas equilibradas. Para isso, ele utiliza o MMR (Matchmaking Rating) 
de cada jogador, um número que representa sua habilidade. Antes de formar as equipes, 
o sistema precisa pegar um grupo de jogadores da fila e ordená-los por seu MMR para 
encontrar oponentes de nível similar.

Tarefa: Você deve implementar o algoritmo de ordenação Quick Sort para organizar uma 
lista de MMRs de jogadores. O programa lerá o número de jogadores na fila e, em seguida, 
os MMRs de cada um. Ao final, deverá exibir a lista de MMRs ordenada em ordem crescente.

Requisitos:
O programa deve primeiro ler um número inteiro N, que representa a quantidade de jogadores.
Em seguida, deve ler N números inteiros, que são os MMRs dos jogadores.
O programa deve obrigatoriamente implementar o algoritmo Quick Sort de forma recursiva para ordenar os MMRs.
Utilize o esquema de partição de Lomuto (pivô como último elemento) visto na aula.
Ao final, o programa deve imprimir os MMRs ordenados em uma única linha, separados por espaços.*/
#include <stdio.h>

int particao(int e, int d, int v[]){
    int pivo = v[d];
    int j = e - 1;
    int i;

    for (i = 0; i < d; i++){
        if (v[i] <= pivo){
            j++;
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }

    int temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;

    return j + 1;
}


void quicksort(int i, int f, int v){
    if (i < f){
        int p = particao(i, f, v);
        quicksort(i, p - 1, v);
        quicksort(p + 1, f, v);
    }

}


int main(){
    int n, i;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);

    int v[n];
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    quicksort(0, n-1, v);

    printf("Inprimindo o resultado:\n");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;


}