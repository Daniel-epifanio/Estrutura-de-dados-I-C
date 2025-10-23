#include <stdio.h>
#include <string.h>

int main(){

    char nome1[50];
    char nome2[50];
    char nome3[50];

    printf("informe os nomes:\n");
    
    scanf("%s %s %s", nome1, nome2, nome3);
    printf("Nomes informados: %s %s %s", nome1, nome2, nome3);
    char menor[50];
    char segundo[50];
        if(strcmp(nome1, nome2) < 0){
            strcpy(menor, nome1);
             strcpy(segundo, nome2);
        }
        else{
             strcpy(menor, nome2);
             strcpy(segundo, nome1);
        }
        if(strcmp(nome3, menor) < 0){
            printf("%s\n%s\n%s\n", nome3, menor, segundo);
        }
        else if(strcmp(nome3, menor) < 0){
            printf(" %s\n %s\n%s\n", menor, nome3, segundo);
            
        }
        else{
            printf(" %s\n %s\n%s\n", menor, segundo, nome3);
        }
    return 0;
}