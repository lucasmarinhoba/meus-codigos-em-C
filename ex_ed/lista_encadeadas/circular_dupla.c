#include <stdio.h>
#include <stdlib.h>
#include "circular_dupla.h"

/* ===== CRIAR NÓ ===== */
No* criar_no(int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return NULL;
    novo->valor = valor;
    novo->proximo = novo;
    novo->anterior = novo;
    return novo;
}

/* ===== INSERIR INÍCIO ===== */
void inserir_inicio(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    if (!novo) return;

    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }

    No* ultimo = (*cabeca)->anterior;

    novo->proximo = *cabeca;
    novo->anterior = ultimo;

    ultimo->proximo = novo;
    (*cabeca)->anterior = novo;

    *cabeca = novo;
}

/* ===== INSERIR FIM ===== */
void inserir_fim(No** cabeca, int valor) {
    if (*cabeca == NULL) {
        inserir_inicio(cabeca, valor);
        return;
    }

    No* novo = criar_no(valor);
    if (!novo) return;

    No* ultimo = (*cabeca)->anterior;

    novo->proximo = *cabeca;
    novo->anterior = ultimo;

    ultimo->proximo = novo;
    (*cabeca)->anterior = novo;
}

/* ===== TAMANHO ===== */
int tamanho_lista(No* cabeca) {
    if (!cabeca) return 0;

    int cont = 0;
    No* atual = cabeca;
    do {
        cont++;
        atual = atual->proximo;
    } while (atual != cabeca);

    return cont;
}

/* ===== INSERIR MEIO ===== */
void inserir_meio(No** cabeca, int valor, int pos) {
    if (!cabeca || pos < 0) return;

    // Lista vazia
    if (*cabeca == NULL) {
        inserir_inicio(cabeca, valor);
        return;
    }

    // Inserção no início
    if (pos == 0) {
        inserir_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;
    int i = 0;

    // Anda até posição ou até dar a volta completa
    while (atual->proximo != *cabeca && i < pos - 1) {
        atual = atual->proximo;
        i++;
    }

    // Se voltou pra cabeça → posição é maior que o tamanho
    if (i < pos - 1) {
        printf("Posição inválida\n");
        return;
    }

    // Criar nó
    No* novo = criar_no(valor);
    if (!novo) return;

    // Inserção no meio
    novo->proximo = atual->proximo;
    novo->anterior = atual;

    atual->proximo->anterior = novo;
    atual->proximo = novo;
}

/* ===== INSERIR ORDENADO ===== */
void inserir_ordenado(No** inicio, int valor) {
    if (!inicio) return;

    // Lista vazia OU deve virar o primeiro
    if (*inicio == NULL || valor < (*inicio)->valor) {
        inserir_inicio(inicio, valor);
        return;
    }

    No* p = *inicio;

    // Anda até o último menor que o valor
    while (p->proximo != *inicio && p->proximo->valor < valor)
        p = p->proximo;

    // Se chegou no final da circular → é inserção no fim
    if (p->proximo == *inicio) {
        inserir_fim(inicio, valor);
        return;
    }

    // Inserção no meio
    No* novo = criar_no(valor);
    if (!novo) return;

    novo->proximo = p->proximo;
    novo->anterior  = p;

    p->proximo->anterior = novo;
    p->proximo = novo;
}


/* ===== REMOVER INÍCIO ===== */
int remover_inicio(No** cabeca) {
    if (!cabeca || !*cabeca) return -1;

    No* removido = *cabeca;
    int valor = removido->valor;

    if (removido->proximo == removido) {
        free(removido);
        *cabeca = NULL;
        return valor;
    }

    No* ultimo = removido->anterior;

    *cabeca = removido->proximo;
    ultimo->proximo = *cabeca;
    (*cabeca)->anterior = ultimo;

    free(removido);
    return valor;
}

/* ===== REMOVER FIM ===== */
int remover_fim(No** inicio) {
    if (!inicio || *inicio == NULL) return 0;

    // Se só tem um nó → usar auxiliar
    if ((*inicio)->proximo == *inicio)
        return remover_inicio(inicio);
    No* temp = *inicio;
    No* remove = temp->anterior;
    int valor = remove->valor;
    // Religar a circularidade
    temp ->anterior->anterior->proximo = *inicio;
    temp->anterior = temp->anterior->anterior;

    free(remove);
    return valor;
}


/* ===== REMOVER VALOR ===== */
int remover_valor(No** cabeca, int valor) {
    if (!cabeca || !*cabeca) return -1;

    No* inicio = *cabeca;
    No* atual  = inicio;

    while (atual->valor != valor) {
        atual = atual->proximo;

        // Deu a volta completa → não existe
        if (atual == inicio)
            return -1;
    }

    // Achou o valor
    if (atual == *cabeca)
        return remover_inicio(cabeca);  // usa auxiliar

    // Meio ou fim
    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    free(atual);
    return valor;
}

/* ===== EXIBIR ===== */
void exibir(No* cabeca) {
    if (!cabeca) {
        printf("Lista vazia\n");
        return;
    }

    No* atual = cabeca;
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != cabeca);

    printf("\n");
}

/* ===== LIBERAR ===== */
void liberar_lista(No** cabeca) {
    if (!cabeca || !*cabeca) return;

    No* atual = (*cabeca)->proximo;
    while (atual != *cabeca) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(*cabeca);
    *cabeca = NULL;
}
int comparar_listas(No* cabeca1, No* cabeca2) {
    if (cabeca1 == NULL && cabeca2 == NULL) return 1;
    if (cabeca1 == NULL || cabeca2 == NULL) return 0;

    No* atual1 = cabeca1;
    No* atual2 = cabeca2;

    while (1) {
        if (atual1->valor != atual2->valor)
            return 0;

        atual1 = atual1->proximo;
        atual2 = atual2->proximo;

        // Se uma terminou o ciclo e a outra não
        if ((atual1 == cabeca1) != (atual2 == cabeca2))
            return 0;

        // Se as duas voltaram, terminou
        if (atual1 == cabeca1)
            break;
    }

    return 1;
}
void inverter_lista(No** inicio) {
    if (!inicio || !*inicio) return;

    No* atual = *inicio;
    No* anterior = NULL;
    No* proximo;

    // percorre todos os nós uma vez
    while (anterior != *inicio) {
        proximo = atual->proximo;      // guarda o próximo original

        // troca os ponteiros
        atual->proximo = atual->anterior;
        atual->anterior = proximo;

        anterior = atual;              // marca como já invertido
        atual = proximo;               // avança
    }

    // antigo último virou o novo início
    *inicio = anterior;
}

