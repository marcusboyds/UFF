#include "TLC.h"

TLC* TLC_cria(){
  return NULL;
}



TLC* _retira_rec(TLC *l, TLC * p, char *info){

  // Se o nó foi encontrado
  if (strcmp(p->info,info)==0){
        TLC * aux = p->prox;
        free(p);
        return aux;
  }
  // Se não for o último elemento da lista, tentar remover o elemento da lista começando
  // do elemento seguinte e atribua o endereço da lista resultante
  // ao campo próximo do elemento atual (p) para garantir o encadeamento
  else if (p!=l){
    p->prox = _retira_rec(l,p->prox,info);
    return p;
  }
  else{
    return p;
  }// É o ultimo elemento e devemos retornar a lista atual;
}


TLC * TLC_retira_rec(TLC *l,char *info){
  if (!l) {//Se a lista for vazia, nada deve ser feito
    return NULL;
  }
  else if (strcmp(l->info,info)==0){//Se o primeiro nó e o procurado
    if (l==l->prox){ //Se ele for único remover
        free(l);
        return NULL;
    }
    else{ //senão, a nova lista de sua remoção como último nó
          //da busca
        l = _retira_rec(l,l->prox,info);
    }
  }
  else{ // caso contrário, a lista a ser retornada é a cabeça concatenada com a remoção na cauda da lista
        l->prox = _retira_rec(l,l->prox,info);
  }
  return l;
}




TLC* _insere_rec(TLC *l, TLC * p, char *info){

  if (p == l){ //Inserção após o último elemento
    TLC* novo = (TLC*) malloc (sizeof(TLC));
    strcpy(novo->info, info);
    novo->prox = l;
    return novo;
  }
  else{
    // O nó atual deve ter como próximo a lista resultante da inserção na cauda
    p->prox = _insere_rec(l,p->prox,info);
    //Retornar a cabeça da lista atual
    return p;
  }
}


TLC*  TLC_insere_rec(TLC * l, char *info){
  if (!l){//Inserção em lista vazia
    TLC* novo = (TLC*) malloc (sizeof(TLC));
    strcpy(novo->info, info);
    novo->prox = novo;
    return novo;
  }
  else{
    l->prox = _insere_rec(l,l->prox,info);
    return l;
  }
}


TLC* TLC_insere(TLC *l, char *info){
  TLC* novo = (TLC*) malloc (sizeof(TLC));
  strcpy(novo->info, info);
  if(!l){
    novo->prox = novo;
    return novo;
  }
  TLC *p = l->prox, *ant = l;
  while(p != l){
    ant = p;
    p = p->prox;
  }
  novo->prox = l;
  ant->prox = novo;
  return l;
}




TLC* TLC_retira(TLC *l, char *info){
  //Se existir uma lista
  if (l){
    //Procurar  o elemento na lista e seu anterior caso existam
    TLC *ant = l, *p = l->prox;
    while ( (p!=l) && (strcmp(p->info, info)!=0)){
      ant = p;
      p = p->prox;
    } 
    //Se o elemento foi encontrado
    if (strcmp(p->info, info)==0){
      //Se houver mais de um nó, aux recebe o próximo, caso contrário é permanece NULL
      if (p!=p->prox){
        ant->prox = p->prox;
        if (p==l){
          l = l->prox;
        }
      }
      else{ // (p==p->prox)
        l = NULL;
      }
      free(p);
    }
  } 

  return l;

}
 
void TLC_imprime(TLC *l){
  printf("---------------------------\n");
  printf("Lista de candidatos\n");
  printf("---------------------------\n");
  if(l){
    printf("%s\n", l->info);
    TLC *p = l->prox;
    while(p != l){
      printf("%s\n", p->info);
      p = p->prox;
    }
  }
  printf("---------------------------\n\n");
}

void TLC_libera(TLC *l){
  if(l){
    TLC *p = l->prox;
    while(p != l){
      TLC *temp = p;
      p = p->prox;
      free(temp);
    }
    free(l);
  }
}

void TLC_executa(TLC *l, void (*visita)(const TLC *p)){
  if (l){
    visita(l);
    TLC *p = l->prox;
    while (p != l){
      visita(p);
      p = p->prox;
     }
  }
}