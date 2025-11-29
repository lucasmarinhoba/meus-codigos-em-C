/*Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n 
e retorne quantos números pares estão armazenados nesse vetor. */
#include <stdio.h>
int contar_pares(int* vet, int n) {
    int count = 0; // Inicializa o contador de números pares

    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) {
            count++; // Incrementa o contador se o número for par
        }
    }

    return count; // Retorna o total de números pares encontrados
}
