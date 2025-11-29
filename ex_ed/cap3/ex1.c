/*Implemente uma função que receba como parâmetro um vetor de números reais (vet) de tamanho n
 e retorne quantos números negativos estão armazenados nesse vetor.
 Essa função deve obedecer ao protótipo:*/
#include <stdio.h>
int contar_negativos(float* vet, int n) {
    int count = 0; // Inicializa o contador de números negativos

    for (int i = 0; i < n; i++) {
        if (vet[i] < 0) {
            count++; // Incrementa o contador se o número for negativo
        }
    }

    return count; // Retorna o total de números negativos encontrados
}