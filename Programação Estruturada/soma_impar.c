#include <stdio.h>
#include <math.h>


int main(void) {

    int contador;
    int p;

    contador = 0;

    for (p = 1; p <= 100; p++) {
        if (p % 2 == 1){
            contador = contador + p;
            printf("%d\n",contador);
        }
}
   
}