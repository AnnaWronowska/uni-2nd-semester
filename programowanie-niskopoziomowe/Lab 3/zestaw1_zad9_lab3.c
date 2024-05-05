#include <stdio.h>

int suma_cyfr(int licz)
{
    if(licz / 10 == 0)
    {
        return licz;
    }
    else
    {
        return licz % 10 + suma_cyfr(licz / 10);
    }
}

int main()
{
    int n, wynik;
    printf("Podaj n ");
    scanf("%d", &n);
    wynik = suma_cyfr(n);
    printf("%d", wynik);
    return 0;
}
