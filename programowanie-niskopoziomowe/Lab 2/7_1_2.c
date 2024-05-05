#include <stdio.h>
#include <string.h>
int main()
{
    int i = 1, j=1, a;
    char o[] = "O";
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &a);
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("O");
        }
        printf("\n");
    }
    return 0;
}
