#include <stdio.h>
#include <stdlib.h>

int comparador(const void *a, const void *b){
    if (*(int*)a > *(int*)b){return 1;}
    if (*(int*)a < *(int*)b){return -1;}
    else{return 0;}
}

int main(){

    int i, lista[5] = {5,4,9,45,15};

    printf("Lista original:");
    for (i = 0; i < 5; i++)
    {
        printf("%d, ",lista[i])
    }

    qsort(lista, 5, sizeof(int), comparador2)

    printf("Lista ordenada:")
    for (i = 0; i < 5; i++)
    {
        printf("%d, ",lista[i])
    }
    
    return 0;
}