/*Implemente uma função que indique se um ponto (x, y) está localizado dentro ou fora de um retângulo. 
O retângulo é definido por seus vértices inferior esquerdo (x0, y0) e superior direito (x1, y1). 
A função deve ter como valor de retorno 1, se o ponto estiver dentro do retângulo, e 0 caso contrário, obedecendo ao protótipo:*/

#include <stdio.h>

typedef struct cooredenada {
    int x;
    int y;
} Ponto;

int ponto_dentro_retangulo(Ponto* v1, Ponto* v2, Ponto* p) {
    if (p->x > v1->x && p->x < v2->x && p->y > v1->y && p->y < v2->y) {
        return 1; // Ponto está dentro do retângulo
    } else {
        return 0; // Ponto está fora do retângulo
    }
}

int main() {
    Ponto v1, v2, p;
    // Exemplo de uso da função
    v1.x = 1; v1.y = 1; // Vértice inferior esquerdo do retângulo
    v2.x = 4; v2.y = 4; // Vértice superior direito do retângulo
    p.x = 2; p.y = 2; // Ponto a ser verificado
    if (ponto_dentro_retangulo(&v1, &v2, &p)) {
        printf("O ponto (%d, %d) está dentro do retângulo.\n", p.x, p.y);
    } else {
        printf("O ponto (%d, %d) está fora do retângulo.\n", p.x, p.y);
    }
}