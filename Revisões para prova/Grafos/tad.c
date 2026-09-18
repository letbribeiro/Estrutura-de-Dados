#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
 int id_vizinho;
 struct viz *prox;
}TVizinho;
typedef struct grafo{
 int id;
 struct grafo *prox;
 TVizinho *primeiro_vizinho;
}TGrafo; 