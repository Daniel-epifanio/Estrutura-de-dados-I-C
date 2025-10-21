/*Problema: O Gerenciamento de Atributos do Herói no Jogo

Contexto: Em um jogo de plataforma, seu herói possui atributos essenciais como saúde, 
pontuação de jogo e sua posição no mapa (coordenadas X e Y). Para garantir que o jogo 
seja fluído e responsivo, o "motor" do jogo precisa ser extremamente eficiente na forma 
como acessa e modifica esses atributos na memória. Em C, uma técnica comum para isso é 
usar ponteiros para manipular diretamente os dados do herói, evitando cópias 
desnecessárias e garantindo que as alterações sejam instantâneas e reflitam o estado 
real do herói.

Tarefa:
Escreva um programa em C que simule a gestão dos atributos do seu herói em um jogo 
de plataforma, utilizando o conceito de estruturas e ponteiros para manipular esses 
dados de forma eficiente.

Requisitos:
Definição da Estrutura Heroi:
- Crie uma estrutura chamada Heroi.
- Esta estrutura deve conter os seguintes membros inteiros:
    saude (inicialize com 100)
    pontuacao (inicialize com 0)
    posX (posição horizontal, inicialize com 0)
    posY (posição vertical, inicialize com 0)
Criação e Inicialização do Herói:
- No main, declare uma variável do tipo struct Heroi e chame-a de meuHeroi.
- Inicialize meuHeroi com os valores padrão especificados acima (saúde 100, pontuação 0, posX 0, posY 0).
- Imprima na tela o estado inicial do herói (saúde, pontuação, posX, posY) usando os membros diretos da estrutura.
Criação do Ponteiro para o Herói:
- Declare uma variável do tipo "ponteiro para struct Heroi" e chame-a de ptrHeroi.
- Faça ptrHeroi apontar para o endereço de memória de meuHeroi.
Simulação de Ações no Jogo (usando o ponteiro):
- Sofrer Dano: Simule o herói sofrendo dano. Use ptrHeroi para diminuir a saude 
do herói em 25 pontos. Após a alteração, imprima a nova saude usando o ponteiro.
- Coletar Moedas: Simule o herói coletando moedas. Use ptrHeroi para aumentar 
a pontuacao do herói em 50 pontos. Após a alteração, imprima a nova pontuacao 
usando o ponteiro.
- Mover Herói: Simule o herói se movendo. Use ptrHeroi para aumentar posX em 10 
e diminuir posY em 5. Após a alteração, imprima as novas coordenadas (posX, posY) 
usando o ponteiro.
Impressão Final do Estado:Após todas as simulações, imprima o estado final 
completo do herói (saúde, pontuação, posX, posY) na tela. Desta vez, todos 
os valores devem ser acessados e impressos apenas através do ponteiro ptrHeroi, 
utilizando o operador ->.*/
#include <stdio.h>

typedef struct{
int saude;
int pontuacao;
int pos_x;
int pos_y;
}heroi;

int main(){

heroi meuheroi;
meuheroi.saude = 100;
meuheroi.pontuacao = 0;
meuheroi.pos_x = 0;
meuheroi.pos_y = 0;

printf("saude: %d pontuacao: %d posicao x: %d posicao y: %d\n", meuheroi.saude, meuheroi.pontuacao, meuheroi.pos_x, meuheroi.pos_y);

heroi *ptrheroi = &meuheroi;

ptrheroi -> saude -= 25;
printf("O Heroi perdeu 25 de vida, vida atual: %d\n", ptrheroi->saude);

ptrheroi -> pontuacao += 50;
printf("O Heroi achou 50 moedas! Pontuacao atual: %d\n", ptrheroi->pontuacao);

ptrheroi ->pos_x += 10;
ptrheroi ->pos_y -= 5;
printf("O Heroi caminhou! posicao atual: X = %d Y = %d\n", ptrheroi->pos_x, ptrheroi->pos_y);

printf("Saude: %d Pontuacao: %d Posicao X: %d Posicao Y: %d\n",ptrheroi->saude, ptrheroi->pontuacao, ptrheroi->pos_x, ptrheroi->pos_y);
    return 0;
}
