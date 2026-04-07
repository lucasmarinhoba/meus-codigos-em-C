#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef struct Arvore{
    No* raiz;
} Arv;

Arv* criar_arvore(){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    if (!a) {return NULL;}
    a->raiz = NULL;
    return a;
}

No* criar_no(int valor){
    No* novo = (No*)malloc(sizeof(No));
    //if nao novo
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int inserir_no(No*n, int valor){
    if (!n) {return 0;}

    if (n->valor > valor){
        if (n->esq == NULL){
            n->esq = criar_no(valor);
            return (n->esq!= NULL);
        }
        return inserir_no(n->esq, valor);
    }

    if (n-> valor < valor){
        if (n->dir == NULL){
            n->dir = criar_no(valor);
            return (n->dir != NULL);
        }
        return inserir_no(n->dir, valor);
    }

    return 0;
}

int inserir_arvore(Arv* a, int valor){
    if (!a) {return NULL;}
    
    if (a->raiz == NULL){
        a->raiz = criar_no(valor);
        return (a->raiz != NULL);
    }

    if (a->raiz->valor > valor){
        if (a->raiz->esq == NULL){
            a->raiz->esq = criar_no(valor);
            return (a->raiz->esq != NULL);
        }
        return inserir_no(a->raiz->esq, valor);
    }

    if (a->raiz->valor < valor){
        if (a->raiz->dir == NULL){
            a->raiz->dir = criar_no(valor);
            return (a->raiz->dir != NULL);
        }
        return inserir_no(a->raiz->dir, valor);
    }
}

/*int inserir_arvore(Arv* a, int valor){
    if (!a) return 0;

    if (a->raiz == NULL){
        a->raiz = criar_no(valor);
        return (a->raiz != NULL);
    }

    return inserir_no(a->raiz, valor);
}*/


No* buscar_no(No* n, int valor){
    if (!n) { return NULL; }

    if (n->valor == valor){
        return n;
    }

    if (n->valor > valor){
        return buscar_no(n->esq, valor);
    }

    return buscar_no(n->dir, valor);
}

No* buscar_arvore(Arv* a, int valor){
    if (!a) {return NULL;}
    return buscar_no(a->raiz, valor);
}

void liberar_no(No* n){
    if (n == NULL)
        return;

    // Libera primeiro a subárvore esquerda
    liberar_no(n->esq);

    // Depois a subárvore direita
    liberar_no(n->dir);

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
    return (1 + max(altura(raiz->esq), altura(raiz->dir)));
}

void exibir_em_ordem(No* n) {
    if (!n) {return;} 

    exibir_em_ordem(n->esq); // Visita a subárvore esquerda
    printf("%d ", n->valor); // Visita o nó atual
    exibir_em_ordem(n->dir); // Visita a subárvore direita
}

No* rotacaoLL(No* raiz){
    No* novaraiz = raiz->esq;
    raiz->esq = novaraiz->dir;
    novaraiz->dir = raiz;
    return novaraiz;
}

No* rotacaoRR(No* raiz){
    No* novaraiz = raiz->dir;
    raiz->dir = novaraiz->esq;
    novaraiz = raiz;
    return novaraiz;
}

No* rotacaoLR(No* raiz) {
    raiz->esq = rotacaoRR(raiz->esq);
    return rotacaoLL(raiz);
}

No* rotacaoRL(No* raiz) {
    raiz->dir = rotacaoLL(raiz->dir);
    return rotacaoRR(raiz);
}

int no_igual(No* a, No* b){
    if (a==NULL && b == NULL){
        return 1;
    }
    if (a==NULL || b == NULL){
        return 0;
    }
    if (a->valor != b ->valor){
        return 0;
    }

    return (no_igual(a->esq, b->esq) && no_igual(a->dir, b->dir));
}

Arv* igual(Arv* a, Arv* b){

    if (a == NULL || b == NULL)
        return NULL;

    if (iguais_nos(a->raiz, b->raiz))
        return a;  // ou b (tanto faz)

    return NULL;
}

int contar_pares(No* n){
    if (!n) {return 0;}

    return ((n->valor % 2 == 0) 
        + contar_pares(n->esq) 
        + contar_pares(n->dir));

}

int contarpares(Arv* a){
    if (!a){ return 0;}

    return contar_pares(a->raiz);
}

int contar_nos(No* a){

    if (!a) return -1;

    return (1 + contar_nos(a->esq) + contar_nos(a->dir));
}

int contarnos(Arv* a) {
    if (a == NULL)
        return 0;
    return contar_nos(a->raiz);
}

No* copia_nos(No* n){
    if (!n) {return NULL;}

    No* novo = (No*)malloc(sizeof(No));

    if (!novo) {return NULL;}

    novo->valor = n->valor;
    novo->esq = copia_nos(n->esq);
    novo->dir = copia_nos(n->dir);

    return novo;
}

Arv* copia(Arv* a){

    if (!a) {return NULL;
    }

    Arv* novo = (Arv*)malloc(sizeof(Arv));

    if (!novo) {return NULL;
    }

    novo->raiz = copia_nos (a->raiz);
    return novo; 
}

