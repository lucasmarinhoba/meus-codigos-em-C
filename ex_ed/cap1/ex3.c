/*Implemente uma função que retorne o n-ésimo termo da série de Fibonacci. 
A série de Fibonacci é dada por: 1 1 2 3 5 8 13 21 ..., isto é, 
os dois primeiros termos são iguais a 1 e cada termo seguinte é a soma dos dois termos anteriores.
 Essa função deve obedecer ao protótipo:*/

#include <stdio.h>
int fibonacci(int n) {
    if (n <= 0) {
        return 0; // Retorna 0 para entradas inválidas
    } else if (n == 1 || n == 2) {
        return 1; // Os dois primeiros termos são 1
    } else {
        int a = 1, b = 1, c;
        for (int i = 3; i <= n; i++) {
            c = a + b; // Calcula o próximo termo
            a = b;     // Atualiza o termo anterior
            b = c;     // Atualiza o termo atual
        }
        return c; // Retorna o n-ésimo termo
    }
}