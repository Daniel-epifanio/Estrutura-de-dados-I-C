/*Contexto: Supondo que você é o desenvolvedor de ferramentas para um novo RPG de fantasia. 
O Mestre do Jogo (Game Master) precisa de um programa de console simples para consultar 
rapidamente os dados dos personagens dos jogadores durante uma sessão ao vivo. Cada personagem 
possui uma ID única, um nome e três atributos principais: Força, Agilidade e Inteligência.

Tarefa:
Crie um programa em C que primeiro leia o número total de personagens na campanha. 
Em seguida, para cada personagem, o programa deve ler sua ID (um inteiro), seu nome 
(uma única palavra) e os valores de seus três atributos (Força, Agilidade, Inteligência). 
Após registrar todos os personagens, o programa deve entrar em um loop de menu com duas opções:

1 - Consultar Personagem: O Mestre do Jogo digita a ID de um personagem. O programa deve 
buscar este personagem na lista. Se encontrado, deve exibir o nome do personagem e sua 
'Média de Atributos', calculada como a média simples dos seus três atributos. Se não for 
encontrado, deve informar que o personagem não existe.
2 - Sair: Encerra o programa.

O menu de consulta deve ser reapresentado após cada busca, permitindo que o Mestre do Jogo faça múltiplas consultas até decidir sair.

Requisitos:
Use uma struct para representar os dados de um personagem (ID, nome, 3 atributos).
Armazene os personagens em um vetor de structs.
Implemente uma função de busca linear para encontrar um personagem pela sua ID.
O programa deve continuar oferecendo a opção de busca até que a opção '2' (Sair) seja selecionada.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    int forca; 
    int agilidade; 
    int inteligencia;
} Personagem;

void ler_dados(Personagem *per){
    scanf("%d %s %d %d %d", &per->id, per->nome, &per->forca, &per->agilidade, &per->inteligencia);
}

void menu(){
    printf("======================= Escolha uma opção =======================\n");
    printf("1 - Pesquisar\n");
    printf("2 - Finalizar\n");
    printf("================================================================\n");
}

int pesquisar(int id, int n, Personagem per[]){
    for (int i = 0; i < n; i++){
        if(per[i].id == id){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    Personagem *personagens = malloc(n * sizeof(Personagem));
    for (int i = 0; i < n; i++){
        ler_dados(personagens + i);
    }
    
    int operacao;
    menu();
    scanf("%d", &operacao);
    while (operacao != 2){
        if (operacao == 1)
        {
            int id;
            printf("Insira o ID do personagem\n");
            scanf("%d", &id);
            int idx = pesquisar(id, n, personagens);
            if (idx != -1){
                int media = ((personagens + idx)->forca + (personagens + idx)->agilidade + (personagens + idx)->inteligencia)/3;

                printf("%d %s %i\n", (personagens + idx)->id, (personagens + idx)->nome, media );
            }           
        }        
        menu();
        scanf("%d", &operacao);
    }
    printf("Programa Finalizado!");
    
    return 0;
}