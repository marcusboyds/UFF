#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int topo, n;
  int *vet;
}TP;	

void TP_push(TP *p, int i);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);
