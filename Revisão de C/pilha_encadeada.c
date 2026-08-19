#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* push(TLista* pilha, int n){
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = n;
    novo->prox = NULL;
    if (pilha == NULL){
        pilha = novo;
    } else {
        novo->prox = pilha;
        pilha = novo;
    }
    return pilha;
}

TLista* pop(TLista* pilha){
    if (pilha == NULL){
        printf("Nada removido pois pilha está vazia.");
    }
    TLista* aux = pilha;
    pilha = pilha->prox;
    free(aux);
    return pilha;
}