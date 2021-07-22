#include<stdio.h>
#include<stdlib.h>
#include"TLSE.h"

TLSE * reverter_pares(TLSE * l){
  
  if (l == NULL || l->prox == NULL){
    return l;}
    
    trocar(&l->info, &l->prox->info);
    reverter_pares(l->prox->prox);
    return l;
}

void trocar(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void teste0(){
    TLSE *prim = NULL;

    printf("prim:");
    TLSE_imprime(prim);
    printf("\n");

    prim = reverter_pares(prim);
    printf("prim (pares reversos):");
    TLSE_imprime(prim);
    printf("\n");

    TLSE_libera(prim);

}

void teste1(){
    TLSE *prim = NULL;
    
    prim = TLSE_insere(prim,5);

    printf("prim:");
    TLSE_imprime(prim);
    printf("\n");

    prim = reverter_pares(prim);
    printf("prim (pares reversos):");
    TLSE_imprime(prim);
    printf("\n");

    TLSE_libera(prim);

}

void teste2(){
    TLSE *prim = NULL;
    
    prim = TLSE_insere(prim,5);
    prim = TLSE_insere(prim,4);


    printf("prim:");
    TLSE_imprime(prim);
    printf("\n");

    prim = reverter_pares(prim);
    printf("prim (pares reversos):");
    TLSE_imprime(prim);
    printf("\n");

    TLSE_libera(prim);

}

void teste3(){
    TLSE *prim = NULL;
    
    prim = TLSE_insere(prim,5);
    prim = TLSE_insere(prim,4);
    prim = TLSE_insere(prim,1);
    prim = TLSE_insere(prim,2);
    prim = TLSE_insere(prim,7);
    prim = TLSE_insere(prim,9);
    prim = TLSE_insere(prim,8);

    printf("prim:");
    TLSE_imprime(prim);
    printf("\n");

    prim = reverter_pares(prim);
    printf("prim (pares reversos):");
    TLSE_imprime(prim);
    printf("\n");   

    TLSE_libera(prim);

}

int main() {
  teste0();
  teste1();
  teste2();
  teste3();

  return 0;
} 