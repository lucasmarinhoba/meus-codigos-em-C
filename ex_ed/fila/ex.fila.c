#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//3.2 usando lista simples 

void combinar(Fila*f res, Fila* f1, Fila* f2) {
    if (fila_vazia(f1) || fila_vazia(f2)){
        f2->fim = f1->inicio;
        f1->inicio = NULL;
        f2->inicio = NULL; 
        return; // Uma das filas está vazia, nada a combinar
    }
    No* temp1 = f1->inicio;
    No* temp2 = f2->inicio;
    while (temp1 != NULL && temp2 != NULL) {
        enfileirar(res, temp1->valor);
        temp1 = temp1->proximo;
        enfileirar(res, temp2->valor);
        temp2 = temp2->proximo;
    }
    while (temp1 != NULL) {
        enfileirar(res, temp1->valor);
        temp1 = temp1->proximo;
    }

    while (temp2 != NULL) {
        enfileirar(res, temp2->valor);
        temp2 = temp2->proximo;
    }


    liberar_fila(f1);
    liberar_fila(f2);
}


void combinar_circular (Fila* res, Fila* f1, Fila* f2) {  //combinar circular usando lista circular
    if (fila_vazia(f1) || fila_vazia(f2)){
        f2->fim = f1->inicio;
        f1->inicio = NULL;
        f2->inicio = NULL; 
        return; // Uma das filas está vazia, nada a combinar
    }
    No* temp1 = f1->inicio;
    No* temp2 = f2->inicio;
    while (temp1 != f1->inicio && temp2 != f2->inicio) {
        enfileirar(res, temp1->valor);
        temp1 = temp1->proximo;
        enfileirar(res, temp2->valor);
        temp2 = temp2->proximo;
    }
    while (temp1 != f1->inicio) {
        enfileirar(res, temp1->valor);
        temp1 = temp1->proximo;
    }

    while (temp2 != f2->inicio) {
        enfileirar(res, temp2->valor);
        temp2 = temp2->proximo;
    }


    liberar_fila(f1);
    liberar_fila(f2);
}

void combinar_vetor(Fila* res, Fila* f1, Fila* f2) { //combinar circular usando vetor
    while (!fila_vazia(f1) && !fila_vazia(f2)) {
        int valor1, valor2;
        desenfileirar(f1, &valor1);
        desenfileirar(f2, &valor2);
        enfileirar(res, valor1);
        enfileirar(res, valor2);
    }
    while (!fila_vazia(f1)) {
        int valor;
        desenfileirar(f1, &valor);
        enfileirar(res, valor);
    }
    while (!fila_vazia(f2)) {
        int valor;
        desenfileirar(f2, &valor);
        enfileirar(res, valor);
    }
}

