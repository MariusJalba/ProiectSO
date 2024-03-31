#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define CHUNK 120
typedef enum
{
    incarcare_v,
    incarcare_f,
} tip_incarcare_t;
typedef struct
{
    tip_incarcare_t tip_incarcare;
    char tip_afisaj[50];
    int n_programe;
    int nivel_z;
    int capacitate;
    char clasa_eficienta[7];
    char programe[1000];
    char producator[100];
    char model[100];
    int pret_f;
    int pret_v;
    int greutate;
} masina;
void scriere_masina(masina *t)
{
    printf("Producator:%s", t->producator);
    printf("Model:%s", t->model);
    printf("Pretul de la furnizor:%d\n", t->pret_f);
    printf("Pret de vanzare:%d", t->pret_v);
    switch (t->tip_incarcare)
    {
    case incarcare_f:
    {
        printf("\nIncarcare frontala\n");
        printf("Capacitate de incarcare:%d kg\n", t->capacitate);
        printf("Clasa eficienta energetica:%s\n", t->clasa_eficienta);
        printf("Programe:%s\n", t->programe);
        break;
    }
    case incarcare_v:
    {
        printf("\n%d\n",t->tip_incarcare);
        printf("%s\n", t->tip_afisaj);
        printf("%d\n", t->n_programe);
        printf("%d \n", t->nivel_z);
        break;
    }
    }
}
void scriere_masini(masina *t)
{
    FILE *fout;
    if ((fout = fopen("Masini.bin", "ab")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }
    fprintf(fout, "%s\n", t->producator);
    fprintf(fout, "%s\n", t->model);
    fprintf(fout, "%d\n", t->pret_f);
    fprintf(fout, "%d\n", t->pret_v);
    switch (t->tip_incarcare)
    {
    case incarcare_f:
    {
        fprintf(fout, "%d\n",t->tip_incarcare);
        fprintf(fout, "%d\n", t->capacitate);
        fprintf(fout, "%s\n", t->clasa_eficienta);
        fprintf(fout, "%s\n", t->programe);
        break;
    }
    case incarcare_v:
    {
        fprintf(fout, "%ds\n",t->tip_incarcare);
        fprintf(fout, "%s\n", t->tip_afisaj);
        fprintf(fout, "%d\n", t->n_programe);
        fprintf(fout, "%d\n", t->nivel_z);
        break;
    }
        fputc('\n', fout);
    }
    fclose(fout);
}
masina citire(int *n_masini)
{
    FILE *fin;
    int8_t n = 0;
    masina *v = {0};
    if ((fin = fopen("Masini.bin", "rb")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de citire");
        exit(EXIT_FAILURE);
    }
    /*if ((fread(n_masini, sizeof(int), 1, fin)) != 1)
    {
        printf("Nu s-a putut citi");
        EXIT_FAILURE;
    }*/
    if ((v = malloc(sizeof(masina) * *n_masini)) == NULL)
    {
        printf("Memorie insuficienta");
        free(v);
        exit(EXIT_FAILURE);
    }
    if ((fread(v, sizeof(masina), *n_masini, fin)) != 1)
    {
        printf("Nu s-a putut citi din fisierul de intrare");
        free(v);
        exit(EXIT_FAILURE);
    }
    fclose(fin);
    return *v;
}
void adaugare(masina *v, int n_masini)
{
    int m = 0;
    printf("\nAlegeti tipul de incarcare al masinii\n1:frontala\n2:verticala");
    scanf("%d", &m);
    switch (m)
    {
    case 1:
    {
        masina masina1;
        masina1.tip_incarcare = incarcare_f;
        printf("Introduceti producatorul:\n");
        scanf("%99s", masina1.producator);
        printf("Introduceti modelul:\n");
        scanf("%99s", masina1.model);
        printf("Introduceti pretul de la furnizor:\n");
        scanf("%d", &masina1.pret_f);
        printf("Introduceti pretul de vanzare:\n");
        scanf("%d", &masina1.pret_v);
        printf("Introduceti greutatea:\n");
        scanf("%d", &masina1.greutate);
        printf("Introduceti capacitatea:\n");
        scanf("%d", &masina1.capacitate);
        printf("Introduceti clasa de eficienta:\n");
        scanf("%6s", masina1.clasa_eficienta);
        printf("Introduceti programele:\n");
        scanf("%999s", masina1.programe);
        v[n_masini] = masina1;

        break;
    }
    case 2:
    {
        masina masina2;
        masina2.tip_incarcare = incarcare_v;
        printf("Introduceti producatorul:\n");
        scanf("%99s", masina2.producator);
        printf("Introduceti modelul:\n");
        scanf("%99s", masina2.model);
        printf("Introduceti pretul de la furnizor:\n");
        scanf("%d", &masina2.pret_f);
        printf("Introduceti pretul de vanzare:\n");
        scanf("%d", &masina2.pret_v);
        printf("Introduceti greutatea:\n");
        scanf("%d", &masina2.greutate);
        printf("Introduceti tip afisaj:");
        scanf("%49s", masina2.tip_afisaj);
        printf("Introduceti numarul de programe:");
        scanf("%d", &masina2.n_programe);
        printf("Introduceti nivelul de zgomot:");
        scanf("%d", &masina2.nivel_z);
        v[n_masini] = masina2;
        break;
    }
    break;
    }
}
void afisare_tip_masina(masina *t)
{
    switch (t->tip_incarcare)
    {
    case incarcare_f:
    {
        printf("Incarcare frontala|%s|%s|", t->producator, t->model);
    }
    break;
    case incarcare_v:
    {
        printf("Incarcare verticala|%s|%s|", t->producator, t->model);
    }
    }
}
void afisare_tip_masini(masina *v, int n_masini)
{
    printf("Tip incarcare|Producator|Model|\n");
    for (int i = 0; i < n_masini; i++)
    {
        afisare_tip_masina(&v[i]);
    }
}
void cautare_greu(masina *v, int n_elemente, int greutate)
{
    for (int i = 0; i < n_elemente; i++)
    {
        if (v[i].greutate == greutate)
        {
            scriere_masina(&v[i]);
        }
    }
}
int sortare(const void *a, const void *b)
{
    masina *masinaA = (masina *)a;
    masina *masinaB = (masina *)b;
    return strcmp(masinaB->clasa_eficienta, masinaA->clasa_eficienta);
}
void sortare_eficienta(masina *v, int n_elemente)
{
    qsort(v, sizeof(masina), n_elemente, sortare);
}
void afisare_producator(masina *v, int n_elemente, char *producator)
{
    for (int i = 0; i < n_elemente; i++)
    {
        if (strcmp(producator, v[i].producator) == 0)
        {
            if (v[i].tip_incarcare == incarcare_f)
            {
                printf("Incarcare frontala %s %s", v[i].producator, v[i].model);
            }
            if (v[i].tip_incarcare == incarcare_v)
            {
                printf("Incarcare verticala %s %s", v[i].producator, v[i].model);
            }
        }
    }
}
int main()
{
    FILE *fout;
    FILE *fin;
    int o = 1;
    int n_masini = 3;
    masina *vector = {0};
    int num = 50;
    if ((vector = malloc(num * sizeof(masina))) == NULL)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    if (num == n_masini)
    {
        num = n_masini + CHUNK;
        if ((vector = realloc(vector, num * sizeof(masina))) == NULL)
        {
            printf("Memorie insuficienta");
            exit(EXIT_FAILURE);
        }
    }
    while (o)
    {
        printf("\nAlegeti optiunea:");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
        {
            //*vector = citire(&n_masini);
            while (1)
            {
                if ((fin = fopen("Masini.bin", "rb")) == NULL)
                {
                    printf("Eroare la deschiderea fisierului de citire");
                    exit(EXIT_FAILURE);
                }
                fread(&vector, sizeof(masina), 1, fin);
                if (feof(fin))
                {
                    break;
                }
            }
            break;
        }
        case 2:
        {
            adaugare(vector, n_masini);
            scriere_masini(&vector[n_masini]);
            n_masini++;
            break;
        }
        case 3:
        {
            afisare_tip_masini(vector, n_masini);
            break;
        }
        case 4:
        {
            if ((fout = fopen("oferta.txt", "w")) == NULL)
            {
                printf("Eroare la deschiderea fisierului cu oferte");
                exit(EXIT_FAILURE);
            }
            break;
        }
        case 5:
        {
            int greu = 0;
            printf("Introduceti greutatea:");
            scanf("%d", &greu);
            cautare_greu(vector, n_masini, greu);
            break;
        }
        case 6:
        {
            sortare_eficienta(vector, n_masini);
            break;
        }
        case 7:
        {
            char str[50] = "a";
            printf("Introduceti producatorul:");
            scanf("%49s", str);
            afisare_producator(vector, n_masini, str);
            break;
        }
        case 8:
        {
            o = 0;
            break;
        }
        default:
        {
            printf("Nu ati ales o optiune corecta");
            break;
        }
        }
    }
    free(vector);
    return 0;
}