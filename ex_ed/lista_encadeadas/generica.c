#include <stdio.h>
#include <stdlib.h>

// ================= FORMAS =================

typedef struct {
    float b, h;
} Retangulo;

typedef struct {
    float b, h;
} Triangulo;

typedef struct {
    float raio;
} Circulo;

// ================= TIPO =================

typedef enum {
    RET,
    TRI,
    CIR
} Tipo;

// ================= NÓ DA LISTA =================

typedef struct no {
    Tipo tipo;       // identifica qual forma está guardada
    void *info;      // ponteiro genérico (lista heterogênea)
    struct no *prox; // próximo nó
} No;

// ================= INSERÇÃO =================

No* inserir_inicio(No* lista, Tipo t, void* dado) {
    No* novo = (No*) malloc(sizeof(No));
    novo->tipo = t;
    novo->info = dado;
    novo->prox = lista;
    return novo;
}

// ================= IMPRESSÃO =================

void imprimir_lista(No* lista) {
    while (lista != NULL) {

        if (lista->tipo == RET) {
            Retangulo* r = (Retangulo*) lista->info;
            printf("Retangulo: base=%.2f altura=%.2f\n", r->b, r->h);
        }
        else if (lista->tipo == TRI) {
            Triangulo* t = (Triangulo*) lista->info;
            printf("Triangulo: base=%.2f altura=%.2f\n", t->b, t->h);
        }
        else if (lista->tipo == CIR) {
            Circulo* c = (Circulo*) lista->info;
            printf("Circulo: raio=%.2f\n", c->raio);
        }

        lista = lista->prox;
    }
}

// ================= LIBERAR MEMÓRIA =================

void liberar_lista(No* lista) {
    No* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux->info); // libera a forma
        free(aux);       // libera o nó
    }
}

// ================= MAIN =================

int main() {
    No* lista = NULL;
    // Criando formas
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    r->b = 10; r->h = 5;

    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->b = 6; t->h = 4;

    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->raio = 3;

    // Inserindo na lista
    lista = inserir_inicio(lista, RET, r);
    lista = inserir_inicio(lista, TRI, t);
    lista = inserir_inicio(lista, CIR, c);

    // Mostrar conteúdo
    imprimir_lista(lista);

    // Liberar memória
    liberar_lista(lista);

    return 0;
}
