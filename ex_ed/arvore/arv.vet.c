#include <stdio.h>
#include <stdlib.h>

// Implementação da árvore usando vetor

// Relação entre índices no vetor
//Considerando índice inicial 0:

//filho_esquerdo = 2*i + 1  
//filho_direito  = 2*i + 2  
//pai            = (i - 1) / 2


#define MAX 100
#define VAZIO -1

typedef struct {
    int dados[100]; // Tamanho fixo do vetor
} Arvore;


void inicializar(Arvore *a){

    for(int i = 0; i < MAX; i++)
        a->dados[i] = VAZIO;

}


void inserir(Arvore *a, int valor){

    int i = 0;

    while(i < MAX){

        if(a->dados[i] == VAZIO){
            a->dados[i] = valor;
            return;
        }

        if(valor < a->dados[i])
            i = 2*i + 1;
        else
            i = 2*i + 2;
    }

    printf("Sem espaço no vetor\n");
}

void em_ordem(Arvore *a, int i){

    if(i >= MAX || a->dados[i] == VAZIO)
        return;

    em_ordem(a, 2*i + 1);

    printf("%d ", a->dados[i]);

    em_ordem(a, 2*i + 2);
}

int minimo_indice(Arvore *a, int i){
    if(i >= MAX || a->dados[i] == VAZIO)
        return -1;

    while(2*i + 1 < MAX && a->dados[2*i + 1] != VAZIO)
        i = 2*i + 1;

    return i;
}

int maximo_indice(Arvore *a, int i){
    if(i >= MAX || a->dados[i] == VAZIO)
        return -1;

    while(2*i + 2 < MAX && a->dados[2*i + 2] != VAZIO)
        i = 2*i + 2;

    return i;
}

int minimo_valor(Arvore *a, int i){
    int idx = minimo_indice(a, i);

    if(idx == -1)
        return -1; // erro

    return a->dados[idx];
}

int maximo_valor(Arvore *a, int i){
    int idx = maximo_indice(a, i);

    if(idx == -1)
        return -1; // erro

    return a->dados[idx];
}

int buscar(Arvore *a, int valor){

    int i = 0;

    while(i < MAX && a->dados[i] != VAZIO){

        if(valor == a->dados[i])
            return i;

        if(valor < a->dados[i])
            i = 2*i + 1;
        else
            i = 2*i + 2;
    }

    return -1;
}



void remover_indice(Arvore *a, int i){
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    // Caso 1: folha
    if((esq >= MAX || a->dados[esq] == VAZIO) &&
       (dir >= MAX || a->dados[dir] == VAZIO)){
        a->dados[i] = VAZIO;
        return;
    }

    // Caso 2: só esquerdo
    if(dir >= MAX || a->dados[dir] == VAZIO){
        a->dados[i] = a->dados[esq];
        remover_indice(a, esq);
        return;
    }

    // Caso 3: só direito
    if(esq >= MAX || a->dados[esq] == VAZIO){
        a->dados[i] = a->dados[dir];
        remover_indice(a, dir);
        return;
    }

    // Caso 4: dois filhos
    int min = minimo_indice(a, dir);

    a->dados[i] = a->dados[min];
    remover_indice(a, min);
}

void remover(Arvore *a, int valor){
    int i = buscar(a, valor);

    if(i == -1){
        printf("Valor nao encontrado\n");
        return;
    }

    remover_indice(a, i);
}