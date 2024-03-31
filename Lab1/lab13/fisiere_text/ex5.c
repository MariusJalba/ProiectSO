#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int arg, char **argv)
{
    FILE *fin;
    FILE *fout;
    char c = '\0';
    float litere[26] = {0};
    float n_litere = 0;
    int contor=97;
    float procent=0;
    if (arg!=2)
    {
        printf("Nu ati introdus destule argumente");
        exit(EXIT_FAILURE); 
    }
    if ((fin = fopen(argv[1], "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(1);
    }
    if ((fout = fopen("histo.txt", "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(1);
    }
    while ((c = fgetc(fin)) != EOF)
    {
        if (isalpha(c))
        {
            n_litere++;
        }
    }
    fseek(fin, 0, SEEK_SET);
    for(int i=0;i<26;i++)
    {
        litere[i]=0;
    }
    for (int i = 0; i < 26; i++)
    {
        while ((c = fgetc(fin)) != EOF)
        {
            c = tolower(c);
            if(c==contor)
            {
                litere[i]++;
            }
        }
        contor++;
        fseek(fin, 0, SEEK_SET);
    }
    contor=97;
    for(int i=0;i<26;i++)
    {
        procent=(litere[i]*100)/n_litere;
        fprintf(fout,"%c",contor);
        fputc('-',fout);
        fprintf(fout,"%g%%",procent);
        fputc('\n',fout);
        contor++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}