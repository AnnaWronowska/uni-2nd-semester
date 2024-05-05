#include <stdio.h>

struct Towar
{
    char nazwa_towaru[50];
    int liczba_sztuk;
    int cena_za_sztuke;
};

void wypisz_towary(struct Towar towary[], int L)
{
    printf("Nazwa towaru\tLiczba sztuk\tCena za sztuke\n");
    for(int i = 0; i < L; i++)
    {
        printf("%s\t\t%d\t\t%d\n", towary[i].nazwa_towaru, towary[i].liczba_sztuk, towary[i].cena_za_sztuke);
    }
}

int suma_towarow(struct Towar towary[], int L)
{
    int suma=0;
    for(int i = 0; i < L; i++)
    {
        suma = suma + towary[i].liczba_sztuk*towary[i].cena_za_sztuke;
    }
    return suma;
}

int main()
{
    int last=0;
    char comm;
    struct Towar towar[50];
    while(1)
    {
        printf("Podaj komende ");
        scanf("%c", &comm);
        fflush(stdin);
        if(comm == 'n' || comm == 'N')
        {
            if(last < 50)
            {
                printf("Podaj nazwe towaru ");
                scanf("%s", &towar[last].nazwa_towaru);
                fflush(stdin);
                printf("Podaj liczbe sztuk towaru ");
                scanf("%d", &towar[last].liczba_sztuk);
                fflush(stdin);
                printf("Podaj cene za sztuke ");
                scanf("%d", &towar[last].cena_za_sztuke);
                fflush(stdin);
                last++;
            }
            else
            {
                printf("Osiagnieto maksymalna pojemnosc rejestru towarow\n");
            }
        }
        else if(comm == 'w' || comm == 'W')
        {
            wypisz_towary(towar, last);
        }
        else if(comm == 'r' || comm == 'R')
        {
            printf("%d\n", suma_towarow(towar, last));
        }
        else if(comm == 'q' || comm == 'Q')
        {
            break;
        }
        else
        {
            printf("Podano nieprawidlowa komende!\n");
        }
    }
    return 0;
}
