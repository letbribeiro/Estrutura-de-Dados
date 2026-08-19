#include "arvore-binaria.c"

typedef struct No {
    TNoA* a;
    struct No *prox;
} TNoP;

typedef struct {
    TNoP* top;
} Pilha;

void iniciarPilha(Pilha* p){
    p->top = NULL;
}

void pushPilha(Pilha *p, TNoA* a){
    TNoP* novo = (TNoP*) malloc(sizeof(TNoP));
    novo->a = a;
    novo->prox = p->top;
    p->top = novo;
}

TNoA* popPilha(Pilha* p){
    if (p->top == NULL){
        printf("Pilha vazia!");
        return NULL;
    }
    TNoP *aux = p->top;
    TNoA* a = aux->a;
    p->top = aux->prox;
    free(aux);

    return a;
}

void simetrico(TNoA* a){
    Pilha pA;
    iniciarPilha(&pA);
    TNoA* aux = a;
    TNoA* temp;
    do {
        while (aux != NULL){
            pushPilha(&pA, aux);
            aux = aux->esq;
        }
        temp = popPilha(&pA);
        printf("%c\n", temp->info);
        aux = temp->dir;
        while (aux == NULL && pA.top != NULL){
            temp = popPilha(&pA);
            printf("%c\n", temp->info);
            aux = temp->dir;
        }
        while (aux != NULL){
            pushPilha(&pA, aux);
            aux = aux->esq;
        }
    } while (pA.top != NULL);
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
    simetrico(raiz);
};