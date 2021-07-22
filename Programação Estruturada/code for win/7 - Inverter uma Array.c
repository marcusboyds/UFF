#include <stdio.h>
#define MAX 100

#include <stdio.h>
#define MAX 100

int main()
{
    int array[MAX];
    int reverseArray[MAX];
    int tamanho;
    
    int* ptr = array;
    int* ptr2 = reverseArray;
    
    printf("Tamanho da Array: ");
    scanf("%d",&tamanho);
    
    for (int i=0; i < tamanho; i++){
        scanf("%d",ptr);
        ptr++;
    }
    
    //Reseta o ponteiro
    ptr = array;
    
    //Função que reverte
    for (int i = tamanho - 1; i >= 0; i--){
      *ptr2 = *(ptr+i);
      ptr2++;
    }
    
    ptr2 = reverseArray;
    
    printf("Array Normal: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr);
        ptr++;
    }
    
    printf("\nArray Invertida: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr2);
        ptr2++;
    }
}