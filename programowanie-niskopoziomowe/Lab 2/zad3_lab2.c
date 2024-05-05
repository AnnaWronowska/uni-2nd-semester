#include <stdio.h>
int main()
{
    // i oraz j od 1 czy 0
    int i=1, j=1, n, m;
    double r=0, licz, mian, ilocz, tmp;
    printf("Podaj n: ");
    scanf("%d", &n);
    printf("Podaj m: ");
    scanf("%d", &m);
    for(i=1; i<n; i++)
    {
        ilocz = 1;
        for(j=1; j<m; j++)
        {
            licz = i*i + j*j - 1;
            mian = 2*i + 3*j + 4;
            tmp = licz / mian;
            ilocz = ilocz * tmp;
        }
        r = r + ilocz;
    }
    printf("%d", r);
    return 0;
}
