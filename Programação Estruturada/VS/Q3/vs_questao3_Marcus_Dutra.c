#include<stdio.h>
#include<stdlib.h>

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

typedef struct fila{
  int n, ini, tam;
  int *vet;
}TF;

int TF_tamanho(TF *f);
void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);


void rearranjar(TF *f){
    if (TF_tamanho(f) % 2 == 0)
    {
        printf("A lista não é par!");
    }

    // Criar uma pilha vazia.
    TP *pilha = TP_inicializa;
    int metade = (TF_tamanho(f) / 2);

    // Colocar a primeira metade dos elementos na pilha
    for (int i=0; i < metade; i++)
    {
       TP_push(pilha, f->vet);
    }

    // Desempilhar e colocar ao final da filha os elementos da pilha
    while (TP_vazia(pilha) != 0)
    {
        TF_insere(f, TP_pop(pilha));
    }
    
    //Desempilhar novamente
    for (int i=0; i < metade; i++)
    {
       TF_insere(pilha, f->vet);
       TP_pop(pilha) ;
    }
    
    // Colocar a primeira metade dos elementos na pilha
    for (int i=0; i < metade; i++)
    {
       TP_push(pilha, f->vet); 
    }
    
    //Intercalar os elementos da pilha com a fila
    while (TP_vazia(pilha) != 0)
    {
        TF_insere(f, TP_pop(pilha));
        TF_insere(pilha, f->vet);
        TP_pop(pilha);
    }

}

int main(){
    TF *f = TF_inicializa();

    TF_insere(f,1);   
    TF_insere(f,2);
    TF_insere(f,3);
    TF_insere(f,4);
    TF_insere(f,5);
    TF_insere(f,6);
    TF_insere(f,7);
    TF_insere(f,8);
    TF_insere(f,9);
    TF_insere(f,10);

    printf("Fila original:\n");
    TF_imprime(f);         
    printf("\n");    

    printf("Fila rearranjada:\n");
    rearranjar(f);
    TF_imprime(f);         
    printf("\n");    

}


TF *TF_inicializa (void){
  TF *f = (TF *) malloc(sizeof (TF));
  f->tam = 1;
  f->vet = (int *) malloc(sizeof(int) * f->tam);
  f->n = f->ini = 0;
  return f;
}

int incr (int ind, int n){
  return (ind + 1) % n;
}

int TF_vazia (TF *f){
  return f->n == 0;
}

int TF_retira (TF *f){
  if(TF_vazia(f)) exit(1);
  int resp = f->vet[f->ini];
  f->ini = incr(f->ini, f->tam);
  f->n--;
  return resp;
}

void TF_libera (TF *f){
  free(f->vet);
  free(f);
}

void TF_insere (TF *f, int x){
  if(f->n == f->tam){
    int *vet = (int *) malloc(sizeof(int) * f->n * 2);
    int i = f->ini, j = 0;
    while(j < f->n){
      vet[j++] = f->vet[i];
      i = incr(i, f->tam);
    }
    f->ini = 0;
    f->tam *= 2;
    int *aux = f->vet;
    f->vet = vet;
    free(aux);
  }
  int fim = (f->ini + f->n++) % f->tam;
  f->vet[fim] = x;
}

void TF_imprime(TF *f){
  int ind = f->ini, i;
  for(i = 0; i < f->n; i++){
    printf("%d -> %d\n", i + 1, f->vet[ind]);
    ind = incr(ind, f->tam);
  }
}

int TF_tamanho(TF *f){
  return f->n;
}


TP *TP_inicializa (void){
  TP *p = (TP *) malloc(sizeof (TP));
  p->topo = 0;
  p->n = 1;
  p->vet = (int *) malloc(sizeof(int) * p->n);
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

void TP_push(TP *p, int i){
  if(p->topo == p->n){
    p->n *= 2;
    p->vet = realloc(p->vet, p->n * sizeof(int));
  }
  p->vet[p->topo].i = i;
  p->topo++;
}

