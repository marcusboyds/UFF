#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;

TLDE* TLDE_insere(TLDE *l, int elem);
void TLDE_imprime(TLDE *l);
void TLDE_libera(TLDE *l);
TLDE* TLDE_retira(TLDE *l, int elem);
TLDE* TLDE_busca(TLDE *l, int elem);

