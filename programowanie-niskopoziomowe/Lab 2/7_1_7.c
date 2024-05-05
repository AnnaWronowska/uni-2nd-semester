#include <stdio.h>
#include <string.h>

int main()
{
    int h, len, x, i;
    char space = " ";
    printf("Podaj wysokosc trojkata: ");
    scanf("%d", &h);
    len = h - 1;
    x = 1;
    while(h>0)
    {
        for(i = 0; i < len; i++)
        {
            printf(" ");
        }
        for(i=0; i < x; i++)
        {
            printf("X");
        }
        for(i = 0; i < len; i++)
        {
            printf(" ");
        }
        printf("\n");
        len = len - 1;
        x = x + 2;
        h--;
    }
    return 0;
}
