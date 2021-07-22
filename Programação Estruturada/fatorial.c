#include <stdio.h>

int fatorial_de_numero (int n);
int main(void) {

    int n;
    int resultado;

    printf("Digite aqui um inteiro positivo: ");
    scanf("%d",&n);

    resultado = fatorial_de_numero(n);

    printf("O fatorial de %d = %d",n,resultado);
}

int fatorial_de_numero (int n){ 
    int f = 1;
    
    for (int p = 1; p <= n; p++){
        f = f*p;
    }
    return f;   
}