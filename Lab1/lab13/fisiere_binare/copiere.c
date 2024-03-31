#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
char *file_name(char *filepath)
{
    int len=strlen(filepath);
    int f=0;
    for(int i=len-1;i>0;i--)
    {
        if(filepath[i]=='/')
        {
            f=1;
            filepath=filepath+i+1;
            break;
        }
    }
    return filepath;
}
int main(int arcg, char **arcgv)
{
    FILE *fin;
    FILE *fout;
    uint8_t n = 0;
    char *denumire="a";
    if (arcg != 3)
    {
        printf("Trebuie sa introduceti 2 argumente <filepath de intrare> <filepath de iesire>\n"); 
        // filepath de intrare exemplu:/home/marius/c/lab13/movies.txt filepath de iesire:/home/marius/c/movies.txt
        exit(EXIT_FAILURE);
    }
    denumire=file_name(arcgv[1]);
    strcat(arcgv[2],denumire);
    if ((fin = fopen(arcgv[1], "rb")) == NULL)
    {
        printf("Eroare deschidere fisier intrare\n");
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen(arcgv[2], "wb")) == NULL)
    {
        printf("Eroare deschidere fisier iesire\n");
        exit(EXIT_FAILURE);
    }
    while ((fread(&n, sizeof(uint8_t), 1, fin)) == 1)
    {
        if ((fwrite(&n, sizeof(uint8_t), 1, fout)) != 1)
        {
            printf("Eroare la copiere din fisier\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}