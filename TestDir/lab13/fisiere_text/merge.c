#include<stdio.h>
#include<stdlib.h>
int main(int arg, char **arcgv)
{
    FILE *fin1;
    FILE *fin2;
    FILE *fout;
    char ch='a';
    if(arg != 3)
    {
        printf("Nu sunt destule argumente");
    }
    if((fin1=fopen(arcgv[1],"r"))==NULL)
    {
        printf("Eroare deschidere fisier 1");
        exit(EXIT_FAILURE);
    }
    if((fout=fopen("out.txt","a"))==NULL)
    {
        printf("Eroare deschidere fisier de iesire");
        exit(EXIT_FAILURE);
    }
    while((ch=fgetc(fin1))!=EOF)
    {
        fprintf(fout,"%c",ch);
    }
    fputc('\n',fout);
    fclose(fin1);
    if((fin2=fopen(arcgv[2],"r"))==NULL)
    {
        printf("Eroare la deschidere fisier 2");
        exit(EXIT_FAILURE);
    }
    while ((ch=fgetc(fin2))!=EOF)
    {
        fputc(ch,fout);
    }
    fclose(fin2);
    fclose(fout);
    return 0;
}