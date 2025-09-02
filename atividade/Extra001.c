#include <stdio.h>

int main(){

int n, i, p = 0;

printf("Digite 5 números inteiros");
    for(i = 0; i < 5; i++){
        scanf("%d", &n);
        if( n%2 == 0){
           p += 1;
        }
    }
          printf("%d valores pares", p);

    return 0;
}