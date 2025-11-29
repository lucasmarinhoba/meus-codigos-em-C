/*Implemente uma função que calcule as raízes de uma equação do segundo graua
Essa função deve obedecer ao protótipo:
int raizes(float a, float b, float c, float* x1, float* x2);
Essa função deve ter como valor de retorno o número de raízes reais e distintas da equação. Se existirem raízes reais, 
seus valores devem ser armazenados nas variáveis apontadas por x1 e x*/
#include <stdio.h>
#include <math.h>
int raizes(float a, float b, float c, float* x1, float* x2) {
    float delta = b * b - 4 * a * c; // Calcula o discriminante (delta)

    if (delta < 0) {
        return 0; // Não existem raízes reais
    } else if (delta == 0) {
        *x1 = -b / (2 * a); // Calcula a única raiz real
        *x2 = *x1; // Ambas as raízes são iguais
        return 1; // Existe uma raiz real
    } else {
        *x1 = (-b + sqrt(delta)) / (2 * a); // Calcula a primeira raiz real
        *x2 = (-b - sqrt(delta)) / (2 * a); // Calcula a segunda raiz real
        return 2; // Existem duas raízes reais distintas
    }
}