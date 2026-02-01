#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

// Protótipos das funções para lista circular simples
No* criar_no(int valor);
void inserir_inicio(No** inicio, int valor);
void inserir_fim(No** inicio, int valor);
void inserir_ordenado(No** inicio, int valor);
void inserir_meio(No** inicio, int valor, int posicao);
void mostrar(No* inicio);
int remover_inicio(No** inicio);
int remover_fim(No** inicio);
int remover_valor(No** inicio, int valor);

void liberar_lista(No** inicio);

No* criar_no(int valor) {
    No* novo_no = malloc(sizeof(No));
    if (!novo_no) return NULL;
    novo_no->dado = valor;
    novo_no->prox = NULL;
    return novo_no;
}
void inserir_inicio(No** inicio, int valor) {
    No* novo_no = malloc(sizeof(No));
    if (!novo_no) return;

    novo_no->dado = valor;

    // Lista vazia
    if (*inicio == NULL) {
        novo_no->prox = novo_no;
        *inicio = novo_no;
        return; 
    }

    No* ultimo = *inicio;

    // Achar o último (que aponta pro início)
    while (ultimo->prox != *inicio)
        ultimo = ultimo->prox;

    novo_no->prox = *inicio;
    ultimo->prox = novo_no;
    *inicio = novo_no;
}
void inserir_fim(No** inicio, int valor){
    if (*inicio == NULL) {
        inserir_inicio(inicio, valor);
        return;
    }
    No* novo_no = malloc(sizeof(No));
    if (!novo_no) return;
    novo_no->dado = valor;
    No* ultimo = *inicio;
    while (ultimo->prox != *inicio){
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo_no;
    novo_no->prox = *inicio;
}

void inserir_meio(No** inicio, int valor, int pos) {
    if (!inicio) return;

    if (pos == 0 || *inicio == NULL) {
        inserir_inicio(inicio, valor);
        return;
    }

    No* atual = *inicio;
    int contador = 0;

    // Percorre até posição anterior OU até dar a volta
    while (contador < pos - 1 && atual->prox != *inicio) {
        atual = atual->prox;
        contador++;
    }

    // Se não alcançou a posição correta, pos é inválida
    if (contador < pos - 1) {
        printf("Posição inválida\n");
        return;
    }

    No* novo_no = malloc(sizeof(No));
    if (!novo_no) return;

    novo_no->dado = valor;
    novo_no->prox = atual->prox;
    atual->prox = novo_no;
}
void inserir_ordenado(No** inicio, int valor){
    if (*inicio == NULL || (*inicio)->dado >= valor) {
        inserir_inicio(inicio, valor);
        return;
    }

    No* atual = *inicio;

    while (atual->prox != *inicio && atual->prox->dado < valor) {
        atual = atual->prox;
    }

    No* novo_no = malloc(sizeof(No));
    if (!novo_no) return;

    novo_no->dado = valor;
    novo_no->prox = atual->prox;
    atual->prox = novo_no;
}

int remover_inicio(No** inicio){
    if (!inicio || !*inicio) return -1;  // Segurança extra

    No* primeiro = *inicio;
    int valor = primeiro->dado;

    // Caso: apenas um nó
    if (primeiro->prox == primeiro) {
        free(primeiro);
        *inicio = NULL;
        return valor;
    }

    // Encontrar último nó
    No* ultimo = primeiro;
    while (ultimo->prox != primeiro) {
        ultimo = ultimo->prox;
    }

    // Ajustar ligações
    ultimo->prox = primeiro->prox;
    *inicio = primeiro->prox;

    free(primeiro);
    return valor;
}

int remover_fim(No** inicio){
    if (!inicio || !*inicio) return -1;  // Lista vazia

    No* primeiro = *inicio;

    // Só um nó
    if (primeiro->prox == primeiro) {
        int valor = primeiro->dado;
        free(primeiro);
        *inicio = NULL;
        return valor;
    }

    // Achar penúltimo (quem aponta pro último)
    No* penultimo = primeiro;
    while (penultimo->prox->prox != primeiro)
        penultimo = penultimo->prox;

    No* ultimo = penultimo->prox;
    penultimo->prox = primeiro;

    int valor = ultimo->dado;
    free(ultimo);
    return valor;
}


int remover_valor(No** inicio, int valor){
    if (!inicio || !*inicio) return -1; // Lista vazia

    No* atual = *inicio;
    No* anterior = NULL;

    // percorre até voltar ao início
    while (1) {
        if (atual->dado == valor) {

            // se é o primeiro nó
            if (anterior == NULL)
                return remover_inicio(inicio);

            // remover nó do meio/fim
            anterior->prox = atual->prox;
            free(atual);
            return valor;
        }

        anterior = atual;
        atual = atual->prox;

        // se voltou ao início, não achou
        if (atual == *inicio)
            break;
    }

    return -1; // Valor não encontrado
}