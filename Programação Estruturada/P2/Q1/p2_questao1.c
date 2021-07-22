#include<stdio.h>
#include<stdlib.h>


typedef struct lse{
  int info;
  struct lse *prox;
} TLSE;

TLSE* TLSE_insere(TLSE *l, int elem);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_retira(TLSE *l, int elem);
TLSE* TLSE_busca(TLSE *l, int elem);

void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);
TLSE* TLSE_busca_rec(TLSE *l, int elem);
TLSE* TLSE_retira_rec(TLSE *l, int elem);

TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLSE_imp_rec(TLSE *l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
}

void TLSE_imp_rec_rev(TLSE *l){
  if(l){
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void TLSE_lib_rec(TLSE *l){
  if(l){
    TLSE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLSE* TLSE_retira(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_retira_rec(TLSE *l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

TLSE* TLSE_busca_rec(TLSE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}



TLSE *TLSE_intercala(TLSE* l1, TLSE* l2){

    //Atribuição a novas variáveis
    TLSE *primeiraLista = l1;
    TLSE *segundaLista = l2;
    
    //Assegurança que uma lista vazia retorna exatamente a outra.
    if (primeiraLista == NULL){
      return(segundaLista);
    }
    else if (segundaLista == NULL){
      return(primeiraLista);
    }

    else {
      TLSE aux = *primeiraLista;
      
      primeiraLista->prox = segundaLista;
      segundaLista->prox = TLSE_intercala(aux.prox, segundaLista->prox);

      return(primeiraLista);
    }
}


void teste1(){
    TLSE *l1, *l2, *l3;

    l1 = l2 = l3 = NULL;
    
    printf("*-----------------------------------*\n");    
    printf("*--------------Teste1---------------*\n");
    printf("*-----------------------------------*\n");

    l1 = TLSE_insere(l1,6);
    l1 = TLSE_insere(l1,5);
    l1 = TLSE_insere(l1,4);
    l1 = TLSE_insere(l1,3);
    l1 = TLSE_insere(l1,2);
    l1 = TLSE_insere(l1,1);

    printf("\nl1:");
    TLSE_imprime(l1);
    printf("\n");

    l2 = TLSE_insere(l2,12);
    l2 = TLSE_insere(l2,11);
    l2 = TLSE_insere(l2,10);
    l2 = TLSE_insere(l2,9);
    l2 = TLSE_insere(l2,8);
    l2 = TLSE_insere(l2,7);

    printf("\nl2:");
    TLSE_imprime(l2);
    printf("\n");

    printf("\nIntercalacao de l1 e l2\n");
    l3 = TLSE_intercala(l1,l2);
    printf("\nl3:");
    TLSE_imprime(l3);
    printf("\n");
    TLSE_libera(l3);


}


void teste2(){
    TLSE *l1, *l2, *l3;

    l1 = l2 = l3 = NULL;

    printf("*-----------------------------------*\n");    
    printf("*--------------Teste2---------------*\n");
    printf("*-----------------------------------*\n");

    l1 = TLSE_insere(l1,6);
    l1 = TLSE_insere(l1,5);
    l1 = TLSE_insere(l1,4);
    l1 = TLSE_insere(l1,3);

    printf("\nl1:");
    TLSE_imprime(l1);
    printf("\n");

    l2 = TLSE_insere(l2,12);
    l2 = TLSE_insere(l2,11);
    l2 = TLSE_insere(l2,10);
    l2 = TLSE_insere(l2,9);
    l2 = TLSE_insere(l2,8);
    l2 = TLSE_insere(l2,7);

    printf("\nl2:");
    TLSE_imprime(l2);
    printf("\n");

    printf("\nIntercalacao de l1 e l2\n");
    l3 = TLSE_intercala(l1,l2);
    printf("\nl3:");
    TLSE_imprime(l3);
    printf("\n");
    TLSE_libera(l3);

}


void teste3(){
    TLSE *l1, *l2, *l3;

    l1 = l2 = l3 = NULL;

    printf("*-----------------------------------*\n");    
    printf("*--------------Teste3---------------*\n");
    printf("*-----------------------------------*\n");

    printf("\nl1:");
    TLSE_imprime(l1);
    printf("\n");

    l2 = TLSE_insere(l2,12);
    l2 = TLSE_insere(l2,11);
    l2 = TLSE_insere(l2,10);
    l2 = TLSE_insere(l2,9);
    l2 = TLSE_insere(l2,8);
    l2 = TLSE_insere(l2,7);

    printf("\nl2:");
    TLSE_imprime(l2);
    printf("\n");

    printf("\nIntercalacao de l1 e l2\n");
    l3 = TLSE_intercala(l1,l2);
    printf("\nl3:");
    TLSE_imprime(l3);
    printf("\n");
    TLSE_libera(l3);
}


void teste4(){
    TLSE *l1, *l2, *l3;

    l1 = l2 = l3 = NULL;

    printf("*-----------------------------------*\n");    
    printf("*--------------Teste4---------------*\n");
    printf("*-----------------------------------*\n");

    l1 = TLSE_insere(l1,6);
    l1 = TLSE_insere(l1,5);
    l1 = TLSE_insere(l1,4);
    l1 = TLSE_insere(l1,3);
    l1 = TLSE_insere(l1,2);
    l1 = TLSE_insere(l1,1);


    printf("\nl1:");
    TLSE_imprime(l1);
    printf("\n");

    printf("\nl2:");
    TLSE_imprime(l2);
    printf("\n");

    printf("\nIntercalacao de l1 e l2\n");
    l3 = TLSE_intercala(l1,l2);
    printf("\nl3:");
    TLSE_imprime(l3);
    printf("\n");
    TLSE_libera(l3);
}

void teste5(){
    TLSE *l1, *l2, *l3;

    l1 = l2 = l3 = NULL;

    printf("*-----------------------------------*\n");    
    printf("*--------------Teste5---------------*\n");
    printf("*-----------------------------------*\n");

    l1 = TLSE_insere(l1,6);
    l1 = TLSE_insere(l1,5);
    l1 = TLSE_insere(l1,4);
    l1 = TLSE_insere(l1,3);
    l1 = TLSE_insere(l1,2);
    l1 = TLSE_insere(l1,1);

    printf("\nl1:");
    TLSE_imprime(l1);
    printf("\n");

    l2 = TLSE_insere(l2,12);
    l2 = TLSE_insere(l2,11);
    l2 = TLSE_insere(l2,10);
 

    printf("\nl2:");
    TLSE_imprime(l2);
    printf("\n");

    printf("\nIntercalacao de l1 e l2\n");
    l3 = TLSE_intercala(l1,l2);
    printf("\nl3:");
    TLSE_imprime(l3);
    printf("\n");
    TLSE_libera(l3);
}

int main(void){

    teste1();
    teste2();
    teste3();
    teste4();
    teste5();
    
  return 0;
}