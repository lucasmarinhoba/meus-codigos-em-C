#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   Funções para MATRIZ ALOCADA COMO VETOR DE PONTEIROS (double**)
   ============================================================ */

// Aloca matriz n x n como vetor de ponteiros
double **aloca_vetor_ponteiros(int n) {
    double **mat = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        mat[i] = malloc(n * sizeof(double));
    return mat;
}

// Libera matriz
void libera_vetor_ponteiros(double **mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

// Verifica se é simétrica (versão 1)
int ehSimetrica_v1(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                return 0; // Não é simétrica
            }
        }
    }
    return 1; // Simétrica
}

/* ============================================================
   Funções para MATRIZ ALOCADA COMO BLOCO ÚNICO (double*)
   ============================================================ */

// Aloca matriz n x n como bloco contínuo
double *aloca_bloco_unico(int n) {
    return malloc(n * n * sizeof(double));
}

// Libera matriz
void libera_bloco_unico(double *mat) {
    free(mat);
}

// Verifica se é simétrica (versão 2)
int ehSimetrica_v2(double *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i*n + j] != mat[j*n + i]) {
                return 0; // Não é simétrica
            }
        }
    }
    return 1; // Simétrica
}

/* ============================================================
   PROGRAMA PRINCIPAL PARA DEMONSTRAÇÃO
   ============================================================ */

int main() {
    int n = 3;

    /* ======= Teste Versão 1: vetor de ponteiros ======= */

    double **A = aloca_vetor_ponteiros(n);

    double dados1[3][3] = {
        {1, 2, 3},
        {2, 5, 6},
        {3, 6, 9}
    };

    // Copia matriz para A
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = dados1[i][j];

    printf("Versão 1 (double**): %s\n",
           ehSimetrica_v1(A, n) ? "Simétrica" : "Não simétrica");

    libera_vetor_ponteiros(A, n);

    /* ======= Teste Versão 2: bloco único ======= */

    double *B = aloca_bloco_unico(n);

    double dados2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Copia matriz para bloco único
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i*n + j] = dados2[i][j];

    printf("Versão 2 (bloco único): %s\n",
           ehSimetrica_v2(B, n) ? "Simétrica" : "Não simétrica");

    libera_bloco_unico(B);

    return 0;
}
