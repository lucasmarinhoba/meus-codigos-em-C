#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
} Aluno;

// Imprime dados dos alunos aprovados
void imprime_aprovados(int n, Aluno **turmas);

// Retorna média final de uma turma específica
float media_turma(int n, Aluno **turmas, char turma);

#endif
