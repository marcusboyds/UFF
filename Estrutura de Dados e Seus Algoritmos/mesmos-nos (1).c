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
    int key;
    struct list* next;
} List;

void printarLista(TNoA* lista){
    while (lista != NULL){
        printf("%c",lista->info);
        lista = lista->esq;
    }
}

int check_equal(List *head1, List *head2) {
    
    while(head1 != NULL && head2 != NULL) {
	
	    if(head1->key != head2->key) return 0;
	    
	    head1 = head1->next;
	    head2 = head2->next;
	}
	
	if (head1 != NULL) return 0;
    if (head2 != NULL) return 0;
    
    return 1;
}

void bubbleSort(List *start)
{
    int swapped, i;
    List *ptr1;
    List *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->key > ptr1->next->key)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(List *a, List *b)
{
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}

TNoA* newNode (char key) {
    TNoA *new = malloc (sizeof(TNoA));
    new->esq = NULL;
    new->dir = NULL;
    new->info = key;
    return new;
}

List* planificar(TNoA* root) {
    List *list1 = (root->esq) ? planificar(root->esq) : NULL;
    List *list2 = (root->dir) ? planificar(root->dir) : NULL;
    List *list3 = newNode(root->info);
    // The "middle" list3 cannot be NULL; append list2 to list3
    list3->next = list2; // If list2 is NULL, it's OK
    if (!list1) return list3; // Nothing to prepend
    List *last = list1;
    while (last->next) last=last->next; // Go to the end of list1
    last->next = list3; // Append list3+list2 to the end of list1
    return list1;
}

/*
 * Funcao deve retornar 1 caso as arvores tenham os mesmos nos (mesmo que em posicoes distintas), e 0 caso contrario
 */
int mesmos_nos(TNoA *a1, TNoA *a2) {
    
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
    
    List* lista1 = NULL;
    List* lista2 = NULL;

    //Planificar as Listas
    lista1 = planificar(a1);
    lista2 = planificar(a2);
    
    printarLista(lista1);
    printf("\n");
    printarLista(lista2);
    printf("\n");
    //Ordenar a lista2
    bubbleSort(lista1);
    bubbleSort(lista2);
    
    printarLista(lista1);
    printf("\n");
    printarLista(lista2);
    
    //Verificar se é igual
    printf("\n");
    printf("%d",check_equal(lista1, lista2));
    
}

