#include "TLDE.h"

TLDE* TLDE_insere(TLDE *l, int elem){
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->ant = NULL;
  novo->prox = l;
  novo->info = elem;
  if(l) l->ant = novo;
  return novo;
}

void TLDE_imprime(TLDE *l){
  TLDE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLDE_libera(TLDE *l){
  TLDE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLDE* TLDE_retira(TLDE *l, int elem){
  TLDE *p = TLDE_busca(l, elem);
  if(!p) return l;
  if(p == l) l = l->prox;
  else p->ant->prox = p->prox;
  if(p->prox) p->prox->ant = p->ant;
  free(p);
  return l;
}

TLDE* TLDE_busca(TLDE *l, int elem){
  TLDE *p = l;
  while(p){
    if(p->info == elem) return p;
    p = p->prox;
  } 
  return NULL;
}

