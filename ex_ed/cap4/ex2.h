#ifndef MAT_TRI_INF_H
#define MAT_TRI_INF_H

typedef struct MatTriInf MatTriInf; // tipo opaco (usuário não vê os campos)

MatTriInf* cria(int n);
void atribui(MatTriInf *m, int i, int j, double val);
double acessa(MatTriInf *m, int i, int j);
void libera(MatTriInf *m);

#endif
