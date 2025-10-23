#include <stdio.h>
#include <locale.h>

int main(){

setlocale(LC_ALL, "Portuguese");

int tesouro_local = 0;
int *ps = &tesouro_local;

printf("O tesouro ainda nao apareceu. Valor: %d \n", *ps);
*ps = 1;
printf("O personagem pisou na plataforma secreta! O tesouro apareceu! Valor: %d\n", *ps);





return 0;
}