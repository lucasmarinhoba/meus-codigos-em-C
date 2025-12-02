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
