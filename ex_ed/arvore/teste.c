#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct No{
    int valor;
    struct No* esquerdo;
    struct No* direito;
} No;

typedef struct Arvore{
    No* raiz;
} Arv;

Arv* criar_arvore(){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}
No* criar_no(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        return NULL; // Falha ao criar nó
    }
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
    return 0; // Valor já existe na árvore
}

int insere_arvore(Arv* a, int valor) {
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
    return 0; // Valor já existe na árvore
}

No* buscar_no(No* n, int valor){
    if (!n) {
        return NULL; // Valor não encontrado
    }
    if (n->valor == valor) {
        return n; // Valor encontrado
    }
    if (n->valor > valor) {
        return buscar_no(n->esquerdo, valor); // Busca na subárvore esquerda
    }
    return buscar_no(n->direito, valor); // Busca na subárvore direita
}

No* busca_arvore(Arv* a, int valor){
    if (!a)        return NULL; // Árvore não existe

    return busca_no(a->raiz, valor);
}

void liberar_no(No* n){
    if (n == NULL)
        return;

    // Libera primeiro a subárvore esquerda
    liberar_no(n->esquerdo);

    // Depois a subárvore direita
    liberar_no(n->direito);

    // Por fim, libera o nó atual
    free(n);
}

void liberar_arvore(Arv** a){
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

int iguais_nos(No* a, No* b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->valor != b->valor)
        return 0;

    return iguais_nos(a->esquerdo, b->esquerdo) &&
           iguais_nos(a->direito, b->direito);
}

Arv* igual(Arv* a, Arv* b) {
    if (a == NULL || b == NULL)
        return NULL;

    if (iguais_nos(a->raiz, b->raiz))
        return a;  // ou b (tanto faz)

    return NULL;
}

int contar_pares(No* n) {
    if (n == NULL)
        return 0;
    return( (n->valor % 2 == 0)
         + contar_pares(n->esquerdo) 
         + contar_pares(n->direito));
}

int contarpares(Arv* a) {
    if (a == NULL)
        return 0;
    return contar_pares(a->raiz);
}

int contar_nos(No* n) {
    if (n == NULL)
        return 0;

    return 1 
         + contar_nos(n->esquerdo)
         + contar_nos(n->direito);
}

int contarnos(Arv* a) {
    if (a == NULL)
        return 0;
    return contar_nos(a->raiz);
}

No* copia_nos(No* n) {
    if (n == NULL)
        return NULL;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL)
        return NULL; // falha de memória

    novo->valor = n->valor;
    novo->esquerdo = copia_nos(n->esquerdo);
    novo->direito  = copia_nos(n->direito);

    return novo;
}

Arv* copia(Arv* a) {
    if (a == NULL)
        return NULL;

    Arv* nova = (Arv*) malloc(sizeof(Arv));
    if (nova == NULL)
        return NULL;

    nova->raiz = copia_nos(a->raiz);

    return nova;
}