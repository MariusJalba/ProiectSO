#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define CHUNK 100
#include <errno.h>
void BubbleSort(uint32_t *v, int n)
{
    int s, i, aux;
    do
    {
        s = 0; // setam faptul ca nu au avut loc schimbari la iterarea curenta
        for (i = 1; i < n; i++)
        {
            // @1 - pornim de la 1 ca sa formam perechi (v[i-1],v[i])
            if (v[i - 1] < v[i])
            {
                // daca valorile NU respecta relatia de ordine
                aux = v[i - 1]; // interschimba valorile
                v[i - 1] = v[i];
                v[i] = aux;
                s = 1; // @2 - seteaza faptul ca a avut loc cel putin o schimbare
            }
        }
    } while (s); // daca s adevarat (!=0), atunci repeta iterarea
}
void scriere(uint32_t *v, int n_elemente,char *filepath)
{
    FILE *fout;
    if ((fout = fopen(filepath, "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n_elemente; i++)
    {
        fprintf(fout, "%d\n", v[i]);
    }
    fclose(fout);
}
int main(int argc, char **arcgv)
{
    uint32_t num = 0;
    FILE *fin;
    int n = 50;
    uint32_t *vector = {0};
    int index = 0;
    if (argc != 3)
    {
        printf("Programul primeste 2 argumente fisierul de intrare si de iesire");
        exit(EXIT_FAILURE);
    }
    if ((fin = fopen(arcgv[1], "rb")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }

    if ((vector = (uint32_t *)malloc(n * sizeof(uint32_t))) == NULL)
    {
        printf("Memorie insuficienta");
        return ENOSPC;
    }
    while (fread(&num, sizeof(uint32_t), 1, fin) == 1)
    {
        vector[index] = num;
        index++;
        if (index == n)
        {
            n = index + CHUNK;
            if ((vector = realloc(vector, n * sizeof(uint32_t))) == NULL)
            {
                printf("Memorie insuficienta");
                return ENOSPC;
            }
        }
    }
    BubbleSort(vector, index);
    scriere(vector, index, arcgv[2]);
    fclose(fin);
    return 0;
}