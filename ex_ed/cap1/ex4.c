/*Implemente uma função que retorne a soma dos n primeiros números naturais ímpares.*/
#include <stdio.h>
int soma_impares(int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (2 * i + 1); // Adiciona o i-ésimo número ímpar
    }
    return soma; // Retorna a soma dos n primeiros números ímpares
}