#include <stdio.h>
void somador(int * p);

int main()
{
    int n;
    int* array;
    int maior = 0;
    
    printf("Digite quantos numeros: ");
    scanf("%d",&n);
    
    //Array a ser alocada
    array = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++){
        scanf("%d",(array+i));       
    }    

    for (int i = 0; i < n; i++){
        int atual = *(array+i);
        
        if (atual > maior) {
            maior = atual;
        }
    }
    
    printf("%d", maior);
    
    free(array)
    
    return 0; 
}