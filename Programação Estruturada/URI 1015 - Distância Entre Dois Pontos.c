#include <stdio.h>
#include <math.h>

float distancia(float x1, float x2, float y1, float y2);
    
int main(void) {

    float x1, x2, y1, y2;

    scanf("%f %f",&x1,&y1);
    scanf("%f %f",&x2,&y2);

    distancia(x1,y1,x2,y2);
}

float distancia(float x1, float y1, float x2, float y2) {
    
    float resultado;
    float a = x2-x1;
    float b = y2-y1;

    resultado = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    printf("%.4f",resultado);
}