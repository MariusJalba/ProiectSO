#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **arcgv)
{
    FILE *fin;
    FILE *fout;
    int c = 0;
    char *denumire;
    if (argc != 3)
    {
        printf("Nu sunt destule argumente");
        exit(EXIT_FAILURE);
    }
    if ((fin = fopen(arcgv[1], "rb")) == NULL)
    {
        printf("Eroare la deschidere fisier");
        exit(EXIT_FAILURE);
    }
    if ((strlen(arcgv[1]) + 1) > 800)
    {
        printf("fisierul de intrare are denumire prea lunga");
        exit(EXIT_FAILURE);
    }
    strcpy(denumire, arcgv[2]);
    strcat(arcgv[2], ".bin");
    if ((fout = fopen(arcgv[2], "wb")) == NULL)
    {
        printf("Eroare la deschidere fisier");
        exit(EXIT_FAILURE);
    }
    while ((fwrite(&arcgv[2], sizeof(char), 1, fout)) == 1)
    {
        c++;
    }
    if (c < 800)
    {
        do
        {
            fwrite(0, sizeof(char), 1, fout);
        } while (c <= 800);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}