/*Implemente uma função para testar se um número inteiro é primo ou não. Essa função deve obedecer ao protótipo a seguir e ter como valor de retorno 1 se n for primo e 0 caso contrário.*/

#include <stdio.h>
int eh_primo(int n) {
    if (n <= 1) {
        return 0; // Números menores ou iguais a 1 não são primos
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Encontrou um divisor, não é primo
        }
    }
    return 1; // É primo
}
int main() {
    int numero;

    // Exemplo de uso da função
    numero = 7; // Número a ser verificado
    if (eh_primo(numero)) {
        printf("O número %d é primo.\n", numero);
    } else {
        printf("O número %d não é primo.\n", numero);
    }

    numero = 10; // Outro número a ser verificado
    if (eh_primo(numero)) {
        printf("O número %d é primo.\n", numero);
    } else {
        printf("O número %d não é primo.\n", numero);
    }

    return 0;
}