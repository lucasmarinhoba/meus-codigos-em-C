/*4.2. Implemente um TAD, minimizando o espaço de memória utilizado, 
para representar uma matriz triangular inferior. 
Nesse tipo de matriz, todos os elementos acima da diagonal têm valor zero.*/

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   TAD — MATRIZ TRIANGULAR INFERIOR (MTI)
   Memória mínima: vetor de size = n(n+1)/2
   ============================================================ */

typedef struct {
    int n;        // ordem da matriz
    double *v;    // vetor que contém somente os elementos i >= j
} MTI;

/* ------------------------------------------------------------
   Cria MTI
   ------------------------------------------------------------ */
MTI *MTI_cria(int n) {
    MTI *m = malloc(sizeof(MTI));
    m->n = n;
    m->v = malloc(n * (n + 1) / 2 * sizeof(double));
    return m;
}

/* ------------------------------------------------------------
   Libera MTI
   ------------------------------------------------------------ */
void MTI_libera(MTI *m) {
    free(m->v);
    free(m);
}

/* ------------------------------------------------------------
   Cálculo do índice no vetor (i,j) com i >= j
   Fórmula: index = i(i+1)/2 + j
   ------------------------------------------------------------ */
int MTI_indice(int i, int j) {
    return (i * (i + 1)) / 2 + j;
}

/* ------------------------------------------------------------
   Define valor na posição (i,j)
   Se j > i → não armazena nada (é zero)
   ------------------------------------------------------------ */
void MTI_set(MTI *m, int i, int j, double valor) {
    if (j > i) return; // não armazena pois deve ser sempre zero
    int idx = MTI_indice(i, j);
    m->v[idx] = valor;
}

/* ------------------------------------------------------------
   Obtém valor na posição (i,j)
   Se j > i → retorna zero
   ------------------------------------------------------------ */
double MTI_get(MTI *m, int i, int j) {
    if (j > i) return 0.0; // posição acima da diagonal
    int idx = MTI_indice(i, j);
    return m->v[idx];
}

/* ------------------------------------------------------------
   Impressão da matriz completa (para depuração/apresentação)
   ------------------------------------------------------------ */
void MTI_imprime(MTI *m) {
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            printf("%6.1lf ", MTI_get(m, i, j));
        }
        printf("\n");
    }
}

/* ============================================================
   EXEMPLO DE USO DO TAD
   ============================================================ */

int main() {
    int n = 4;
    MTI *A = MTI_cria(n);

    // Preenchendo somente região válida (i >= j)
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            MTI_set(A, i, j, k++);
        }
    }

    printf("Matriz Triangular Inferior:\n");
    MTI_imprime(A);

    printf("\nExemplo: A[3][1] = %.1lf\n", MTI_get(A, 3, 1));
    printf("Exemplo: A[1][3] = %.1lf (acima da diagonal → zero)\n",
           MTI_get(A, 1, 3));

    MTI_libera(A);
    return 0;
}
