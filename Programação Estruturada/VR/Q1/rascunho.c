#include <stdio.h>

int sumArray(int anArray[], int size)
    {
        //base case
        if (size == 0)
        {
            return 0;
        }
        else if (size == 1)
        {
            return anArray[0];
        }
    
        //divide and conquer
        int mid = size / 2;
        int rsize = size - mid;
        int lsum = sumArray(anArray, mid);
        int rsum = sumArray(anArray + mid, rsize);
        return lsum + rsum;
    }

int main()
{
    int array[4] = {1,2,3,4};
    int soma = sumArray(array, 4);
    printf("Soma é %d", soma);
}
