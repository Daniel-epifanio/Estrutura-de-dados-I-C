/*
Contexto: Em um jogo de plataforma, o arquivo level_1_map.dat contém os dados essenciais 
para construir a primeira fase. Se este arquivo estiver faltando ou corrompido, o jogo não 
pode ser iniciado e deve informar ao jogador exatamente qual foi o problema, em vez de 
simplesmente travar. Um bom tratamento de erros é crucial para a experiência do usuário.

Tarefa:
Crie um programa em C que simule a tentativa de carregar este arquivo de mapa. Como o 
arquivo não existirá, o programa deve detectar o erro na abertura, exibir uma mensagem 
de erro personalizada e, em seguida, usar a função perror() para mostrar a mensagem de 
erro específica do sistema operacional, que é mais técnica e útil para os desenvolvedores.

Requisitos:

Tente abrir um arquivo chamado level_1_map.dat no modo de leitura ("r").
Verifique se o ponteiro retornado por fopen() é NULL.
Se for NULL, imprima a mensagem de erro personalizada: ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n.
Imediatamente após a mensagem personalizada, chame a função perror() para exibir a mensagem de erro do sistema. 
A string passada para perror deve ser Detalhes do erro.
O programa deve encerrar com um status de erro (usando exit(1)) após exibir as mensagens, para sinalizar que a operação falhou.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("level_1_map.dat", "r");
    if(file == NULL){
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        perror("A operacao falhou");
        exit(1);
    }
}