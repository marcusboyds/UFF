#include <stdio.h>
#include <math.h>

void main() {
    float a;
    float b;
    float c;
    scanf("%f;%f;%f",&a,&b,&c);

    float delta = b*b-4*a*c;

    float r1 = (-b+sqrt(delta))/2*a;
    float r2 = (-b-sqrt(delta))/2*a;

    printf("Raiz 1 = %2f e Raiz 2 = %2f",r1,r2);

}