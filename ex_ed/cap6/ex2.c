#include <stdio.h>

typedef struct vetor {
    int x;
    int y;
    int z;
} Vetor;

int produto_escalar(Vetor* v1, Vetor* v2) {
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}