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
int main() {
    float vetor[] = {3.5, -2.1, 0.0, -7.4, 5.6, -1.2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int negativos = contar_negativos(vetor, tamanho);

    printf("Quantidade de numeros negativos no vetor: %d\n", negativos);

    return 0;
}