/*Contexto: Em um jogo de defesa de torre (Tower Defense), os inimigos avançam em direção à sua base a partir de dois portais de invocação distintos, o Portal Alfa e o Portal Beta. Para otimizar o posicionamento das torres, o sistema de defesa precisa de uma lista unificada e ordenada de todas as unidades inimigas que se aproximam, classificadas por seu 'nível de ameaça'.

Cada portal gera sua própria onda de inimigos, e a lista de inimigos de cada portal já está ordenada de forma crescente pelo nível de ameaça. Sua missão é criar um programa que leia as duas listas de inimigos e as intercale em uma única lista, mantendo a ordem crescente de ameaça.

Tarefa:
Você deve criar um programa em C que leia os dados de duas ondas de inimigos (Portal Alfa e Portal Beta). Para cada onda, o programa primeiro lerá o número de inimigos e, em seguida, o nível de ameaça de cada um. Assuma que os níveis de ameaça em cada onda de entrada já estão ordenados de forma crescente.

O programa deve então criar uma terceira lista que intercala as duas ondas, resultando em uma única lista com todos os inimigos, também ordenada de forma crescente pelo nível de ameaça. Finalmente, o programa deve imprimir esta lista final e ordenada.

Requisitos:
Leia um inteiro n representando o número de inimigos do Portal Alfa.
Leia n inteiros (níveis de ameaça) e armazene-os em um primeiro vetor.
Leia um inteiro m representando o número de inimigos do Portal Beta.
Leia m inteiros (níveis de ameaça) e armazene-os em um segundo vetor.
Crie um terceiro vetor com tamanho n + m.
Implemente a lógica de intercalação (merge) para combinar os dois vetores ordenados no terceiro vetor, mantendo a ordem.
Imprima os elementos do terceiro vetor, separados por um espaço.*/
#include <stdio.h>

void intercalando(int n, int v1[], int m, int v2[], int r[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m){
        if (v1[i] < v2[j]){
            r[k] = v1[i];
            i++;
        }
        else{
            r[k] = v2[j];
            j++;
        }
        k++;
    }
    while (i < n){
        r[k] = v1[i];
        i++;
        k++;
    }
    while (j < m){
        r[k] = v2[j];
        j++;
        k++;
    }
}

int main(){
    int n, i;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int v1[n];
    for (i = 0; i < n; i++){
        scanf("%d", &v1[i]);
    }
    int m;
    printf("Informe o valor de m:\n");
    scanf("%d", &m);
    int v2[m];
    for (i = 0; i < m; i++){
        scanf("%d", &v2[i]);
    }
    int r[n + m];
    intercalando(n, v1, m, v2, r);
    for (i = 0; i < m + n; i++){
        printf("%d ", r[i]);
    }
    
    return 0;
}