#include <stdio.h>

int main() {

    int a, b;

    scanf("%d %d",&a,& b)

    if (a < b)
    {
        if (b % a == 0)
        {
           printf("Sao Multiplos") 
        }
        else {
            printf("Nao sao Multiplos")
        }
    }
    
    else if (a > b)
    {
        if (a % b == 0)
        {
           printf("Sao Multiplos") 
        }
        else {
            printf("Nao sao Multiplos")
        }
    }
    
    if (a == b)
    {
        printf("Sao Multiplos")
    }
    
    return 0;
}