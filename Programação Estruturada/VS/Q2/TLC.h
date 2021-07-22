#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
  char info[31];
  struct lc *prox;
} TLC;

TLC* TLC_cria();
TLC* TLC_insere(TLC *l, char *info);
TLC* TLC_insere_rec(TLC *l, char *info);
TLC* TLC_retira(TLC *l, char *info);
TLC* TLC_retira_rec(TLC *l, char *info);
void TLC_imprime(TLC *l);
void TLC_libera(TLC *l);
void TLC_executa(TLC *l, void (*visita)(const TLC *p));
