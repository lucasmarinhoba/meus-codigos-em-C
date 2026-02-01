//lista simplesmente encadeada
#include <stdio.h>
#include <stdlib.h>
#include "simples.h"

struct no {
    int valor;
    No* proximo;
};

No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (!novo_no) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}
void inserir_no_inicio(No** cabeca, int valor) {
    No* novo_no = criar_no(valor);
    if (!novo_no) return;
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}
void inserir_no_fim(No** cabeca, int valor) {
    No* novo_no = criar_no(valor);
    if (!novo_no) return;
    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}
void inserir_ordenado(No** cabeca, int valor) {

    // Lista vazia OU menor que o primeiro → início
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        inserir_no_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;

    // Anda até achar a posição
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    // Se é o final → usa função pronta
    if (atual->proximo == NULL) {
        inserir_no_fim(cabeca, valor);
        return;
    }

    // Agora sabemos que é no MEIO → cria o nó
    No* novo_no = criar_no(valor);
    if (!novo_no) return;

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}


void inserir_meio(No** cabeca, int valor, int posicao) {
    if (cabeca == NULL || posicao < 0) {
        printf("Posicao invalida\n");
        return;
    }

    if (posicao == 0) {
        inserir_no_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;
    int i = 0;

    // Anda até o nó anterior à posição desejada
    while (atual->proximo != NULL && i < posicao - 1) {
        atual = atual->proximo;
        i++;
    }

    // ❗ TESTE CORRETO DE ERRO
    if (i < posicao - 1) {
        printf("Posicao invalida\n");
        return;
    }

    No* novo_no = criar_no(valor);
    if (!novo_no) return;

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

int remover_inicio(No** cabeca) {
    if (*cabeca == NULL) {
        printf("Lista vazia\n");
        return -1;
    }
    No* temp = *cabeca;
    int valor = temp->valor;
    *cabeca = (*cabeca)->proximo;
    free(temp);
    return valor;
}

int remover_fim(No** cabeca) {
    if (cabeca == NULL || *cabeca == NULL) {
        printf("Lista vazia\n");
        return -1;
    }

    // Só um nó
    if ((*cabeca)->proximo == NULL) {
        return remover_inicio(cabeca);
    }

    No* atual = *cabeca;

    // Para no penúltimo
    while (atual->proximo->proximo != NULL) {
        atual = atual->proximo;
    }

    No* ultimo = atual->proximo;
    int valor = ultimo->valor;

    free(ultimo);
    atual->proximo = NULL;

    return valor;
}

int remover_valor(No** cabeca, int valor) {
    if (cabeca == NULL || *cabeca == NULL) {
        printf("Lista vazia\n");
        return -1;
    }
    if ((*cabeca)->valor == valor) {
        return remover_inicio(cabeca);
    }
    No* atual = *cabeca;
    No* anterior = NULL;

    // Procura o valor
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Não encontrou
    if (atual == NULL) {
        printf("Valor nao encontrado\n");
        return -1;
    }
    anterior->proximo = atual->proximo;
    free(atual);
    return valor;
}

int buscar_valor(No* cabeca, int valor) {
    No* atual = cabeca;
    int posicao = 0;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}
int tamanho_lista(No* cabeca) {
    No* atual = cabeca;
    int tamanho = 0;
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
        if (atual1->valor != atual2->valor) {
            return 0;
        }
        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }
    return 1;
}
void exibir(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
void liberar_lista(No** cabeca) {
    if (cabeca == NULL) return;

    while (*cabeca != NULL) {
        remover_inicio(cabeca);
    }
}

int main() {
    No* lista = NULL;
    inserir_no_fim(&lista, 10);
    inserir_no_fim(&lista, 20);
    inserir_no_inicio(&lista, 5);
    inserir_ordenado(&lista, 15);
    exibir(lista);
    printf("Tamanho da lista: %d\n", tamanho_lista(lista));
    int removido = remover_valor(&lista, 15);
    if (removido != -1) {
        printf("Removido: %d\n", removido);
    }
    exibir(lista);
    liberar_lista(&lista);
    lista = NULL;
    return 0;
}