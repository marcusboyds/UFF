#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;

TLDE* TLDE_busca(TLDE *l, int elem);
TLDE* TLDE_insere(TLDE *l, int elem);

TLDE* TLDE_insere(TLDE *l, int elem){
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->ant = NULL;
  novo->prox = l;
  novo->info = elem;
  if(l) l->ant = novo;
  return novo;
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

TLDE *TLDE_remove_duplicados(TLDE *l){
    //Criar o ponteiro auxiliar.
    TLDE *aux = l;

    //Fazer o ponteiro andar por todo o array
    while (l != NULL)
    {
        //Checar se todos os números depois do ponteiro são iguais.
        while (aux != NULL && aux->prox != NULL)
        {
            if (aux->prox->info == l->info){
                TLDE_retira(aux, l->info);
            }
            aux = aux->prox;
        }
        l = l->prox;
        aux = l;
    }
    
    return NULL;
}

int main(){
  
  TLDE *l = NULL;
  
  l = TLDE_insere(l, 1);
  l = TLDE_insere(l, 2);
  l = TLDE_insere(l, 1);
  l = TLDE_insere(l, 2);
  l = TLDE_insere(l, 1);
  TLDE_remove_duplicados(l);
 
  }
