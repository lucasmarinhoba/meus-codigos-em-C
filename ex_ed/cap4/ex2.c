#include "ex2.h"
#include <stdlib.h>

struct MatTriInf {
    int n;
    double *dados;
};

MatTriInf* cria(int n) {
    MatTriInf *m = malloc(sizeof(MatTriInf));
    m->n = n;
    m->dados = calloc(n*(n+1)/2, sizeof(double));
    return m;
}

void atribui(MatTriInf *m, int i, int j, double val) {
    if (i < j) return;
    int pos = i*(i+1)/2 + j;
    m->dados[pos] = val;
}

double acessa(MatTriInf *m, int i, int j) {
    if (i < j) return 0.0;
    int pos = i*(i+1)/2 + j;
    return m->dados[pos];
}

void libera(MatTriInf *m) {
    free(m->dados);
    free(m);
}

#include <stdio.h>
#include "ex2.h"

int main() {
    MatTriInf *m = cria(3);
    atribui(m, 2, 1, 5.0);
    printf("%.1f\n", acessa(m, 2, 1));
    libera(m);
}
