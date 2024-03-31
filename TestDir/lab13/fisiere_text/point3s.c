#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    int b;
    int c;
} points;
void add_puncte(points **v, int *n)
{
    FILE *fin;
    int c = 60;
    int i = 0;
    if ((*v = malloc(c * sizeof(points))) == NULL)
    {
        printf("Nu exista spatiu");
        exit(EXIT_FAILURE);
    }
    if ((fin = fopen("points3.txt", "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }
    points punct1;
    while (fscanf(fin, "%d.%d.%d", &punct1.a, &punct1.b, &punct1.c) == 3)
    {
        (*v)[i] = punct1;
        i++;
        if (i == c)
        {
            c = c+60;
            if ((*v = realloc(*v, c * sizeof(points))) == NULL)
            {
                printf("Nu exista spatiu");
                exit(EXIT_FAILURE);
            }
        }
    }
    *n = i;
    fclose(fin);
}
void out(points **v, int *n)
{
    FILE *fout;
    int p = 0;
    if ((fout = fopen("out.txt", "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < *n; i++)
    {
        if ((*v)[i].a + (*v)[i].b > (*v)[i].c &&
            (*v)[i].a + (*v)[i].c > (*v)[i].b &&
            (*v)[i].b + (*v)[i].c > (*v)[i].a)
        {
            p = (*v)[i].a + (*v)[i].b + (*v)[i].c;
            fprintf(fout, "(%d, %d, %d)=(%d)", (*v)[i].a, (*v)[i].b, (*v)[i].c, p);
            fputc('\n', fout);
        }
        else
        {
            fprintf(fout, "(%d, %d, %d)=NU ESTE TRIUNGHI", (*v)[i].a, (*v)[i].b, (*v)[i].c);
            fputc('\n', fout);
        }
    }
    fclose(fout);
}
int main()
{
    points *v = 0;
    int n_puncte = 0;
    add_puncte(&v, &n_puncte);
    out(&v, &n_puncte);
    free(v);
    return 0;
}