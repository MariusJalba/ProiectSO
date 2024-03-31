#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX 120
typedef struct Indemnizatii
{
    char Judet[100];
    int B_platiti;
    int suma_tot;
    int alt_p;
    int populatie;
} Indemnizatii;
int n_indemnizatii = 0;
Indemnizatii *vector;
void adaugare(char *linie)
{
    if ((vector = (Indemnizatii *)realloc(vector, (n_indemnizatii + 1) * sizeof(Indemnizatii))) == NULL)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
        free(linie);
    }
    strcpy(vector[n_indemnizatii].Judet, strtok(linie, ";"));
    vector[n_indemnizatii].populatie = atoi(strtok(NULL, ";"));
    vector[n_indemnizatii].B_platiti = atoi(strtok(NULL, ";"));
    strtok(NULL, ";");
    vector[n_indemnizatii].suma_tot = atoi(strtok(NULL, ";"));
    vector[n_indemnizatii].alt_p = atoi(strtok(NULL, ";"));
    n_indemnizatii++;
}
int comparare_Judet(const void *a, const void *b)
{
    const Indemnizatii *A = (Indemnizatii *)a;
    const Indemnizatii *B = (Indemnizatii *)b;
    return (strcmp(A->Judet, B->Judet));
}
int comparare_Suma_tot(const void *a, const void *b)
{
    const Indemnizatii *A = (Indemnizatii *)a;
    const Indemnizatii *B = (Indemnizatii *)b;
    return (A->suma_tot - B->suma_tot);
}
int maxim_altp(Indemnizatii *v, int n_elemente)
{
    int max = 0;
    int pos = 0;
    for (int i = 0; i < n_elemente; i++)
    {
        if (v->alt_p > max)
        {
            max = v->alt_p;
            pos = i;
        }
    }
    return pos;
}
int maxim_pop(Indemnizatii *v, int n_elemente)
{
    int max = 0;
    int pos = 0;
    for (int i = 0; i < n_elemente; i++)
    {
        if (v->populatie > max)
        {
            max = v->populatie;
            pos = i;
        }
    }
    return pos;
}
int main()
{
    FILE *fin;
    FILE *fout;
    FILE *fout1;
    FILE *fout2;
    char linie[1000] = "a";
    int max1 = 0;
    int max2 = 0;
    /*if (argc != 2)
    {
        printf("Eroare argument");
        exit(1);
    }*/
    if ((fin = fopen("indemnizatie.txt", "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(2);
    }
    if ((fout = fopen("Sortat_Judet.txt", "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de iesire");
        return EXIT_FAILURE;
    }
    if ((fout1 = fopen("Sortat_Plati_tot.txt", "w")) == NULL)
    {
        printf("Eroare la deshiderea fisierului de iesire nr2");
        exit(EXIT_FAILURE);
    }
    if ((fout2 = fopen("rezultat.txt", "w")) == NULL)
    {
        printf("Eroare la deshiderea fisierului de iesire nr2");
        exit(EXIT_FAILURE);
    }
    if ((fgets(linie, 1000, fin)) == NULL)
    {
        perror(NULL);
        exit(3);
    }
    while (fgets(linie, 1000, fin) != NULL)
    {
        adaugare(linie);
    }
    qsort(vector, n_indemnizatii, sizeof(*vector), comparare_Judet);
    for (int i = 0; i < n_indemnizatii; i++)
    {
        fprintf(fout, "%s", vector[i].Judet);
        fputc('-', fout);
        fprintf(fout, "%d", vector[i].B_platiti);
        fputc('-', fout);
        fprintf(fout, "%d", vector[i].suma_tot);
        fputc('-', fout);
        fprintf(fout, "%d", vector[i].alt_p);
        fputc('-', fout);
        fprintf(fout, "%d", vector[i].populatie);
        fputc('\n', fout);
    }
    qsort(vector, n_indemnizatii, sizeof(*vector), comparare_Suma_tot);
    for (int i = 0; i < n_indemnizatii; i++)
    {
        fprintf(fout1, "%s", vector[i].Judet);
        fputc('-', fout1);
        fprintf(fout1, "%d", vector[i].B_platiti);
        fputc('-', fout1);
        fprintf(fout1, "%d", vector[i].suma_tot);
        fputc('-', fout1);
        fprintf(fout1, "%d", vector[i].alt_p);
        fputc('-', fout1);
        fprintf(fout1, "%d", vector[i].populatie);
        fputc('\n', fout1);
    }
    max1 = maxim_altp(vector, n_indemnizatii);
    max2=maxim_pop(vector,n_indemnizatii);
    fprintf(fout2, "%s", vector[max1].Judet);
    fputc('-',fout2);
    fprintf(fout2, "%d", vector[max1].alt_p);
    fputc('\n', fout2);
    fprintf(fout2, "%s", vector[max2].Judet);
    fputc('-',fout2);
    fprintf(fout2, "%d", vector[max2].populatie);
    fclose(fin);
    fclose(fout);
    fclose(fout1);
    fclose(fout2);
    free(vector);
    return 0;
}