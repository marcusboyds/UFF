#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

typedef struct list {
    int info;
    struct list* dir;
} LSE;

int checarIgual(LSE *lista1, LSE *lista2) {
    
    while(lista1 != NULL && lista2 != NULL) {
	
	    if(lista1->info != lista2->info) return 0;
	    
	    lista1 = lista1->dir;
	    lista2 = lista2->dir;
	}
	
	if (lista1 != NULL) return 0;
    if (lista2 != NULL) return 0;
    
    return 1;   
}

void trocar(LSE *a, LSE *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void bubbleSort(LSE *cabeca)
{
    int trocado;
    LSE *ponteiro1;
    LSE *lptr = NULL;
  
    /* Checking for empty list */
    if (cabeca == NULL)
        return;
  
    do
    {
        trocado = 0;
        ponteiro1 = cabeca;
  
        while (ponteiro1->dir != lptr)
        {
            if (ponteiro1->info > ponteiro1->dir->info)
            { 
                trocar(ponteiro1, ponteiro1->dir);
                trocado = 1;
            }
            ponteiro1 = ponteiro1->dir;
        }
        lptr = ponteiro1;
    }
    while (trocado);
}

TNoA* novaRaiz(char info) {
    TNoA *novo = malloc (sizeof(TNoA));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = info;
    return novo;
}

LSE* novoNo(char info) {
    LSE *novo = malloc (sizeof(LSE));
    novo->dir = NULL;
    novo->info = info;
    return novo;
}

LSE* planificar(TNoA* root) {
    LSE *list1 = (root->esq) ? planificar(root->esq) : NULL;
    LSE *list2 = (root->dir) ? planificar(root->dir) : NULL;
    LSE *list3 = novoNo(root->info);
    list3->dir = list2; 
    if (!list1) return list3; 
    LSE *last = list1;
    while (last->dir) last=last->dir; 
    last->dir = list3; 
    return list1;
}


/*
 * Funcao deve retornar 1 caso as arvores tenham os mesmos nos (mesmo que em posicoes distintas), e 0 caso contrario
 */
int mesmos_nos(TNoA *a1, TNoA *a2) {

    LSE* lista1 = NULL;
    LSE* lista2 = NULL;

    //Planificação da Árvores para se tornarem listas.
    lista1 = planificar(a1);
    lista2 = planificar(a2);

    bubbleSort(lista1);
    bubbleSort(lista2);

    while(lista1 != NULL && lista2 != NULL) {
	
	    if(lista1->info != lista2->info) return 0;
	    
	    lista1 = lista1->dir;
	    lista2 = lista2->dir;
	}
	
	if (lista1 != NULL) return 0;
    if (lista2 != NULL) return 0;
    
    return 1;   
    return 0;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

void imprimeProfundidade(TNoA *nodo, int altura) {
    altura = altura - 1;
    if (nodo != NULL) {
        printf("%c", nodo->info);
        if (altura > 0) {
            imprimeProfundidade(nodo->esq, altura);
            imprimeProfundidade(nodo->dir, altura);
        }
    } else {
        printf("*");
        //Trata caso de subarvore NULL em nível menor que altura da árvore
        if (altura > 0) {
            imprimeProfundidade(NULL, altura);
            imprimeProfundidade(NULL, altura);
        }
    }
}

TNoA *criaArvore(char entrada[100], int tamanho) {
    char novaEntrada[100];
    int i,j;
    TNoA *novo;
    novo = NULL;
    if ((tamanho > 0) && (entrada[0] != '*')) {
        novo = (TNoA *) malloc(sizeof(TNoA));
        novo->info = entrada[0];
        tamanho = tamanho / 2;

        //divide a entrada em duas partes e chama a função criaArvore recursivamente
        i = 1; //inicio da subarvore esquerda na string entrada
        j = 0; //cursor da nova string de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->esq = criaArvore(novaEntrada, tamanho);

        i = tamanho+1; //inicio da subarvore direita na string entrada
        j = 0; //cursor da nova string de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho*2) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->dir = criaArvore(novaEntrada, tamanho);
    }
    return novo;
}

int main (void) {
    /* A função main lê os dados de entrada, cria as árvores e chama a função solicitada no exercício
     * depois imprime o resultado
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TNoA* a1 = NULL;
    TNoA* a2 = NULL;
    int tam;
    char entrada1[100];
    char entrada2[100];

    /* lê valores para criar a árvore 1
     * exemplo: FBC */
    scanf("%s", entrada1);
    tam = strlen(entrada1);
    a1 = criaArvore(entrada1 , tam);

    /* le valores para criar a arvore 2 */
    scanf("%s", entrada2);
    tam = strlen(entrada2);
    a2 = criaArvore(entrada2 , tam);
    
    printf("%d", mesmos_nos(a1, a2));
}

