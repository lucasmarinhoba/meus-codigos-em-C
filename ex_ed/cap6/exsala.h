#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complexo Complexo;

// Cria um número complexo (a + bi)
Complexo* criar_complexo(double a, double b);

// Libera memória
void liberar_complexo(Complexo* c);

// Soma: c1 + c2
Complexo* somar_complexo(const Complexo* c1, const Complexo* c2);

// Subtrai: c1 - c2
Complexo* subtrair_complexo(const Complexo* c1, const Complexo* c2);

// Multiplica: c1 * c2
Complexo* multiplicar_complexo(const Complexo* c1, const Complexo* c2);

// Divide: c1 / c2
Complexo* dividir_complexo(const Complexo* c1, const Complexo* c2);

// Imprime na forma a + bi
void imprimir_complexo(const Complexo* c);

#endif
