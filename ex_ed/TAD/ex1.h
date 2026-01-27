#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

// Cria ponto (x, y)
Ponto* ponto_cria(float x, float y);

// Libera memória
void ponto_libera(Ponto* p);

// Acessores
float ponto_get_x(Ponto* p);
float ponto_get_y(Ponto* p);

// Modificadores
void ponto_set_x(Ponto* p, float x);
void ponto_set_y(Ponto* p, float y);

// Distância entre dois pontos
float ponto_distancia(Ponto* p1, Ponto* p2);

#endif
