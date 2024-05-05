#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int size = 5, count = 1, tmp = 0;
    float a = 0, b = 0, j = 0;
    int *arr = (int)malloc(size * sizeof(int));
    int *size_arr = (int)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
        size_arr[i] = 0;
    }
    FILE *in, *out;
    in = fopen("test8_in.txt", "r");
    out = fopen("test8_out.txt", "w");
    if(in == NULL || out == NULL)
    {
        printf("Blad odczytu pliku");
    }
    while(1)
    {
        c = fgetc(in);
        if (count >= size)
        {
            int* temp_arr = realloc(arr, count * sizeof(int));
            arr = temp_arr;
            int* temp_size_arr = realloc(size_arr, count * sizeof(int));
            size_arr = temp_size_arr;
            arr[count] = 0;
            size_arr[count] = 0;
            size = count;
        }
        if (c == EOF)
        {
            arr[count-1] += tmp;
            size_arr[count-1]++;
            break;
        }
        if(c == ' ')
        {
            arr[count-1] += tmp;
            size_arr[count-1]++;
            count++;
            tmp = 0;
            continue;
        }
        else if (c == '\n')
        {
            c = c - '0';
            arr[count-1] += tmp;
            size_arr[count-1]++;
            count = 1;
            tmp = 0;
            continue;
        }
        c = c - '0';
        tmp = tmp * 10 + c;
    }
    fprintf(out, "Suma: ");
    for (int i = 0; i < size; i++)
    {
        fprintf(out, "%d ", arr[i]);
        fputc(' ', out);
    }
    fputc('\n', out);
    fprintf(out, "Srednia: ");
    for (int i = 0; i < size; i++)
    {
        a = arr[i];
        b = size_arr[i];
        if (size_arr[i] != 0)
        {
            j = a / b;
        }
        else
        {
            j = 0;
        }
        fprintf(out, "%g", j);
        fputc(' ', out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
