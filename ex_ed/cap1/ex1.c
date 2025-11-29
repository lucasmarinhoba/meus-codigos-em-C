/*Implemente uma função que indique se um ponto (x, y) está localizado dentro ou fora de um retângulo. 
O retângulo é definido por seus vértices inferior esquerdo (x0, y0) e superior direito (x1, y1). 
A função deve ter como valor de retorno 1, se o ponto estiver dentro do retângulo, e 0 caso contrário, obedecendo ao protótipo:*/

#include <stdio.h>
int ponto_dentro_retangulo(int x, int y, int x0, int y0, int x1, int y1) {
    if (x > x0 && x < x1 && y > y0 && y < y1) {
        return 1; // Ponto está dentro do retângulo
    } else {
        return 0; // Ponto está fora do retângulo
    }
}

int main() {
    int x, y, x0, y0, x1, y1;

    // Exemplo de uso da função
    x0 = 1; y0 = 1; // Vértice inferior esquerdo do retângulo
    x1 = 4; y1 = 4; // Vértice superior direito do retângulo

    x = 2; y = 2; // Ponto a ser verificado
    if (ponto_dentro_retangulo(x, y, x0, y0, x1, y1)) {
        printf("O ponto (%d, %d) está dentro do retângulo.\n", x, y);
    } else {
        printf("O ponto (%d, %d) está fora do retângulo.\n", x, y);
    }
    x = 5; y = 5; // Outro ponto a ser verificado
    if (ponto_dentro_retangulo(x, y, x0, y0, x1, y1)) {
        printf("O ponto (%d, %d) está dentro do retângulo.\n", x, y);
    } else {
        printf("O ponto (%d, %d) está fora do retângulo.\n", x, y);
    }
    return 0;
}