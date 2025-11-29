/*Implemente uma função que retorne uma aproximação do valor de π, de acordo com a fórmula de Leibniz*/
#include <stdio.h>
double aproximacao_pi(int termos) {
    double pi = 0.0;
    for (int k = 0; k < termos; k++) {
        // Adiciona o k-ésimo termo da série de Leibniz
        if (k % 2 == 0) {
            pi += 1.0 / (2 * k + 1); // Termo positivo
        } else {
            pi -= 1.0 / (2 * k + 1); // Termo negativo
        }
    }
    pi *= 4.0; // Multiplica a soma por 4 para obter a aproximação de π
    return pi; // Retorna a aproximação de π
}