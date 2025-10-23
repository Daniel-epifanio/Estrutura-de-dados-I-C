/*Problema: O Diálogo do Final Boss

Contexto: Em um jogo de plataforma, ao chegar na sala do chefe final,
o chefe precisa dizer uma frase específica para o jogador. O motor do
jogo possui uma variável para guardar a fala atual que será exibida na tela.
Para cada evento do jogo (início da luta, jogador com pouca vida, chefe derrotado),
uma frase diferente precisa ser carregada nessa variável de fala. Essa
"carga" é, na verdade, uma cópia de uma string pré-definida para a variável
que controla o diálogo na tela.

Tarefa:
Escreva um programa em C que simule a troca de diálogo do chefe final no início da batalha.

Requisitos:
Frase Padrão do Chefe: Crie uma string (vetor de char) chamada frase_inicio_luta
e inicialize-a com o texto: "Você nunca sairá daqui com vida!".
Caixa de Diálogo: Crie outra string chamada caixa_dialogo com tamanho suficiente
para a frase (ex: 100 caracteres) e inicialize-a com o texto "(Silêncio)".
Imprima o Estado Inicial: Mostre na tela o conteúdo da caixa_dialogo antes
do início da luta. A saída deve ser: Chefe antes da luta: (Silêncio)
Ative o Diálogo: Use a função strcpy() para copiar o conteúdo da
frase_inicio_luta para a caixa_dialogo.
Imprima o Diálogo Ativado: Mostre na tela o novo conteúdo da caixa_dialogo
para confirmar que a frase foi copiada. A saída deve ser: Chefe diz: Você
nunca sairá daqui com vida!*/
#include <stdio.h>
#include <string.h>

int main(){

char frase_inicio_luta[] = "Você nunca sairá daqui com vida!";
char caixa_dialogo[75] = "(Silencio)";

printf("Chefe antes da luta: %s\n", caixa_dialogo);
strcpy(caixa_dialogo, frase_inicio_luta);

printf("Chefe diz: %s\n", caixa_dialogo);



    return 0;
}