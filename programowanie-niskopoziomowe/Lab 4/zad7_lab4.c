#include <stdio.h>

int main()
{
    // dokonczyc konwersje wedlug drugiego schematu
    char c, tmp, choice;
    int depth = 0, prev = 0, i = 0, zmiana = 0, j, odj;
    int tab[] ={0, 0, 0, 0, 0, 0};
    int tab2[] = {65, 1, 97, 1, 97, 1};
    FILE *in, *out;
    in = fopen("test7_in.txt", "r");
    out = fopen("test7_out.txt", "w");
    if(in == NULL || out == NULL)
    {
        printf("Blad odczytu pliku");
    }
    printf("Ktorym sposobem chcesz zrobic konwersje?\nA - 1.1.1.1\nB -   a.\n");
    scanf("%c", &choice);
    switch(choice)
    {
    case 'A':
        while(1)
        {
            c = fgetc(in);
            if(c == EOF)
            {
                break;
            }
            if(c == '*')
            {
                zmiana = 1;
                depth++;
            }
            else
            {
                if(zmiana == 1)
                {
                    if(depth < prev)
                    {
                        for(j = depth; j < 6; j++)
                        {
                            tab[j] = 0;
                        }
                    }
                    tab[depth - 1]++;
                    for(j = 0; j < depth - 1; j++)
                    {
                        fputs("  ", out);
                    }
                    while(tab[i] != 0)
                    {
                        fprintf(out, "%d", tab[i]);
                        fputc('.', out);
                        i++;
                    }
                    i = 0;
                    prev = depth;
                    depth = 0;
                    zmiana = 0;
                }
                fputc(c, out);
            }
        }
    case 'B':
        while(1)
        {
            c = fgetc(in);
            if(c == EOF)
            {
                break;
            }
            if(c == '*')
            {
                zmiana = 1;
                depth++;
            }
            else
            {
                if(zmiana == 1)
                {
                    if(depth < prev)
                    {
                        for(j = depth; j < 6; j++)
                        {
                            if(j % 2 == 1)
                                tab2[j] = 1;
                            else
                                tab2[j] = 97;
                        }
                    }
                    for(j = 0; j < depth - 1; j++)
                    {
                        fputs("  ", out);
                    }
                    if(depth > 3)
                        fputc('(', out);
                    if(depth % 2 == 0)
                    {
                        fprintf(out, "%d", tab2[depth - 1]);
                    }
                    else
                    {
                        fprintf(out, "%c", tab2[depth - 1]);
                    }
                    if(depth > 3)
                        fputc(')', out);
                    else
                        fputc('.', out);
                    tab2[depth - 1]++;
                    prev = depth;
                    depth = 0;
                    zmiana = 0;
                }
                fputc(c, out);
            }
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
