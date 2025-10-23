#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("=== escolha uma opcao ===\n");
    printf("1 - cadastrar\n");
    printf("2 - listar\n");
    printf("3 - editar\n");
    printf("...\n");
    printf("0 - sair\n");
    printf("==========================\n");
}

struct estudante {
  int mat;
  char nome[10];
  float ns[3];
};

void cadastrar(struct estudante *e) {
    printf("Informe os dados do estudante:\n");
    scanf("%d %s %f %f %f", &e->mat, e->nome, &e->ns[0], &e->ns[1], &e->ns[2]);
}

void listar(struct estudante *e, int n) {
    printf("Lista de estudantes:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %s %f %f %f\n", e[i].mat, e[i].nome, e[i].ns[0], e[i].ns[1], e[i].ns[2]);
    }
}

void editarNota(struct estudante *e, int n, int mat) {
    int i;
    for (i = 0; i < n; i++) {
        if (e[i].mat == mat) {
            printf("Informe a nota a ser editada:\n");
            printf("1 - nota 1\n");
            printf("2 - nota 2\n");
            printf("3 - nota 3\n");
            int nota;
            scanf("%d", &nota);
            float novaNota;
            printf("Informe a nova nota %d do aluno:\n", nota);
            scanf("%f", &novaNota);
            if (nota < 1 || nota > 3) {
                printf("Nota informada invalida:\n");
            }
            e[i].ns[nota - 1] = novaNota;
        }
    }
}

int main() {
    int op;
    menu();
    scanf("%d", &op);
    int max = 10;
    int n = 0;
    struct estudante e[max];
    while (op != 0) {
        if (op == 1) {
            cadastrar(&e[n]);
            n++;
        }
        else if (op == 2) {
            listar(e, n);
        }
        else if (op == 3) {
            printf("Informe a matricula:\n");
            int mat;
            scanf("%d", &mat);
            editarNota(e, n, mat);
        }
        menu();
        scanf("%d", &op);
    }
    
    return 0;
}