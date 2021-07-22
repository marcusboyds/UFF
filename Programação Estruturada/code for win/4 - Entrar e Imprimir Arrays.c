#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    
    int tamanho;
    int array[MAX_SIZE];
    int *ptr = array;
    
    printf("Entra o tamanho: ");
    scanf("%d",&tamanho);
    
    for (int i=0; i < tamanho; i++) {
        scanf("%d",ptr);
        ptr++;
    }
    
    ptr = array;
    
    for (int i=0; i < tamanho; i++)
        printf("%d", *ptr);
        
        ptr++;
}