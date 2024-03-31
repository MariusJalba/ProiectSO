#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#define CHUNK 1000
int myCompare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}
void write_sort(char **lines, char *filepath, int n_elemente)
{
    FILE *fout;
    if ((fout = fopen(filepath, "w")) == NULL)
    {
        printf("Eroare la deschidrea fisierului de iesire");
        exit(EXIT_FAILURE);
    }
    qsort(lines, n_elemente, sizeof(lines), myCompare);
    for (int i = 0; i < n_elemente; i++)
    {
        fprintf(fout, "%s", lines[i]);
    }
    fclose(fout);
}
void write_random(char **lines, char *filepath, int n_elemente)
{
    FILE *fout;
    if ((fout = fopen(filepath, "w")) == NULL)
    {
        printf("eroare la deschiderea fiserului random de iesire");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n_elemente; i++)
    {
        fprintf(fout, "%s", lines[rand() % n_elemente]);
    }
    fclose(fout);
}
uint32_t find_word(char **lines, char *word, int n_elemente)
{
    int n = 0;
    char *token = "a";
    char token2[500] = "b";
    for (int i = 0; i < n_elemente; i++)
    {
        token = strstr(lines[i], word);
        if (token == NULL)
        {
            continue;
        }
        else
        {
            n++;
            strcpy(token2, strtok(lines[i], " "));
            while (token != NULL)
            {
                strcpy(token2, strtok(NULL, " "));
                // printf("%s",token2);
                token = strstr(token2, word);
                if (token != NULL)
                {
                    n++;
                }
            }
        }
    }
    return n;
}
int main(int argc, char **argv)
{
    FILE *fin;
    char **v;
    int n = 1000;
    int index = 0;
    char linie[1000];
    char l = 0;
    int a = 0;
    char word[200] = "a";
    if ((fin = fopen(argv[1], "r")) == NULL)
    {
        printf("Eroare a deschiderea fisierului de intare");
        exit(EXIT_FAILURE);
    }
    if ((v = (char **)malloc(n * sizeof(char *))) == NULL)
    {
        printf("Memorie insuficienta");
        return ENOSPC;
    }
    while (fgets(linie, 1000, fin) != NULL)
    {
        /*if ((v = (char **)realloc(v, ((n++) * sizeof(char *)))) == NULL)
        {
            printf("Memorie insuficienta");
            return ENOSPC;
        }*/
        if ((v[index] = (char *)malloc((strlen(linie) + 1) * sizeof(char))) == NULL)
        {
            printf("Memorie insuficienta");
            return ENOSPC;
        }
        strcpy(v[index], linie);
        l = l + strlen(linie);
        index++;
        if (n <= l)
        {
            n = l + CHUNK;
            if ((v = (char **)realloc(v, n * sizeof(char *))) == NULL)
            {
                printf("Memorie insuficienta");
                return ENOSPC;
            }
        }
    }
    write_sort(v, "/home/marius/c/lab13/out.txt", index);
    write_random(v, "/home/marius/c/lab13/rand.txt", index);
    printf("\nIntroduceti cuvantul pentru a fi gasit\n");
    scanf("%s", word);
    a = find_word(v, word, index);
    printf("Cuvantul %s apare de %d ori:", word, a);
    free(v);
    fclose(fin);
    printf("\n");
    return 0;
}