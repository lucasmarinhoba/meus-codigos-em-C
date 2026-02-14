#include "pilha.h"
#include <stdlib.h>

// Implementação de uma pilha usando um vetor dinâmico.

struct pilha{
    int* elementos;
    int indice;
    int capacidade;
};

Pilha* criar_pilha(int valor){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (!p){ free(p); return NULL;}

    p->elementos = (int*)malloc(sizeof(int) * valor);
    p->indice = -1;
    p->capacidade = valor;
    return p;
}

int pilha_cheia (Pilha* p){
    if (!p) return -1;
    return p->indice == p->capacidade - 1;
}

int pilha_vazia (Pilha* p){
    if (!p) return -1;
    return p->indice == -1;
}

int pop(Pilha* p, int* valor){
    if (!p || pilha_vazia(p)) return 0;
    *valor = p->elementos[p->indice];
    p->indice--;    
    return 1;
}

int push(Pilha* p, int valor){
    if (!p) return 0;
    if (pilha_cheia(p)){
        int* aux = (int*)realloc(p->elementos, sizeof(int) * 2*p->capacidade);
        if ( aux == NULL){
            return 0;
        }
        p->capacidade *= 2;

    }
    p->indice++;
    p->elementos[p->indice] = valor;
    return 1;
}

void imprimir_pilha(Pilha* p){
    if (!p) return;
    for (int i = p->indice; i >= 0; i--){
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

void liberar_pilha(Pilha* p){
    if (p){
        free(p->elementos);
        free(p);
    }
}