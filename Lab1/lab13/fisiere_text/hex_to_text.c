#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int arg, char **arcgv)
{
    FILE *fin;
    FILE *fout;
    char *s={"a"};
    int i=0;
    int size=0;
    if (arg != 2)
    {
        printf("Nu sunt destule argumente");
    }
    if ((fin = fopen(arcgv[1], "r")) == NULL)
    {
        printf("eroare deschidere fisier intrare");
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen("hexout.txt", "w")) == NULL)
    {
        printf("Eroare deschidere fisier iesire");
        exit(EXIT_FAILURE);
    }
    fseek(fin,0,SEEK_END);
    size=ftell(fin);
    fseek(fin,0,SEEK_SET);
    if((s=malloc(size/2*sizeof(char)))==NULL)
    {
        printf("memorie pizdet");
        exit(EXIT_FAILURE);
    }
    while ((fscanf(fin,"%2hhx",&s[i])) != EOF)
    { 
        i++;
    }
    s[size/2]='\0';
    printf("%s",s);
    free(s);
    return 0;
}