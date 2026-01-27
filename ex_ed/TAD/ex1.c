#include <stdlib.h>
#include <math.h>
#include "ex1.h"

struct ponto {
    float x;
    float y;
};

Ponto* ponto_cria(float x, float y) {
    Ponto* p = malloc(sizeof(Ponto));
    if (p == NULL) return NULL;

    p->x = x;
    p->y = y;
    return p;
}

void ponto_libera(Ponto* p) {
    free(p);
}

float ponto_get_x(Ponto* p) {
    return p->x;
}

float ponto_get_y(Ponto* p) {
    return p->y;
}

void ponto_set_x(Ponto* p, float x) {
    p->x = x;
}

void ponto_set_y(Ponto* p, float y) {
    p->y = y;
}

float ponto_distancia(Ponto* p1, Ponto* p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}
