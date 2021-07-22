#include <stdio.h>
#include <math.h>

void main(){

    float a,b,c;
    
    printf("BOA TARDE! Digite os 3 coefiecientes a,b e c: \n");
    scanf("%f;%f;%f",&a,&b,&c);

    float delta = b*b-4*a*c;

    if (delta<0){
        printf("Nem da men delta é negativo ou a é zero \n");
    }
    else {
        float r1 = (-b+sqrt(delta))/2*a;
        float r2 = (-b-sqrt(delta))/2*a;

        printf("Raiz 1 = %f e Raiz 2 = %f",r1,r2);
    }
}