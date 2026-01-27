#include <stdio.h>
#include "ex3_4.h"

float media_aluno(Aluno *a) {
    return (a->p1 + a->p2 + a->p3) / 3.0f;
}
void imprime_aprovados(int n, Aluno **turmas) {
    for (int i = 0; i < n; i++) {
        Aluno *a = turmas[i];
        float media = media_aluno(a);

        if (media >= 7.0f) {
            printf("Matricula: %s\n", a->matricula);
            printf("Nome: %s\n", a->nome);
            printf("Turma: %c\n", a->turma);
            printf("Media: %.2f\n\n", media);
        }
    }
}

float media_turma(int n, Aluno **turmas, char turma) {
    float soma = 0.0f;
    int count = 0;

    for (int i = 0; i < n; i++) {
        Aluno *a = turmas[i];

        if (a->turma == turma) {
            soma += media_aluno(a);
            count++;
        }
    }

    if (count == 0) return 0.0f; // nenhuma pessoa da turma

    return soma / count;
}

int main() {
    int n = 3;

    Aluno *v[3];

    for (int i = 0; i < n; i++)
        v[i] = malloc(sizeof(Aluno));

    // aluno 1
    sprintf(v[0]->nome, "Lucas");
    sprintf(v[0]->matricula, "123");
    v[0]->turma = 'A';
    v[0]->p1 = 8; v[0]->p2 = 7; v[0]->p3 = 9;

    // aluno 2
    sprintf(v[1]->nome, "Ana");
    sprintf(v[1]->matricula, "456");
    v[1]->turma = 'A';
    v[1]->p1 = 5; v[1]->p2 = 6; v[1]->p3 = 5;

    // aluno 3
    sprintf(v[2]->nome, "Joao");
    sprintf(v[2]->matricula, "789");
    v[2]->turma = 'B';
    v[2]->p1 = 9; v[2]->p2 = 8; v[2]->p3 = 10;

    imprime_aprovados(n, v);

    printf("Media turma A: %.2f\n", media_turma(n, v, 'A'));

    for (int i = 0; i < n; i++)
        free(v[i]);

    return 0;
}
