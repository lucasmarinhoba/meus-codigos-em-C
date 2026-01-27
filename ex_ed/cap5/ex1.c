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


char* minisculo_novo(const char *str) {
    int n = strlen(str);
    char *nova = malloc((n + 1) * sizeof(char));
    if (!nova) return NULL;

    for (int i = 0; i <= n; i++) {  // inclui '\0'
        nova[i] = tolower(str[i]);
    }

    return nova;
}

char* shift_string_novo(const char *str) {
    int n = strlen(str);
    char *nova = malloc((n + 1) * sizeof(char));
    if (!nova) return NULL;

    for (int i = 0; i <= n; i++) {
        nova[i] = str[i];

        if (nova[i] >= 'a' && nova[i] <= 'z')
            nova[i] = 'a' + (nova[i] - 'a' + 1) % 26;

        else if (nova[i] >= 'A' && nova[i] <= 'Z')
            nova[i] = 'A' + (nova[i] - 'A' + 1) % 26;
    }

    return nova;
}


char* string_apostada_novo(const char *str) {
    int n = strlen(str);
    char *nova = malloc((n + 1) * sizeof(char));
    if (!nova) return NULL;

    for (int i = 0; i <= n; i++) {
        nova[i] = str[i];

        if (nova[i] >= 'a' && nova[i] <= 'z')
            nova[i] = 'a' + 'z' - nova[i];

        else if (nova[i] >= 'A' && nova[i] <= 'Z')
            nova[i] = 'A' + 'Z' - nova[i];
    }

    return nova;
}


char* shift_string_direita_novo(const char *str) {
    int n = strlen(str);
    char *nova = malloc((n + 1) * sizeof(char));
    if (!nova) return NULL;

    strcpy(nova, str);

    if (n > 1) {
        char ultimo = nova[n - 1];
        for (int i = n - 1; i > 0; i--)
            nova[i] = nova[i - 1];
        nova[0] = ultimo;
    }

    return nova;
}
