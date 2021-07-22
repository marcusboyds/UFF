#include <stdio.h>

int main()
{
    int professor;
    int viado;
    
    int *do_ = &professor;
    int *caralho = &viado;
    
    
    scanf("%d",&professor);
    scanf("%d",&viado);
   
    do_ = &viado;
    caralho = &professor;
    
    printf("professor = %d\n",*do_);
    printf("viadoo = %d",*caralho);
    
    return 0;
}