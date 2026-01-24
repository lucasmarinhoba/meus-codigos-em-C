#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

struct MatTri {
    int n;
    double *dados;
};

MatTri* cria(int n) {
    MatTri *m = malloc(sizeof(MatTri));
    m->n = n;
    m->dados = malloc((n*(n+1)/2) * sizeof(double));
    for (int i = 0; i < n*(n+1)/2; i++)
        m->dados[i] = 0.0;
    return m;
}

void atribui(MatTri *m, int i, int j, double val) {
    if (i > j) return;  // só guarda parte SUPERIOR
    int pos = i*(2*m->n - i + 1)/2 + (j - i);
    m->dados[pos] = val;
}

double acessa(MatTri *m, int i, int j) {
    if (i > j) return 0.0;
    int pos = i*(2*m->n - i + 1)/2 + (j - i);
    return m->dados[pos];
}

void libera(MatTri *m) {
    free(m->dados);
    free(m);
}

int main() {
    int n = 4;
    MatTri *m = cria(n);

    // Atribuindo valores válidos (i <= j)
    atribui(m, 0, 0, 1);
    atribui(m, 0, 1, 2);
    atribui(m, 0, 2, 3);
    atribui(m, 0, 3, 4);
    atribui(m, 1, 1, 5);
    atribui(m, 1, 2, 6);
    atribui(m, 1, 3, 7);
    atribui(m, 2, 2, 8);
    atribui(m, 2, 3, 9);
    atribui(m, 3, 3, 10);

    // Tentativa inválida (inferior)
    atribui(m, 3, 0, 99);  // deve ser ignorado

    printf("Matriz triangular superior %dx%d:\n\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.1f ", acessa(m, i, j));
        }
        printf("\n");
    }

    printf("\nTestes isolados:\n");
    printf("m(0,3) = %.1f (esperado 4)\n", acessa(m,0,3));
    printf("m(3,0) = %.1f (esperado 0)\n", acessa(m,3,0));

    libera(m);
    return 0;
}
