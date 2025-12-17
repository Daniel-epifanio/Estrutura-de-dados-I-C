/*Contexto: Suponha um jogo de corrida arcade, o placar de pontuações precisa ser atualizado 
instantaneamente após cada partida. O placar sempre exibe os scores em ordem decrescente 
(do maior para o menor). O algoritmo Bubble Sort padrão funciona, mas pode causar um pequeno 
atraso, especialmente se um novo jogador obtiver uma pontuação baixa e a maior parte da lista 
já estiver ordenada. Para manter a experiência do jogador fluida, o processo de ordenação precisa 
ser o mais rápido possível.

Tarefa:
Sua tarefa é criar um programa que leia uma lista de pontuações e as ordene usando uma 
versão otimizada do algoritmo Bubble Sort. Esta versão deve ser inteligente o suficiente 
para parar de executar assim que a lista estiver completamente ordenada, sem a necessidade 
de percorrer o vetor desnecessariamente até o final.

Requisitos:
Leia um número inteiro n, que representa a quantidade de jogadores na partida.
Leia n pontuações inteiras e armazene-as em um vetor.
Implemente o algoritmo Bubble Sort otimizado, que utiliza uma variável de controle (flag) para verificar se alguma troca foi realizada durante uma passagem completa pelo vetor.
Se uma passagem inteira for concluída sem nenhuma troca, o algoritmo deve ser interrompido imediatamente.
Ao final, imprima as pontuações ordenadas em ordem decrescente, separadas por um espaço, seguidas de uma quebra de linha.*/
#include <stdio.h>
#include <stdlib.h>

void bolha(int n, int v[]){
    int i, j;
    for(i = 0; i < n; i++){
        int trocou = 0;
        for(j = 0; j < n - 1; j++){
            if(v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if(trocou == 0){
            return;
        }
    }
}

int main(){
    int n, i;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *vetor = malloc(n*sizeof(int)); 

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    bolha(n, vetor);

    for ( i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    
    return 0;
    
}