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
    if (!cabeca) return;

    // Início
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        inserir_no_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;

    // Anda até achar posição
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    // Fim
    if (atual->proximo == NULL) {
        inserir_no_fim(cabeca, valor);
        return;
    }

    // Meio
    No* novo = criar_no(valor);
    if (!novo) return;

    novo->proximo = atual->proximo;
    novo->anterior = atual;
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
    if (!cabeca || !*cabeca) return -1;

    No* atual = *cabeca;

    // Caso 1: está no início
    if (atual->valor == valor)
        return remover_inicio(cabeca);

    // Procura a partir do segundo
    atual = atual->proximo;
    while (atual != NULL && atual->valor != valor)
        atual = atual->proximo;

    // Não encontrou
    if (atual == NULL) return -1;

    // Caso 2: está no final
    if (atual->proximo == NULL)
        return remover_fim(cabeca);

    // Caso 3: está no meio
    atual->anterior->proximo = atual->proximo;
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
void inverter_lista_dupla(No** inicio) {
    if (!inicio || !*inicio) return;

    No* anterior = NULL;
    No* atual = *inicio;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;   // guarda o próximo

        // inverte os dois lados
        atual->proximo = anterior;  // vira o prox
        atual->anterior = proximo;  // vira o anterior

        // anda pra frente (na lista original)
        anterior = atual;
        atual = proximo;
    }

    // novo início é o antigo último
    *inicio = anterior;
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