#include <stdio.h>

int main(){

int vet[10],posicao = 0, i, menor;

for(i = 0; i < 10; i++){
    scanf("%d", &vet[i]);
    if(i == 0){
        menor = vet[i];
        posicao = i;
    }
    else if (vet[i] < menor){
        menor = vet[i];
        posicao = i;
    }
}
    printf("o menor valor é: %d\n", menor);
    printf("a posicao é : %d\n", posicao);
    return 0;
}