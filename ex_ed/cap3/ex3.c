/*Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n 
e inverta a ordem dos elementos armazenados nesse vetor.*/
#include <stdio.h>
void inverterVetor(int vet[], int n) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio < fim) {
        int temp = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = temp;
        inicio++;
        fim--;
    }
}
int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    inverterVetor(vetor, tamanho);

    printf("Vetor invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}