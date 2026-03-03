#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
// Implementação da fila usando lista encadeada dupla

struct no {
    int valor;
    No* proximo;
    No* anterior;
};
struct fila {
    No* inicio;
    No* fim;
};
Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        return NULL;
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
int fila_cheia(Fila* f) {
    return 0; // Fila encadeada nunca fica cheia
}
int fila_vazia(Fila* f) {
    return f->inicio == NULL;
}
int enfileirar(Fila* f, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        return 0;
    }

    novo_no->valor = valor;

    if (fila_vazia(f)) {
        novo_no->proximo = novo_no;
        novo_no->anterior = novo_no;

        f->inicio = novo_no;
        f->fim = novo_no;
    } else {
        novo_no->proximo = f->inicio;
        novo_no->anterior = f->fim;

        f->fim->proximo = novo_no;
        f->inicio->anterior = novo_no;

        f->fim = novo_no;
    }

    return 1;
}
int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f)) {
        return 0; // Fila vazia
    }
    No* temp = f->inicio;
    *valor = temp->valor;

    if (f->inicio == f->fim) {
        f->inicio = NULL;
        f->fim = NULL; // Fila ficou vazia
    } else {
        f->inicio = f->inicio->proximo; 
        f->inicio->anterior = f->fim;
        f->fim->proximo = f->inicio;
    }

    free(temp);
    return 1; // Desenfileirado com sucesso
}
void imprimir_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    No* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}
void liberar_fila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(f);
}