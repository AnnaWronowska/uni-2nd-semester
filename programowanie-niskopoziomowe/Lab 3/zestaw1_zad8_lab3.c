#include <stdio.h>
#include <math.h>

int liczba_cyfr(int n)
{
    int k = 0;
    while(n>0)
    {
        n = n / 10;
        k++;
    }
    return k;
}

int main()
{
    int a, b, i, j;
    printf("Podaj a i b\n");
    scanf("%d %d", &a, &b);
    for(i=a; i<=b; i++)
    {
        j = liczba_cyfr(i);
        if(i*i % (int)pow(10, j) == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
