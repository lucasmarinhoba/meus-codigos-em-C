#include <stdio.h>
#include <stdlib.h>
#include "exsala.h"

struct complexo {
    double a; // parte real
    double b; // parte imaginária
};

Complexo* criar_complexo(double a, double b) {
    Complexo* c = (Complexo*)malloc(sizeof(Complexo));
    if (!c) 
        return NULL;
    else {
        c->a = a;
        c->b = b;
        return c;
    }
}

void liberar_complexo(Complexo* c) {
    free(c);
}

Complexo* somar_complexo(const Complexo* c1, const Complexo* c2) {
    return criar_complexo(c1->a + c2->a, c1->b + c2->b);
}

Complexo* subtrair_complexo(const Complexo* c1, const Complexo* c2) {
    return criar_complexo(c1->a - c2->a, c1->b - c2->b);
}

Complexo* multiplicar_complexo(const Complexo* c1, const Complexo* c2) {
    double real = c1->a * c2->a - c1->b * c2->b;
    double imag = c1->a * c2->b + c1->b * c2->a;
    return criar_complexo(real, imag);
}

Complexo* dividir_complexo(const Complexo* c1, const Complexo* c2) {
    double denom = c2->a * c2->a + c2->b * c2->b;
    if (denom == 0) 
        return NULL; // divisão por zero
    double real = (c1->a * c2->a + c1->b * c2->b) / denom;
    double imag = (c1->b * c2->a - c1->a * c2->b) / denom;
    return criar_complexo(real, imag);
}

void imprimir_complexo(const Complexo* c) {
    if (c->b >= 0)
        printf("%.2f + %.2fi\n", c->a, c->b);
    else
        printf("%.2f - %.2fi\n", c->a, -c->b);
}

int main() {
    double a1, b1, a2, b2;
    printf("Digite a parte real e imaginária do primeiro número complexo (a b): ");
    scanf("%lf %lf", &a1, &b1);
    printf("Digite a parte real e imaginária do segundo número complexo (a b): ");
    scanf("%lf %lf", &a2, &b2);
    Complexo* c1 = criar_complexo(a1, b1);
    Complexo* c2 = criar_complexo(a2, b2);

    imprimir_complexo(c1);
    imprimir_complexo(c2);
    if (!c1 || !c2) {
        printf("Erro ao alocar memória para números complexos.\n");
        return 1;
    }

    Complexo* soma = somar_complexo(c1, c2);
    Complexo* subtracao = subtrair_complexo(c1, c2);
    Complexo* multiplicacao = multiplicar_complexo(c1, c2);
    Complexo* divisao = dividir_complexo(c1, c2);

    printf("Soma: ");
    imprimir_complexo(soma);
    printf("Subtração: ");
    imprimir_complexo(subtracao);
    printf("Multiplicação: ");
    imprimir_complexo(multiplicacao);
    printf("Divisão: ");
    imprimir_complexo(divisao);

    liberar_complexo(c1);
    liberar_complexo(c2);
    liberar_complexo(soma);
    liberar_complexo(subtracao);
    liberar_complexo(multiplicacao);
    liberar_complexo(divisao);

    return 0;
}