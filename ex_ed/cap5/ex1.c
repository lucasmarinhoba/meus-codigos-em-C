/*5.1. Implemente uma função que receba uma string como parâmetro e 
retorne como resultado o número de vogais nessa string. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h> // para tolower()

int contaVogais(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}
 int ocorrenciasChar(char *str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
 }
void minisculo(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
void shift_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'z') {
            str[i] = 'a';
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        } else {
            str[i] = str[i] + 1;
        }
    }
}
void string_apostada(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + 'z' - str[i];
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + 'Z' - str[i];
        }
    }
}
void shift_string_direita(char *str) {
    int i;
    char ultimo;

    // achar o tamanho
    int n = strlen(str);

    if (n <= 1) return;

    ultimo = str[n - 1];  // guarda último

    // move tudo para direita
    for (i = n - 1; i > 0; i--) {
        str[i] = str[i - 1];
    }

    str[0] = ultimo; // coloca último no começo
}
