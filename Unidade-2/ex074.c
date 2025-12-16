/*Contexto: Supondo um jogo de estratégia de ficção científica, você controla a "Legião de Ferro". 
Após uma batalha intensa, o sistema de triagem automática precisa reorganizar rapidamente as unidades
mecha com base em seus pontos de vida (HP) restantes. O sistema usa a saúde da última unidade na lista 
como um "limiar de dano" para decidir quem precisa de reparos imediatos.

Tarefa:
Você deve criar um programa em C que leia a quantidade de unidades mecha e, em seguida, os pontos de 
vida de cada uma. O programa deve então particionar o vetor de HP. O pivô para a partição será o valor 
de HP da última unidade lida. Todos os mechas com HP menor que o pivô devem ser movidos para o início 
do vetor, e todos os com HP maior devem ser movidos para o final. O pivô deve ficar posicionado entre 
esses dois grupos. Esta operação deve ser feita "in-place", ou seja, modificando o vetor original sem 
criar um vetor auxiliar, para economizar recursos computacionais críticos no campo de batalha.

Requisitos:
Leia um inteiro n representando o número de unidades mecha.
Leia n inteiros em um vetor, representando os pontos de vida de cada unidade.
Crie uma função void particao(int n, int v[]) que implemente a lógica de particionamento.
O pivô para a partição deve ser sempre o último elemento do vetor (v[n-1]).
A partição deve ser realizada no próprio vetor (in-place).
Após a partição, imprima o vetor resultante com os elementos separados por um espaço.*/
#include <stdio.h>

int particao(int n, int v[]){
    int pivo = v[n - 1];
    int j = -1;
    int i;

    for (i = 0; i < n - 1; i++){
        if (v[i] < pivo){
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[j + 1];
    v[j + 1] = v[n - 1];
    v[n - 1] = temp;
    
    return j + 1; 
}

int main(){
    int n, i;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    int v[n];

    for (i = 0;  i < n; i++){
        scanf("%d", &v[i]);
    }

    particao(n, v);

    printf("Imprimindo o vetor\n");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}
