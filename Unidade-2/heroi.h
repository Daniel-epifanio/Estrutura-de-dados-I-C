#ifndef HEROI_H
#define HEROI_H

typedef struct heroi heroi;

heroi* cria(int n);

void ler(int n, heroi *v);

void imprimir(int n, heroi *v);

#endif