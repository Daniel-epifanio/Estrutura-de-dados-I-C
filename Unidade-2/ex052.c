/*Contexto: Em um jogo de estratégia como 'Warfront Tactics', uma unidade de artilharia 
pode lançar um poderoso ataque de área de efeito (AoE - Area of Effect). Para que este 
ataque seja eficiente, a IA (Inteligência Artificial) do jogo precisa identificar grupos 
de inimigos que estão agrupados. Um agrupamento é definido como qualquer par de unidades 
inimigas que estejam a uma distância menor ou igual a um determinado 'raio de explosão' 
uma da outra.

Tarefa: Escreva um programa em C que primeiro leia o número de unidades inimigas n no 
campo de batalha. Em seguida, para cada uma das n unidades, o programa deve ler suas 
coordenadas (x, y). Por fim, o programa deve ler um valor de ponto flutuante para o 
'raio de explosão'. Sua tarefa é calcular e informar quantas duplas distintas de inimigos 
estão dentro desse raio de explosão uma da outra. A análise de todas as duplas resultará 
em um algoritmo de complexidade quadrática.

Requisitos:
Crie uma struct chamada Unidade para armazenar as coordenadas x e y (ambas inteiras) de cada inimigo.
Use malloc() para alocar dinamicamente um vetor de structs para armazenar os dados de todas as n unidades.
Utilize laços aninhados para comparar cada unidade com todas as outras unidades. 
Evite comparar uma unidade com ela mesma e evite contar o mesmo par duas vezes 
(por exemplo, se já comparou a unidade A com a B, não precisa comparar a B com a A).
Para calcular a distância entre dois pontos (x1, y1) e (x2, y2), utilize a fórmula: 
distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)). Para isso, você precisará 
incluir a biblioteca <math.h> e compilar com a flag -lm se estiver no Linux/GCC.
Conte quantas duplas de unidades têm uma distância entre si menor ou igual ao raio fornecido.
Ao final, imprima a contagem total de duplas próximas.
Lembre-se de liberar a memória alocada dinamicamente com free() antes de encerrar o programa.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}Unidade;

int main(){
int n;
printf("Digite quantas unidades inimigas\n");
scanf("%d", &n);
Unidade *unidades = malloc(n * sizeof(Unidade));
for(int i = 0; i < n; i++){
printf("Digite x e y da unidade %d", i + 1);
scanf("%d %d", unidades[i].x, unidades[i].y);
}
   float raio;
    printf("Digite o raio de explosao: ");
    scanf("%f", &raio);
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; i++)
        {
            float distancia = sqrt
                (pow (unidades[j].x - unidades[i].x, 2) + pow (unidades[j].y - unidades[i].y, 2));
                if(distancia <= raio){
                    cont++;
                }
        }     
    }
    printf("Total de duplas proximas: %d\n", cont);
    free(unidades);
    return 0;
}