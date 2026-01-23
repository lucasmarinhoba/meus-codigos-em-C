#ifndef EX2_H
#define EX2_H

typedef struct MatTriInf MatTriInf;

MatTriInf* cria(int n);
void atribui(MatTriInf *m, int i, int j, double val);
double acessa(MatTriInf *m, int i, int j);
void libera(MatTriInf *m);

#endif
