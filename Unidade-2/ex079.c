/*Contexto: Suponha que você esta desenvolvendo um RPG tático, o sistema de gerenciamento da equipe 
(party) precisa ser robusto e reutilizável. Atualmente, toda a lógica para criar, ler e exibir os 
heróis está misturada no arquivo main.c, tornando o código confuso e difícil de expandir. Para preparar 
o jogo para futuras funcionalidades (como sistemas de inventário, habilidades, etc.), você precisa 
refatorar o código, isolando toda a lógica relacionada aos heróis em seu próprio módulo.

Tarefa: 
Você deve criar um programa que permita ao jogador montar sua equipe de heróis para uma nova missão. 
O programa primeiro pergunta quantos heróis farão parte da equipe, depois lê os dados de cada um 
(nome, pontos de vida - HP, e poder de ataque) e, finalmente, exibe o 'roster' (lista da equipe) completo.

Requisitos:
Crie um módulo chamado 'heroi'. Dentro de um diretório com este nome, você deve criar dois arquivos: heroi.h e heroi.c.
No arquivo heroi.h (a interface), você deve:
- Definir um tipo Heroi usando typedef e uma declaração de struct incompleta (opaque type), para esconder os detalhes da implementação.
- Declarar os protótipos de três funções que operarão sobre os heróis: uma para alocar dinamicamente um vetor de heróis, uma para ler os dados dos heróis, e uma para imprimir os dados.
No arquivo heroi.c (a implementação), você deve:
- Incluir o seu próprio cabeçalho heroi.h.
- Definir a struct heroi completa com os campos: nome (string), hp (inteiro) e ataque (inteiro).
- Implementar as três funções cujos protótipos foram declarados no arquivo .h.
No arquivo main.c, você deve:
- Incluir o cabeçalho heroi/heroi.h.
- Conter apenas a lógica principal: ler a quantidade de heróis, chamar as funções do módulo heroi para criar o vetor, preenchê-lo com dados e imprimi-lo na tela.*/
#include <stdio.h>
#include "heroi/heroi.h"
#include <stdlib.h>

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);

    heroi *v = cria(n);

    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    ler(n, v);
    imprimir(n, v);

    free(v);
    return 0;
}