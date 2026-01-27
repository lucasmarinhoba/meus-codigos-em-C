#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/* Estrutura REAL da matriz (oculta no .h) */
struct matriz {
    int m;        // linhas
    int n;        // colunas
    float **v;    // matriz de valores
};

Matriz* matriz_cria(int linhas, int colunas) {
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    mat->m = linhas;
    mat->n = colunas;

    mat->v = (float**) malloc(linhas * sizeof(float*));
    if (!mat->v) {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        mat->v[i] = calloc(colunas, sizeof(float)); //mat->v[i] = (float*) malloc(colunas * sizeof(float));
        if (!mat->v[i]) {
            // desaloca o que já foi alocado
            for (int k = 0; k < i; k++)
                free(mat->v[k]);
            free(mat->v);
            free(mat);
            return NULL;
        }
    }

    return mat;
}

/* Libera matriz */
void mat_libera(Matriz* mat) {
    if (!mat) return;

    for (int i = 0; i < mat->m; i++)
        free(mat->v[i]);

    free(mat->v);
    free(mat);
}

/* Acessa elemento */
float mat_acessa(Matriz* mat, int i, int j) {
    if (i < 0 || i >= mat->m || j < 0 || j >= mat->n) {
        printf("Erro de acesso na matriz!\n");
        exit(1);
    }
    return mat->v[i][j];
}

/* Atribui valor */
void mat_atribui(Matriz* mat, int i, int j, float v) {
    if (i < 0 || i >= mat->m || j < 0 || j >= mat->n) {
        printf("Erro de atribuição na matriz!\n");
        exit(1);
    }
    mat->v[i][j] = v;
}

/* Número de linhas */
int mat_linhas(Matriz* mat) {
    return mat->m;
}

/* Número de colunas */
int mat_colunas(Matriz* mat) {
    return mat->n;
}

/*#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int m;      // número de linhas
    int n;      // número de colunas
    float *v;   // dados da matriz (bloco contíguo)
} Matriz;

 cria uma matriz m x n 
Matriz* matriz_cria(int linhas, int colunas);

atribui valor à posição (i,j) 
void matriz_atribui(Matriz *mat, int i, int j, float val);

 acessa valor da posição (i,j) 
float matriz_acessa(Matriz *mat, int i, int j);

 libera a matriz 
void matriz_libera(Matriz *mat);

#endif 

#include "matriz.h"
#include <stdlib.h>

Matriz* matriz_cria(int linhas, int colunas) {
    Matriz *mat = malloc(sizeof(Matriz));
    if (!mat) return NULL;

    mat->m = linhas;
    mat->n = colunas;

    mat->v = malloc(linhas * colunas * sizeof(float));
    if (!mat->v) {
        free(mat);
        return NULL;
    }

    // inicializa com zero
    for (int i = 0; i < linhas * colunas; i++) {
        mat->v[i] = 0.0f;
    }

    return mat;
}

void matriz_atribui(Matriz *mat, int i, int j, float val) {
    mat->v[i * mat->n + j] = val;
}

float matriz_acessa(Matriz *mat, int i, int j) {
    return mat->v[i * mat->n + j];
}

void matriz_libera(Matriz *mat) {
    free(mat->v);
    free(mat);
}
*/