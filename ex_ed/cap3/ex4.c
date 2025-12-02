/*Implemente uma função que permita a avaliação de polinômios. 
Cada polinômio é definido por um vetor que contém seus coeficientes. Por exemplo,
 o polinômio de grau 2, 
double avalia(double* poli, int grau, double x);*/

#include <stdio.h>
#include <stdio.h>

#include <stdio.h>

double avalia(double* pol, int grau, double x);

int main() {
    double pol[] = {12, 2, 3};  // 12 + 2x + 3x^2
    double x = 2.0;

    double r = avalia(pol, 2, x);

    printf("Resultado = %lf\n", r); // Deve imprimir 3*4 + 2*2 + 12 = 12 + 4 + 12 = 28

    return 0;
}

double avalia(double* pol, int grau, double x) {
    double resultado = pol[grau];

    for (int i = grau - 1; i >= 0; i--) {
        resultado = resultado * x + pol[i];
    }

    return resultado;
}
