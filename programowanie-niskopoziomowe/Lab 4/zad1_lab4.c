#include <stdio.h>

int main()
{
    int count=0;
    char c, tmp;
    FILE *plik;
    plik = fopen("test.txt", "r");
    if(plik == NULL)
    {
        printf("Blad otwarcia pliku");
    }
    printf("Podaj szukany znak: ");
    scanf("%c", &c);
    while(!feof(plik))
    {
        tmp = fgetc(plik);
        if(tmp == c)
        {
            count++;
        }
    }
    fclose(plik);
    printf("%d", count);
    return 0;
}
