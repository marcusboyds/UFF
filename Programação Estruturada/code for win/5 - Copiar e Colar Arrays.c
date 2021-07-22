#include <stdio.h>
#define MAX 100

//Copiar Elementos de Um Array para Outro

int main()
{
    int array[MAX];
    int outraArray[MAX];
    
    int * ptr = array;
    int * ptr2 = outraArray;
    int tamanho;
    
    printf("Tamanho da Array: ");
    scanf("%d",&tamanho);
    
    //1.
    
    //Inserir elementos na array
    printf("Insira Elementos: \n");
    for (int i=0; i < tamanho; i++){
        printf("%d: ",i);
        scanf("%d",ptr);
        ptr++;
    }
    
    //Insira Elementos na outraArray
    printf("Insira Elementos: \n");
    for (int i=0; i < tamanho; i++){
        printf("%d: ",i);
        scanf("%d",ptr2);
        ptr2++;
    }
    
    //2.

    ptr = array;
    ptr2 = outraArray;
    
    //Imprimir array a ser copiada
    printf("Array a ser copiada: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr);
        ptr++;
    }
    //Imprimir a outraArray antes da cola;
    printf("\nArray a ser colada: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr2);
        ptr2++;
    }
    
    printf("\n");
    
    //3.
    
    ptr = array;
    ptr2 = outraArray;
    
    for (int i=0; i < tamanho; i++){
        *ptr2 = *ptr;
        ptr2++;
        ptr++;
    }
    
    //4.
    
    ptr = array;
    ptr2 = outraArray;
    
     printf("Array que foi copiada: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr);
        ptr++;
    }
    
    printf("\nArray depois de ser colada: ");
    for (int i=0; i < tamanho; i++){
        printf("%d, ",*ptr2);
        ptr2++;
    }
    
    
}