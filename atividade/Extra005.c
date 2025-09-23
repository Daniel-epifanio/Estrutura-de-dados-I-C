#include <stdio.h>

int main() {
    float a1[3];
    float a2[3];
    float a3[3];

    float *alunos[3] = {a1, a2, a3}; 

    int i, j;
    int contador = 0;   
    float maior;        

    printf("Informe as notas dos 3 alunos (cada um com 3 notas):\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%f", &alunos[i][j]);
        }
    }

    maior = alunos[0][0];
   
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (alunos[i][j] >= 7.0) {
                contador++;
            }
            if (alunos[i][j] > maior) {
                maior = alunos[i][j];
            }
        }
    }

    printf("\nQuantidade de notas maiores ou iguais a 7.0: %d\n", contador);
    printf("Maior nota encontrada: %.2f\n", maior);

    return 0;
}
