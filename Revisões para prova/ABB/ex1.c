#include "tad.c"

TABB* maior(TABB *a){
    if (a == NULL) return NULL;
    if (a->dir == NULL) return a;
    return maior(a->dir);
}