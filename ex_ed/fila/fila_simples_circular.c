# include <stdio.h>
# include <stdlib.h>
# include "fila.h"

//implementação da fila circular simples

struct no {
    int valor;
    No* proximo;
};
struct fila {
    No* inicio;
    No* fim;
};

Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_cheia(Fila* f) {
    return 0; // A fila circular simples não tem limite de tamanho
}

int fila_vazia(Fila* f) {
    return (f->inicio == NULL);
}

int enfileirar(Fila* f, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        return 0; // Falha ao alocar memória
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo_no;
        f->fim = novo_no;
        f->fim->proximo = f->inicio; // Aponta para o início para formar o círculo
    } else {
        f->fim->proximo = novo_no; // O último nó aponta para o novo nó
        f->fim = novo_no; // O fim agora é o novo nó
        f->fim->proximo = f->inicio; // O novo fim aponta para o início para manter o círculo
    }
    return 1; // Sucesso
}

int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f)) {
        return 0; // Fila vazia, não é possível desenfileirar
    }
    No* temp = f->inicio;
    *valor = temp->valor;

    if (f->inicio == f->fim) { // Apenas um elemento na fila
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        f->inicio = f->inicio->proximo; // O início agora é o próximo nó
        f->fim->proximo = f->inicio; // O fim aponta para o novo início para manter o círculo
    }
    free(temp);
    return 1; // Sucesso
}

void imprimir_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    No* temp = f->inicio;
    do {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    } while (temp != f->inicio); // Continua até voltar ao início
    printf("\n");
}

void liberar_fila(Fila* f) {
    if (f == NULL) {
        return;
    }
    No* temp = f->inicio;
    while (temp != NULL) {
        No* prox = temp->proximo;
        free(temp);
        if (prox == f->inicio) { // Se voltar ao início, a fila foi completamente liberada
            break;
        }
        temp = prox;
    }
    free(f);
}