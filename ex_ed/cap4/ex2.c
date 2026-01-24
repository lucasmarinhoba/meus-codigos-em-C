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
    if (i < j) return;  // inferior
    int pos = i*(i+1)/2 + j;
    m->dados[pos] = val;
}

double acessa(MatTri *m, int i, int j) {
    if (i < j) return 0.0;
    int pos = i*(i+1)/2 + j;
    return m->dados[pos];
}

void libera(MatTri *m) {
    free(m->dados);
    free(m);
}
#include <stdio.h>
#include "ex2.h"

int main() {
    int n = 4;
    MatTri *m = cria(n);

    if (!m) {
        printf("Erro ao criar matriz.\n");
        return 1;
    }

    // Atribuindo vários valores válidos (parte inferior)
    atribui(m, 0, 0, 1.0);
    atribui(m, 1, 0, 2.0);
    atribui(m, 1, 1, 3.0);
    atribui(m, 2, 0, 4.0);
    atribui(m, 2, 1, 5.0);
    atribui(m, 2, 2, 6.0);
    atribui(m, 3, 0, 7.0);
    atribui(m, 3, 1, 8.0);
    atribui(m, 3, 2, 9.0);
    atribui(m, 3, 3, 10.0);

    // Tentativa inválida (acima da diagonal → deve ser ignorado)
    atribui(m, 0, 2, 99.0);

    printf("Matriz triangular inferior %dx%d:\n\n", n, n);

    // Imprimindo como matriz completa
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.1f ", acessa(m, i, j));
        }
        printf("\n");
    }

    printf("\nTeste de acesso isolado:\n");
    printf("m(3,1) = %.1f\n", acessa(m,3,1)); // deve ser 8
    printf("m(0,3) = %.1f\n", acessa(m,0,3)); // deve ser 0

    libera(m);
    return 0;
}
