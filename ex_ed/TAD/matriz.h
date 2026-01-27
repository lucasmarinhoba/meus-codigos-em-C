#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;
Matriz* matriz_cria(int linhas, int colunas);
void mat_libera (Matriz* mat);
float mat_acessa(Matriz* mat, int i, int j);
void mat_atribui(Matriz* mat, int i, int j, float val);
int mat_linhas(Matriz* mat);
int mat_colunas(Matriz* mat);



#endif