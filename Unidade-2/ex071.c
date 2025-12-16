/*Contexto: Em um jogo de estratégia espacial, sua frota de naves de combate é controlada por uma IA (Inteligência Artificial) avançada. Em uma batalha, o sistema de radar detecta múltiplos alvos inimigos, cada um com um 'nível de ameaça' calculado com base em seu poder de fogo, velocidade e blindagem. Para maximizar a eficácia em combate, a IA precisa ordenar a lista de alvos de forma que as naves foquem fogo nos inimigos de menor ameaça primeiro, eliminando-os rapidamente antes de passar para os alvos mais perigosos.

Tarefa:
Você deve implementar o módulo de priorização de alvos da IA. Seu programa lerá os dados de 'N' naves inimigas (ID e nível de ameaça) e, em seguida, usará o algoritmo Merge Sort para ordenar a lista de inimigos com base no nível de ameaça, em ordem crescente. Ao final, o programa deve imprimir a sequência de IDs das naves inimigas já ordenadas por prioridade.

Requisitos:
Utilize uma struct para representar cada nave inimiga, contendo um campo para o id (inteiro) e outro para o nivel_ameaca (inteiro).
O programa deve primeiro ler um número inteiro N, que representa a quantidade de naves inimigas.
Em seguida, leia os dados (id e nivel_ameaca) para cada uma das N naves e armazene-os em um vetor de structs.
Implemente o algoritmo de ordenação Merge Sort para ordenar o vetor de naves com base no campo nivel_ameaca.
Após a ordenação, imprima na tela apenas os ids das naves, separados por um espaço, na nova ordem de prioridade (do menor para o maior nível de ameaça).*/
#include <stdio.h>

void intercala(int e, int m, int d, int v[]){
    int n1 = (m - e) + 1;
    int n2 = (d - m);
    int k = e;
    int E[n1];
    int D[n2];
    int i, j;
    for(i = 0; i < n1; i++){
        E[i] = v[e + i];
    }

    for(j = 0; j < n2; j++){
        D[j] = v[m + 1 + j];
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2){
        if(E[i] < D[j]){
            v[k] = E[i];
            i++;
        }
        else{
            v[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        v[k] = E[i];
        i++;
        k++;
    }

    while (j < n2){
        v[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int i, int f, int v[]){
    if(i < f){
        int meio = (i + f)/2;
        mergeSort(i, meio, v);
        mergeSort(meio + 1, f, v);
        intercala(i, meio, f, v);
    }
}

int main(){
    int n, i;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    int v[n];

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergeSort(0, n - 1, v);
    
    printf("Imprimindo o vetor ordenado\n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    
}