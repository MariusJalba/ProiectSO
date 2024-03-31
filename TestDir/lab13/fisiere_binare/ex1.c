#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main(int argc,char ** arcgv)
{
    FILE *fin;
    FILE *fout;
    uint32_t n=0;
    if(argc!=3)
    {
        printf("Introduceti 2 argumente <fisierul de intrare> <fisierul de iesire>");
        exit(EXIT_FAILURE);
    }
    if((fin=fopen(arcgv[1],"rb"))==NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }
    if((fout=fopen(arcgv[2],"wb"))==NULL)
    {
        printf("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }
    while(fread(&n,sizeof(uint32_t),1,fin)==1)
    {
        fprintf(fout,"%08x\n",n);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}