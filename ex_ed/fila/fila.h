#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
typedef struct fila Fila;
typedef struct no No;
Fila* criar_fila();
int fila_cheia(Fila* f);
int fila_vazia(Fila* f);
int enfileirar(Fila* f, int valor);
int desenfileirar(Fila* f, int* valor);
void imprimir_fila(Fila* f);
void liberar_fila(Fila* f);

#endif // FILA_H