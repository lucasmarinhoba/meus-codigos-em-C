/*Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r. 
Essa função deve obedecer ao protótipo:*/
#include <stdio.h>
#include <math.h>
void esfera(float r, float* area, float* volume) {
    const float pi = 3.14; // Definição do valor de pi
    *area = 4 * pi * r * r; // Cálculo da área da superfície da esfera
    *volume = (4.0f / 3.0f) * pi * r * r * r; // Cálculo do volume da esfera
}

int main() {
    float raio, area, volume;

    // Solicita ao usuário o valor do raio
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    // Chama a função para calcular área e volume
    esfera(raio, &area, &volume);

    // Exibe os resultados
    printf("Área da superfície: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}