
// Implementação da fila circular usando vetor
#include <stdio.h>

#define CAPACIDADE 5

typedef struct fila {
    int dados[CAPACIDADE];
    int inicio;
    int fim;
} FilaCircular;

/* =========================
   Inicializar
   ========================= */
void inicializar(FilaCircular *f) {
    f->inicio = -1;
    f->fim = -1;
}

/* =========================
   Fila vazia
   ========================= */
int estaVazia(FilaCircular *f) {
    return (f->inicio == -1);
}

/* =========================
   Fila cheia
   ========================= */
int estaCheia(FilaCircular *f) {
    return ((f->fim + 1) % CAPACIDADE) == f->inicio;
}

/* =========================
   Enfileirar
   ========================= */
int enfileirar(FilaCircular *f, int valor) {

    if (estaCheia(f))
        return 0;

    if (estaVazia(f)) {
        f->inicio = 0;
        f->fim = 0;
        f->dados[f->fim] = valor;
        return 1;
    }    
    
    f->fim = (f->fim + 1) % CAPACIDADE;
    f->dados[f->fim] = valor;
    return 1;
}

/* =========================
   Desenfileirar
   ========================= */
int desenfileirar(FilaCircular *f, int *valorRemovido) {

    if (estaVazia(f))
        return 0;

    *valorRemovido = f->dados[f->inicio];

    if (f->inicio == f->fim) {
        f->inicio = -1;
        f->fim = -1;
    } else {
        f->inicio = (f->inicio + 1) % CAPACIDADE;
    }

    return 1;
}

/* =========================
   Imprimir fila
   ========================= */
void imprimir(FilaCircular *f) {

    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila: ");

    int i = f->inicio;  // variável auxiliar

    while (i != f->fim) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % CAPACIDADE;
    }

    printf("%d\n", f->dados[f->fim]);  // imprime o último
}
/* =========================
   Main
   ========================= */
int main() {

    FilaCircular fila;
    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    imprimir(&fila);

    int removido;

    desenfileirar(&fila, &removido);
    printf("Removido: %d\n", removido);

    imprimir(&fila);

    return 0;
}