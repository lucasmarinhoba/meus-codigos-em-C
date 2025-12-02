#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   TAD — MATRIZ TRIANGULAR SUPERIOR (MTS)
   Armazena somente elementos com j >= i
   Memória mínima: n(n+1)/2 valores
   ============================================================ */

typedef struct {
    int n;       // ordem da matriz
    double *v;   // vetor com os valores da parte triangular superior
} MTS;

/* ------------------------------------------------------------
   Cria matriz triangular superior
   ------------------------------------------------------------ */
MTS *MTS_cria(int n) {
    MTS *m = malloc(sizeof(MTS));
    m->n = n;
    m->v = malloc(n * (n + 1) / 2 * sizeof(double));
    return m;
}

/* ------------------------------------------------------------
   Libera MTS
   ------------------------------------------------------------ */
void MTS_libera(MTS *m) {
    free(m->v);
    free(m);
}

/* ------------------------------------------------------------
   Calcula índice no vetor para posição (i,j), com j >= i
   Fórmula: index = i*n - (i*(i-1))/2 + (j - i)
   ------------------------------------------------------------ */
int MTS_indice(int n, int i, int j) {
    return i * n - (i * (i - 1)) / 2 + (j - i);
}

/* ------------------------------------------------------------
   Define valor na posição (i,j)
   Se j < i → não armazena (é zero)
   ------------------------------------------------------------ */
void MTS_set(MTS *m, int i, int j, double valor) {
    if (j < i) return;  // abaixo da diagonal → sempre zero
    int idx = MTS_indice(m->n, i, j);
    m->v[idx] = valor;
}

/* ------------------------------------------------------------
   Obtém valor da posição (i,j)
   Se j < i → retorna zero
   ------------------------------------------------------------ */
double MTS_get(MTS *m, int i, int j) {
    if (j < i) return 0.0;
    int idx = MTS_indice(m->n, i, j);
    return m->v[idx];
}

/* ------------------------------------------------------------
   Imprime matriz completa (para depuração)
   ------------------------------------------------------------ */
void MTS_imprime(MTS *m) {
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            printf("%6.1lf ", MTS_get(m, i, j));
        }
        printf("\n");
    }
}

/* ============================================================
   EXEMPLO DE USO DO TAD
   ============================================================ */

int main() {
    int n = 4;
    MTS *A = MTS_cria(n);

    // Preenche apenas a região válida (j >= i)
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            MTS_set(A, i, j, k++);
        }
    }

    printf("Matriz Triangular Superior:\n");
    MTS_imprime(A);

    printf("\nExemplo: A[1][3] = %.1lf\n", MTS_get(A, 1, 3));
    printf("Exemplo: A[3][1] = %.1lf (abaixo da diagonal → zero)\n",
           MTS_get(A, 3, 1));

    MTS_libera(A);
    return 0;
}
