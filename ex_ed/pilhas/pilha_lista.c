#include <stdio.h>
#include <pilha.h>

//implementação da pilha usando lista encadeada

struct pilha {
    int valor;
    struct pilha* prox;
};

Pilha* criar_pilha() {
    return NULL; // pilha vazia
}

int pilha_vazia(Pilha* p) {
    if (p == NULL) {
        return 1; // pilha vazia
    }
    return 0;
}

int pop (Pilha* p, int* valor){
    if (pilha_vazia(p)){
        return 0;
    }

    *valor = p->valor;
    Pilha* temp = p;
    p = p->prox;
    free(temp);
    return 1;
}

int push(Pilha* p, int valor) {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    if (nova_pilha == NULL) {
        return 0; // falha na alocação
    }
    nova_pilha->valor = valor;
    nova_pilha->prox = p;
    p = nova_pilha;
    return 1;
}

void imprimir_pilha(Pilha* p){ // faça recursivo
    if (pilha_vazia(p)){
        return;
    }
    imprimir_pilha(p->prox);
    printf("%d\n", p->valor);
}
