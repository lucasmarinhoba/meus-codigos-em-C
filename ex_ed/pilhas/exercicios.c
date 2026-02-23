#include <stdio.h>
#include <stdlib.h>


//ex1 a

int valor_topo_vet_estatic(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        return -1; // Retorna -1 para indicar que a pilha está vazia
    }
    return p->elementos[p->indice]; // Retorna o valor do topo da pilha
}

int valor_topo_vet_dinam(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        return -1; // Retorna -1 para indicar que a pilha está vazia
    }
    return p->elementos[p->indice]; // Retorna o valor do topo da pilha
}

int valor_topo_lista(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        return -1; // Retorna -1 para indicar que a pilha está vazia
    }
    return p->valor; // Retorna o valor do topo da pilha
}

// ex1 b

Pilha* concatena_pilha_vet_estatic(Pilha* p1, Pilha* p2){
    if (pilha_vazia(p1)) {
        return p2; // Se a pilha 1 estiver vazia, retorna a pilha 2
    }
    if (pilha_vazia(p2)) {
        return p1; // Se a pilha 2 estiver vazia, retorna a pilha 1
    }
    for (int i = 0; i <= p2->indice; i++) {
        push(p1, p2->elementos[i]); // Adiciona os elementos da pilha 2 à pilha 1
    }
    return p1;
}

Pilha* concatena_pilha_vet_dinam(Pilha* p1, Pilha* p2){
    if (pilha_vazia(p1)) {
        return p2; // Se a pilha 1 estiver vazia, retorna a pilha 2
    }
    if (pilha_vazia(p2)) {
        return p1; // Se a pilha 2 estiver vazia, retorna a pilha 1
    }
    for (int i = 0; i <= p2->indice; i++) {
        push(p1, p2->elementos[i]); // Adiciona os elementos da pilha 2 à pilha 1
    }
    return p1;
}

Pilha* concatena_pilha_lista(Pilha* p1, Pilha* p2){
    if (pilha_vazia(p1)) {
        return p2; // Se a pilha 1 estiver vazia, retorna a pilha 2
    }
    if (pilha_vazia(p2)) {
        return p1; // Se a pilha 2 estiver vazia, retorna a pilha 1
    }
    Pilha* temp = p2; // Cria um ponteiro temporário para percorrer a pilha 2
    while (temp != NULL) {
        temp = temp->prox; // Move o ponteiro para o próximo elemento da pilha 2
    }
    temp->prox = p1; // Conecta o último elemento da pilha 2 ao topo da pilha 1
    p1 = p2; // Atualiza o topo da pilha 1 para o topo da pilha 2
    return p1;
}

//ex 1 c

Pilha* copia_pilha_vet_estatic(Pilha* p){
    if (pilha_vazia(p)) {
        return NULL; 
    }
    Pilha* nova_pilha = criar_pilha(); // Cria uma nova pilha
    for (int i = 0; i <= p->indice; i++) {
        push(nova_pilha, p->elementos[i]); // Adiciona os elementos da pilha original à nova pilha
    }
    return nova_pilha; // Retorna a nova pilha copiada
}

Pilha* copia_pilha_vet_dinam(Pilha* p){
    if (pilha_vazia(p)) {
        return NULL; 
    }
    Pilha* nova_pilha = criar_pilha(); // Cria uma nova pilha
    for (int i = 0; i <= p->indice; i++) {
        push(nova_pilha, p->elementos[i]); // Adiciona os elementos da pilha original à nova pilha
    }
    return nova_pilha; // Retorna a nova pilha copiada
}

Pilha* copiar_pilha(Pilha* p) {
    if (p == NULL)
        return NULL;

    Pilha* nova = copiar_pilha(p->prox);

    Pilha* novo_no = malloc(sizeof(Pilha));
    if (!novo_no)
        return NULL;

    novo_no->valor = p->valor;
    novo_no->prox = nova;

    return novo_no;
}
