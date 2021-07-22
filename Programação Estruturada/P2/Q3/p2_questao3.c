#include<stdio.h>
#include<stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;

TLDE* TLDE_insere(TLDE *l, int elem);
void TLDE_imprime(TLDE *l);
void TLDE_libera(TLDE *l);
TLDE* TLDE_retira(TLDE *l, int elem);
TLDE* TLDE_busca(TLDE *l, int elem);

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

//-----------------------------//

TLDE *TLDE_copia_apos(TLDE *l,int x);
TLDE *TLDE_copia_ant(TLDE *l,int x);

TLDE *TLDE_copia_apos(TLDE *l, int x){
    
    //Trava de Segurança
    if(l == NULL){return NULL;}
    
    TLDE* temp, *no = l;
    while(no->info != x)
    {
        temp = no;
        no = no->prox;
        free(temp);
    }
    
  return no;
}

TLDE *TLDE_copia_ant(TLDE *l, int x){

    //Trava de Segurança
    if(l == NULL){return NULL;}
  
    TLDE *temp, *no = l;
    while (no->prox != NULL)
    {
        no = no->prox;
    }
    
    
    while(no->info != x)
    {
        temp = no;
        no = no->ant;
        free(temp);
    }
    return no;
}

void teste(TLDE *l, int x){

    printf("Teste para x = %d\n",x);

    TLDE *copia_l1 = TLDE_copia_ant(l,x);
    TLDE *copia_l2 = TLDE_copia_apos(l,x);

    printf("copia antes:");
    TLDE_imprime(copia_l1);
    printf("\n");
    printf("copia apos:");
    TLDE_imprime(copia_l2);
    printf("\n\n");

    TLDE_libera(copia_l1);
    TLDE_libera(copia_l2);

}

int main(void){
    TLDE *l = NULL;
    int x;

    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    teste(l,0);
    teste(l,9);
    teste(l,3);
    teste(l,30);

    TLDE_libera(l);

    l = TLDE_insere(l, 9);
    l = TLDE_insere(l, 8);
    l = TLDE_insere(l, 7);
    l = TLDE_insere(l, 6);
    l = TLDE_insere(l, 5);
    l = TLDE_insere(l, 4);
    l = TLDE_insere(l, 3);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 0);

    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    teste(l,0);
    teste(l,9);
    teste(l,3);
    teste(l,30);

    TLDE_libera(l);
    
  return 0;
}


