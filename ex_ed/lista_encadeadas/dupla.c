#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo, *anterior;
} No;

No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return NULL;
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

void inserir_no_inicio(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    if (!novo) return;

    novo->proximo = *cabeca;
    if (*cabeca != NULL)
        (*cabeca)->anterior = novo;

    *cabeca = novo;
}

void inserir_no_fim(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    if (!novo) return;

    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }

    No* atual = *cabeca;
    while (atual->proximo != NULL)
        atual = atual->proximo;

    atual->proximo = novo;
    novo->anterior = atual;
}

void inserir_meio(No** cabeca, int valor, int posicao) {
    // Se o ponteiro da lista não existe ou a posição é inválida, sai da função
    if (cabeca == NULL || posicao < 0) return;

    // Caso especial: inserir na posição 0 (início da lista)
    // Usa a função auxiliar que já ajusta os ponteiros corretamente
    if (posicao == 0) {
        inserir_no_inicio(cabeca, valor);
        return;
    }

    // Ponteiro para percorrer a lista
    No* atual = *cabeca;

    // Anda até o nó ANTERIOR à posição onde queremos inserir
    // Ex: posição 3 → para no nó 2
    for (int i = 0; i < posicao - 1 && atual != NULL; i++)
        atual = atual->proximo;

    // Se chegou ao fim antes da posição desejada → posição inválida
    if (atual == NULL) {
        printf("Posicao invalida\n");
        return;
    }

    // Cria o novo nó com o valor desejado
    No* novo = criar_no(valor);
    if (!novo) return; // Falha de alocação de memória

    // Liga o novo nó para frente (próximo)
    novo->proximo = atual->proximo;

    // Liga o novo nó para trás (anterior)
    novo->anterior = atual;

    // Se não estamos inserindo no final,
    // ajusta o ponteiro "anterior" do próximo nó
    if (atual->proximo != NULL)
        atual->proximo->anterior = novo;

    // Faz o nó anterior apontar para o novo nó
    atual->proximo = novo;
}


void inserir_ordenado(No** cabeca, int valor) {
    if (cabeca == NULL) return;

    // Caso 1: lista vazia OU deve inserir no início
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        inserir_no_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;

    // Anda até achar a posição correta
    while (atual->proximo != NULL && atual->proximo->valor < valor)
        atual = atual->proximo;

    // Agora sim cria o nó (porque sabemos onde inserir)
    No* novo = criar_no(valor);
    if (!novo) return;

    // Ajustes de ponteiros (lista DUPLA)
    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo != NULL)
        atual->proximo->anterior = novo;

    atual->proximo = novo;
}

int remover_inicio(No** cabeca) {
    if (cabeca == NULL || *cabeca == NULL) return -1;

    No* temp = *cabeca;
    int valor = temp->valor;

    *cabeca = temp->proximo;
    if (*cabeca != NULL)
        (*cabeca)->anterior = NULL;

    free(temp);
    return valor;
}

int remover_fim(No** cabeca) {
    if (cabeca == NULL || *cabeca == NULL) return -1;

    No* atual = *cabeca;
    if (atual->proximo == NULL) {
        int valor = atual->valor;
        free(atual);
        *cabeca = NULL;
        return valor;
    }

    while (atual->proximo != NULL)
        atual = atual->proximo;

    int valor = atual->valor;
    atual->anterior->proximo = NULL;
    free(atual);
    return valor;
}
int remover_valor(No** cabeca, int valor) {
    if (cabeca == NULL || *cabeca == NULL) return -1;

    No* atual = *cabeca;

    // Se o valor está no primeiro nó
    if (atual->valor == valor)
        return remover_inicio(cabeca);

    // Procura o valor a partir do segundo
    while (atual != NULL && atual->valor != valor)
        atual = atual->proximo;

    if (atual == NULL) return -1;

    // Ajusta os ponteiros (meio ou fim)
    atual->anterior->proximo = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;

    free(atual);
    return valor;
}

void liberar_lista(No** cabeca) {
    if (cabeca == NULL) return;

    No* atual = *cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *cabeca = NULL;
}
int tamanho_lista(No* cabeca) {
    int tamanho = 0;
    No* atual = cabeca;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}
int comparar_listas(No* cabeca1, No* cabeca2) {
    No* atual1 = cabeca1;
    No* atual2 = cabeca2;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->valor != atual2->valor)
            return 0;

        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }

    // Se as duas acabaram juntas → iguais
    if (atual1 == NULL && atual2 == NULL)
        return 1;

    // Uma acabou antes da outra → tamanhos diferentes
    return 0;
}

void exibir(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}
int main() {
    No* lista = NULL;

    inserir_no_fim(&lista, 10);
    inserir_no_fim(&lista, 20);
    inserir_no_inicio(&lista, 5);
    inserir_meio(&lista, 15, 2);
    inserir_ordenado(&lista, 12);

    printf("Lista atual: ");
    exibir(lista);

    printf("Removido do inicio: %d\n", remover_inicio(&lista));
    printf("Removido do fim: %d\n", remover_fim(&lista));
    printf("Removido valor 15: %d\n", remover_valor(&lista, 15));

    printf("Lista apos remocoes: ");
    exibir(lista);

    printf("Tamanho da lista: %d\n", tamanho_lista(lista));

    liberar_lista(&lista);
    return 0;
}