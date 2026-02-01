#ifndef CURCULAR_DUPLA_H
#define CURCULAR_DUPLA_H

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

/* Criação */
No* criar_no(int valor);

/* Inserções */
void inserir_inicio(No** cabeca, int valor);
void inserir_fim(No** cabeca, int valor);
void inserir_meio(No** cabeca, int valor, int posicao);
void inserir_ordenado(No** cabeca, int valor);

/* Remoções */
int remover_inicio(No** cabeca);
int remover_fim(No** cabeca);
int remover_valor(No** cabeca, int valor);

/* Utilidades */
int tamanho_lista(No* cabeca);
void exibir(No* cabeca);
void liberar_lista(No** cabeca);

#endif
