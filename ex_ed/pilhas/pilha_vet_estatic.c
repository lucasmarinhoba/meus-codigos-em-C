#include "pilha.h"
#include <stdlib.h>
#define MAX 100

// Implementação de uma pilha usando um vetor estático.

struct pilha {
    int indice;
    int elementos[MAX];
};

Pilha* criar_pilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (!p){ return NULL;}
    p->indice = -1;
    return p;
}

int pilha_vazia(Pilha* p){
    if (!p){ return 1;}
    return p->indice == -1;
}

int pilha_cheia(Pilha* p){
    if (!p){ return 1;}
    return p->indice == MAX - 1;
}

int pop (Pilha* p, int* valor){
    if (!p || !valor)    {
        return NULL;
    }
    if (pilha_vazia(p)){
        return NULL;
    }

    *valor = p->elementos[p->indice];
    p->indice--;
    return 1;
}

int push( Pilha*p, int valor){
    if (!p){
        return 0;
    }

    if (pilha_cheia(p)){
        return 0;
    }
    p->indice++;
    p->elementos[p->indice] = valor;
    return 1;
}
void imprimir_pilha(Pilha* p){
    if (!p){
        return;
    }
    for (int i = p->indice; i >= 0; i--){
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

void liberar_pilha(Pilha* p){
    if (p){
        free(p);
    }
}