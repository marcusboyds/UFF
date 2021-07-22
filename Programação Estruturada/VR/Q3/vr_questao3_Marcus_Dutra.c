#include<stdio.h>
#include<stdlib.h>
#include "TLDE.h"

TLDE *TLDE_remove_duplicados(TLDE *l);

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
                aux = TLDE_retira(l->prox, l->info);
            }
            aux = aux->prox;
        }
        l = l->prox;
        aux = l;
    }
    
    return NULL;
}

void teste0(){

    printf("------------Teste 0 - Lista vazia------------\n");
    TLDE *l = NULL;

    TLDE_libera(l);

    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    l = TLDE_remove_duplicados(l);

    printf("l sem duplicatas:");
    TLDE_imprime(l);
    printf("\n\n");

    TLDE_libera(l);

}

void teste1(){
    TLDE *l = NULL;

    printf("-------------------Teste 1---------------------\n");

    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 3);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 4);
    l = TLDE_insere(l, 3);
    l = TLDE_insere(l, 4);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);


    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    l = TLDE_remove_duplicados(l);

    printf("l sem duplicatas:");
    TLDE_imprime(l);
    printf("\n\n");

    TLDE_libera(l);

}



void teste2(){
   TLDE *l = NULL;

    printf("-------------------Teste 2---------------------\n");


    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 1);


    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    l = TLDE_remove_duplicados(l);

    printf("l sem duplicatas:");
    TLDE_imprime(l);
    printf("\n\n");

    TLDE_libera(l);

}


void teste3(){
   TLDE *l = NULL;

    printf("-------------------Teste 3---------------------\n");


    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 3);
    l = TLDE_insere(l, 4);
    l = TLDE_insere(l, 5);
    l = TLDE_insere(l, 6);
    l = TLDE_insere(l, 7);
    l = TLDE_insere(l, 7);
    l = TLDE_insere(l, 9);
    l = TLDE_insere(l, 10);


    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    l = TLDE_remove_duplicados(l);

    printf("l sem duplicatas:");
    TLDE_imprime(l);
    printf("\n\n");

    TLDE_libera(l);

}

void teste4(){
   TLDE *l = NULL;

    printf("-------------------Teste 4---------------------\n");


    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);
    l = TLDE_insere(l, 1);
    l = TLDE_insere(l, 2);


    printf("l:");
    TLDE_imprime(l);
    printf("\n\n");

    l = TLDE_remove_duplicados(l);

    printf("l sem duplicatas:");
    TLDE_imprime(l);
    printf("\n\n");

    TLDE_libera(l);

}

int main(void){
    teste0();
    teste1();
    teste2();
    teste3();
    teste4();
    
    return 0;
}


