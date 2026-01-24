#ifndef EX2_H
#define EX2_H

typedef struct MatTri MatTri;

MatTri* cria(int n);
void atribui(MatTri *m, int i, int j, double val);
double acessa(MatTri *m, int i, int j);
void libera(MatTri *m);

#endif
