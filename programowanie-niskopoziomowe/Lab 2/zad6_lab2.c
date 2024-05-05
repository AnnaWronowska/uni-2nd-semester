#include <stdio.h>
int main()
{
    int a, i, j, sum1, sum2;
    printf("Podaj a: ");
    scanf("%d", &a);
    for(i=1; i<=a; i++)
    {
        sum1 = 0;
        sum2 = 0;
        for(j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                sum1 = sum1 + j;
            }
        }
        if(sum1 <= i)
        {
            continue;
        }
        for(j=1; j<sum1; j++)
        {
            if(sum1 % j == 0)
            {
                sum2 = sum2 + j;
            }
        }
        if(sum2 == i)
        {
            printf("%d %d\n", i, sum1);
        }
    }
    return 0;
}
