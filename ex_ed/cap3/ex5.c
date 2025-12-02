/*3.5. Implemente uma função que calcule a derivada de um polinômio. Cada polinômio é representado como exemplificado no exercício anterior. A função deve obedecer ao protótipo:*/
/*void deriva(double* poli, int grau, double* out);*/

#include <stdio.h>
void deriva(double* poli, int grau, double* out) {
    for (int i = 0; i < grau; i++) {
        out[i] = poli[i] * (grau - i);
    }
}
int main() {
    double poli[] = {3.0, 2.0, 1.0}; // Representa o polinômio 3x^2 + 2x + 1
    int grau = 2; // Grau do polinômio
    double out[grau]; // Array para armazenar a derivada

    deriva(poli, grau, out);

    printf("Derivada do polinômio: ");
    for (int i = 0; i < grau; i++) {
        printf("%.1fx^%d ", out[i], grau - i - 1);
        if (i < grau - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    return 0;
}

