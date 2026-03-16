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

void em_ordem(Arvore *a, int i){

    if(i >= MAX || a->dados[i] == VAZIO)
        return;

    em_ordem(a, 2*i + 1);

    printf("%d ", a->dados[i]);

    em_ordem(a, 2*i + 2);
}

int minimo_indice(Arvore *a, int i){

    while(2*i + 1 < MAX && a->dados[2*i + 1] != VAZIO)
        i = 2*i + 1;

    return i;
}

