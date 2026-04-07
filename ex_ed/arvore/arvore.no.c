#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementação da árvore usando nós
typedef struct No {
    int valor;
    struct No *esquerdo;
    struct No *direito;
} No;

typedef struct {
    No *raiz;
} Arvore;

Arvore* criar_arvore() {
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}

No* criar_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

int inserir_no(No* n, int valor){
    if (!n) {
        return 0; // Falha ao criar nó
    }

    if (n->valor > valor){
        if (n->esquerdo == NULL) {
            n->esquerdo = criar_no(valor);
            return (n->esquerdo != NULL);
        }
        return inserir_no(n->esquerdo, valor);
    }

    if (n->valor < valor){
        if (n->direito == NULL) {
            n->direito = criar_no(valor);
            return (n->direito != NULL);
        }
        return inserir_no(n->direito, valor);
    }

}

int insere_arvore(Arvore* a, int valor) {
    if (!a)        return 0; // Falha ao criar árvore
    if (a->raiz == NULL){
        a->raiz = criar_no(valor);
        return (a->raiz != NULL);
    }
    if (a->raiz->valor > valor){
        if (a->raiz->esquerdo == NULL) {
            a->raiz->esquerdo = criar_no(valor);
            return (a->raiz->esquerdo != NULL);
        }
        return inserir_no(a->raiz->esquerdo, valor);
    }
    if (a->raiz->valor < valor){
        if (a->raiz->direito == NULL) {
            a->raiz->direito = criar_no(valor);
            return (a->raiz->direito != NULL);
        }
        return inserir_no(a->raiz->direito, valor);
    }    
}

No* buscar_no(No* n, int valor){
    if (!n)        return NULL; // Nó não existe
    if (n->valor == valor) {
        return n; // Nó encontrado
    }
    if (n->valor > valor) {
        return buscar_no(n->esquerdo, valor); // Busca na subárvore esquerda
    }
    return buscar_no(n->direito, valor); // Busca na subárvore direita
}

No* busca_arvore(Arvore* a, int valor){
    if (!a)        return NULL; // Árvore não existe

    return busca_no(a->raiz, valor);
}

void liberar_no(No* n){
    if (n) {
        liberar_no(n->esquerdo);
        liberar_no(n->direito);
        free(n);
    }
}
void liberar_arvore(Arvore** a){
    if (!a) { return; } // Árvore não existe
    liberar_no((*a)->raiz);
    *a = NULL;

}
int altura(No* raiz){
    if (!raiz) {
        return -1; // Altura de uma árvore vazia é -1
    }
    return (1 + max(altura(raiz->esquerdo), altura(raiz->direito)));
}

int contar_nos(No* n){
    if (!n){return 0;}

    return (1 + contar_nos(n->esquerdo) + contar_nos(n->direito));
}

void exibir_em_ordem(No* n) {
    if (n) {
        exibir_em_ordem(n->esquerdo); // Visita a subárvore esquerda
        printf("%d ", n->valor); // Visita o nó atual
        exibir_em_ordem(n->direito); // Visita a subárvore direita
    }
}

No* rotacaoLL(No* raiz) {
    No* novaRaiz = raiz->esquerdo;
    raiz->esquerdo = novaRaiz->direito;
    novaRaiz->direito = raiz;
    return novaRaiz;
}

No* rotacaoRR(No* raiz) {
    No* novaRaiz = raiz->direito;
    raiz->direito = novaRaiz->esquerdo;
    novaRaiz->esquerdo = raiz;
    return novaRaiz;
}


//faça a main