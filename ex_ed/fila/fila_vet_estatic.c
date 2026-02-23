#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MAX 100

// Implementação da fila usando vetor estático

struct fila {
    int dados[MAX];
    int inicio;
    int fim;
};

Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        return NULL;
    }
    f->inicio = 0;
    f->fim = 0;
    return f;
}

int fila_cheia(Fila* f) {
    return (f->fim + 1) % MAX == f->inicio;
}

int fila_vazia(Fila* f) {
    return f->inicio == f->fim;
}
int enfileirar(Fila* f, int valor) {
    if (fila_cheia(f)) {
        return 0; // Fila cheia
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    return 1; // Enfileirado com sucesso
}

int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f)) {
        return 0; // Fila vazia
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return 1; // Desenfileirado com sucesso
}
void imprimir_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->inicio; i != f->fim; i = (i + 1) % MAX) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

void liberar_fila(Fila* f) {
    free(f);
}

