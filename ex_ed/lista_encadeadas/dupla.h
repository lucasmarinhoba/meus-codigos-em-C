//tad lista encadeada duplamente
#ifndef DUPLA_H
#define DUPLA_H

typedef struct no No;
No* criar_no(int valor);
void liberar_lista(No* cabeca);
void inserir_no_inicio(No** cabeca, int valor);
void inserir_no_fim(No** cabeca, int valor);
void inserir_ordenado(No** cabeca, int valor);
void inserir_meio(No** cabeca, int valor, int posicao);
int remover_incicio(No** cabeca);
int remover_fim(No** cabeca);
int remover_valor(No** cabeca, int valor);
int buscar_valor(No* cabeca, int valor);
int tamanho_lista(No* cabeca);
int comparar_listas(No* cabeca1, No* cabeca2);
void exibir(No* cabeca);
#endif