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
    struct list* next;
} List;

int checarIgual(List *cabeca1, List *cabeca2) {
    
    while(cabeca1 != NULL && cabeca2 != NULL) {
	
	    if(cabeca1->info != cabeca2->info) return 0;
	    
	    cabeca1 = cabeca1->next;
	    cabeca2 = cabeca2->next;
	}
	
	if (cabeca1 != NULL) return 0;
    if (cabeca2 != NULL) return 0;
    
    return 1;   
}

void bubbleSort(List *cabeca)
{
    int trocado, i;
    List *ponteiro1;
    List *lptr = NULL;
  
    /* Checking for empty list */
    if (cabeca == NULL)
        return;
  
    do
    {
        trocado = 0;
        ponteiro1 = cabeca;
  
        while (ponteiro1->next != lptr)
        {
            if (ponteiro1->info > ponteiro1->next->info)
            { 
                troca(ponteiro1, ponteiro1->next);
                trocado = 1;
            }
            ponteiro1 = ponteiro1->next;
        }
        lptr = ponteiro1;
    }
    while (trocado);
}

void troca(List *a, List *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

TNoA* novoNo(char info) {
    TNoA *novo = malloc (sizeof(TNoA));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = info;
    return novo;
}

List* planificar(TNoA* root) {
    List *list1 = (root->esq) ? planificar(root->esq) : NULL;
    List *list2 = (root->dir) ? planificar(root->dir) : NULL;
    List *list3 = newNode(root->info);
    list3->next = list2; 
    if (!list1) return list3; 
    List *last = list1;
    while (last->next) last=last->next; 
    last->next = list3; 
    return list1;
}


/*
 * Funcao deve retornar 1 caso as arvores tenham os mesmos nos (mesmo que em posicoes distintas), e 0 caso contrario
 */
int mesmos_nos(TNoA *a1, TNoA *a2) {

    List* lista1 = NULL;
    List* lista2 = NULL;

    //Planificação da Árvores para se tornarem listas.
    lista1 = planificar(a1);
    lista2 = planificar(a2);

    while(cabeca1 != NULL && cabeca2 != NULL) {
	
	    if(cabeca1->info != cabeca2->info) return 0;
	    
	    cabeca1 = cabeca1->next;
	    cabeca2 = cabeca2->next;
	}
	
	if (cabeca1 != NULL) return 0;
    if (cabeca2 != NULL) return 0;
    
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

