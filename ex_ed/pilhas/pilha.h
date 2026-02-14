#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
Pilha* criar_pilha();
int pilha_cheia(Pilha* p);
int pilha_vazia(Pilha* p);
int pop(Pilha* p, int* valor);
int push(Pilha* p, int valor);
void imprimir_pilha(Pilha* p);
void liberar_pilha(Pilha* p);

#endif // PILHA_H