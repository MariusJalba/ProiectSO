#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX 120
#define CHUNK
typedef struct
{
    unsigned year;
    unsigned int budget;
    char title[200];
} filme;
filme *Filme;
int nfilme = 0;
FILE *fin;
FILE *fout1;
FILE *fout2;
FILE *fout3;
void eliberare()
{
    /*for (int i = 0; i < nlinii; i++)
    {
        free(linii[i]);
    }*/
    free(Filme);
    fclose(fin);
    fclose(fout1);
    fclose(fout2);
    fclose(fout3);
}
void adauga(char *linie)
{
    if ((Filme = (filme *)realloc(Filme, (nfilme + 1) * sizeof(filme))) == NULL)
    {
        printf("memorie insuficienta");
        free(linie);
        eliberare();
        exit(EXIT_FAILURE);
    }
    Filme[nfilme].year = atoi(strtok(linie, ","));
    strtok(NULL, ",");
    strcpy(Filme[nfilme].title, strtok(NULL, ","));
    strtok(NULL, ",");
    strtok(NULL, ",");
    strtok(NULL, ",");
    Filme[nfilme].budget = atoi(strtok(NULL, ","));
    nfilme++;
}
int comparator(const void *p, const void *q)
{
    return strcmp(((filme *)p)->title,
                  ((filme *)q)->title);
}
int comparare(const void *a, const void *b)
{
    const filme *film1 = (filme *)a;
    const filme *film2 = (filme *)b;
    if (film1->year > film2->year)
    {
        return 1;
    }
    else
    {
        if (film1->year < film2->year)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
int comparare1(const void *a, const void *b)
{
    const filme *film1 = (filme *)a;
    const filme *film2 = (filme *)b;
    if (film1->budget > film2->budget)
    {
        return 1;
    }
    else
    {
        if (film1->budget < film2->budget)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    char linie[1000];
    if ((fin = fopen("movies.txt", "r")) == NULL)
    {
        printf("eroare la deschidere");
        return EXIT_FAILURE;
    }
    fgets(linie, 1000, fin);
    while ((fgets(linie, 1000, fin)) != NULL)
    {
        if (strlen(linie) <= 1)
            continue;
        adauga(linie);
    }
    if ((fout1 = fopen("out1.txt", "w")) == NULL)
    {
        printf("eroare la deschidere");
        return EXIT_FAILURE;
    }
    if ((fout2 = fopen("out2.txt", "w")) == NULL)
    {
        printf("eroare la deschidere");
        return EXIT_FAILURE;
    }
    if ((fout3 = fopen("out3.txt", "w")) == NULL)
    {
        printf("eroare la deschidere");
        return EXIT_FAILURE;
    }
    qsort(Filme, nfilme, sizeof(*Filme), comparator);
    for (int i = 0; i < nfilme; i++)
    {
        fprintf(fout2, "%s", Filme[i].title);
        fputc('\n', fout2);
        fprintf(fout2, "%u", Filme[i].budget);
        fputc(' ', fout2);
        fprintf(fout2, "%u", Filme[i].year);
        fputc(' ', fout2);
    }
    qsort(Filme, nfilme, sizeof(*Filme), comparare);
    for (int i = 0; i < nfilme; i++)
    {
        fprintf(fout1, "%s", Filme[i].title);
        fputc('\n', fout1);
        fprintf(fout1, "%u", Filme[i].budget);
        fputc(' ', fout1);
        fprintf(fout1, "%u", Filme[i].year);
        fputc(' ', fout1);
    }
    qsort(Filme, nfilme, sizeof(*Filme), comparare1);
    for (int i = 0; i < nfilme; i++)
    {
        fprintf(fout3, "%s", Filme[i].title);
        fputc('\n', fout3);
        fprintf(fout3, "%u", Filme[i].budget);
        fputc(' ', fout3);
        fprintf(fout3, "%u", Filme[i].year);
        fputc(' ', fout3);
    }
    eliberare();
    return 0;
}