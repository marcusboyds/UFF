#include "TP.h"

TP *TP_inicializa (void){
  TP *p = (TP *) malloc(sizeof (TP));
  p->topo = 0;
  p->n = 1;
  p->vet = (Par_int *) malloc(sizeof(Par_int) * p->n);
  return p;
}
 
int TP_vazia (TP *p){
  return p->topo == 0;
}

int TP_pop(TP *p){
  if(TP_vazia(p)) exit(1);
  int resp = p->vet[--p->topo];
  return resp;
}

void TP_libera(TP *p){
  free(p->vet);
  free(p);
}

void TP_push(TP *p, int i, int j){
  if(p->topo == p->n){
    p->n *= 2;
    p->vet = realloc(p->vet, p->n * sizeof(Par_int));
  }
  p->vet[p->topo].i = i;
  p->vet[p->topo].j = j;
  p->topo++;
}

void TP_imprime(TP *p){
  int i;
  for(i = p->topo - 1; i >= 0; i--)
    printf("%d -> (%d,%d)\n", p->topo - i, p->vet[i].i, p->vet[i].j);
}
