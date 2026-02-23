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
        return 0; // Falha ao alocar memória
    }
    novo_no->valor = valor;
    if (fila_vazia(f)) {
        novo_no->proximo = NULL;
        novo_no->anterior = NULL;
        f->inicio = novo_no;
        f->fim = novo_no;
    }
    novo_no->proximo = NULL;
    novo_no->anterior = f->fim;
    f->fim->proximo = novo_no;
    f->fim = novo_no;
    
    return 1; // Enfileirado com sucesso
}

int desenfileirar(Fila* f, int* valor){
    if (fila_vazia(f)){
        return 0; // Fila vazia
    }

    No* temp = f->inicio;
    *valor = temp->valor;
    if (f->inicio == f->fim){
        f->inicio = NULL;
        f->fim = NULL; // Fila ficou vazia
        free(temp);
        return 1;
    }
    f->inicio = f->inicio->proximo;
    f->inicio->anterior = NULL;
    free(temp);
    return 1; // Desenfileirado com sucesso
}

void imprimir_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    No* atual = f->inicio;
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