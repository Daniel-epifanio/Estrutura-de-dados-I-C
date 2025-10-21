/*Problema: Movimentação do Personagem e Coleta de Moedas

Contexto: Em um jogo de plataforma 2D, o personagem principal precisa se mover pelo cenário 
para coletar moedas. Cada vez que o personagem se move, sua posição (coordenadas X e Y) é 
atualizada. Além disso, precisamos manter um registro de quantas moedas ele já coletou. 
Para organizar esses dados, usaremos uma estrutura que armazena todas as informações do 
personagem. Vamos criar um programa simples que simula a movimentação do personagem e a 
coleta de uma moeda. Para isso, criaremos uma função que recebe o estado atual do personagem, 
atualiza sua posição e incrementa seu contador de moedas.

Tarefa:
Escreva um programa em C que utilize uma estrutura para representar o personagem e uma 
função para atualizar seu estado. Você pode escolher uma das duas abordagens abaixo para 
resolver o problema.

Requisitos principais:
Estrutura do Personagem: Crie uma struct chamada Personagem que contenha os seguintes membros:
int posX; (para a coordenada X)
int posY; (para a coordenada Y)
int moedas; (para o contador de moedas)
Função Principal (main):
- Declare uma variável do tipo struct Personagem chamada jogador.
- Inicialize os valores de jogador: posX = 0, posY = 0 e moedas = 0.
- Imprima na tela o estado inicial do jogador. A saída deve ser: "Posicao inicial: (0, 0) - Moedas: 0"
- Chame a função de atualização (conforme a opção escolhida).
- Após a chamada da função, imprima o estado final do jogador. A saída deve ser: "Posicao atualizada: (10, 5) - Moedas: 1"
Opção 1: Solução com Passagem por Valor (Baseada nesta Aula 32)
Neste método, a função recebe uma cópia da estrutura, modifica e retorna a estrutura atualizada.
Função de Atualização: Crie uma função chamada atualizarPersonagem.
- Ela deve retornar uma struct Personagem.
- Ela deve receber como parâmetro uma struct Personagem (uma cópia). 
(Dica: struct Personagem atualizarPersonagem(struct Personagem p))
- Dentro da função, modifique os dados da cópia recebida:
    - Altere p.posX para 10 e p.posY para 5.
    - Incremente p.moedas em 1.
- Ao final, retorne a estrutura modificada com o comando return p;.
Chamada na main: Na função main, você deve atualizar a variável jogador com o retorno da função: 
jogador = atualizarPersonagem(jogador);
*/
#include <stdio.h>

typedef struct
{
  int pos_x;
  int pos_y;
  int moedas;
}personagem;

personagem atualizarPersonagem(personagem jogador);


int main(){

personagem jogador;
jogador.pos_x = 0;
jogador.pos_y = 0;
jogador.moedas = 0;

printf("Posicao inicial: (%d, %d) - Moedas: %d\n", jogador.pos_x, jogador.pos_y, jogador.moedas);

jogador = atualizarPersonagem(jogador);

printf("Posicao atualizada: (%d, %d) - Moedas: %d\n", jogador.pos_x, jogador.pos_y, jogador.moedas);
    return 0;
}

personagem atualizarPersonagem(personagem jogador){
    jogador.pos_x = 10;
    jogador.pos_y = 5;
    jogador.moedas += 1;

    return jogador;

}