/*Contexto: Você está desenvolvendo o sistema de placar para um jogo de corrida futurista. 
Ao final de cada corrida, o sistema recebe os dados dos pilotos (nome e sua posição final 
de chegada) de forma desordenada. Para exibir o pódio e a classificação final na tela, é 
crucial que esses dados sejam ordenados com base na posição de chegada, do primeiro ao 
último colocado.

Tarefa:
Crie um programa em C que leia o número de pilotos em uma corrida, seguido dos dados de cada piloto 
(posição de chegada e nome). Utilize o algoritmo de ordenação por intercalação (Merge Sort) para 
organizar a lista de pilotos em ordem crescente de sua posição final. Ao final, o programa deve 
imprimir a lista ordenada, mostrando a posição e o nome de cada piloto.

Requisitos:
Utilize uma struct chamada Piloto para armazenar a posicao (inteiro) e o nome (string) de cada competidor.
Implemente a lógica do Merge Sort de forma recursiva, com uma função mergeSort para dividir o vetor e uma função intercala para combinar as metades ordenadas.
A ordenação deve ser baseada no campo posicao da struct.
O programa deve ler primeiro o número total de pilotos e, em seguida, os dados de cada um (posição e nome).
Após a ordenação, imprima a lista final no formato posicao nome para cada piloto, um por linha.*/
#include <stdio.h>

typedef struct{
    int posicao;
    char nome[50];
} Piloto;

void intercala(int e, int m, int d, Piloto v[]){
    int n1 = (m - e) + 1;
    int n2 = d - m;
    int k = e;
    Piloto E[n1];
    Piloto D[n2];
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
        if(E[i].posicao < D[j].posicao){
            v[k] = E[i];
            i++;
        }else{
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

void mergeSort(int i, int f, Piloto v[]){
    if(i < f){
        int meio = (i + f)/2;
        mergeSort(i, meio, v);
        mergeSort(meio + 1, f, v);
        intercala(i, meio, f, v);
    }
}

void ler(Piloto *pilotos){
    scanf("%s %d", &pilotos->nome, &pilotos->posicao);
}

int main(){
    int n, i;
    printf("Informe o valor de n\n");
    scanf("%d", &n);

    Piloto pilotos[n];

    for(i = 0; i < n; i++){
        ler(&pilotos[i]);
    }

    mergeSort(0, n - 1, pilotos);

    printf("Imprimindo os Pilotos\n");

    for(i = 0; i < n; i++){
        printf("%s %d\n", pilotos[i].nome, pilotos[i].posicao);
    }
    return 0;
}