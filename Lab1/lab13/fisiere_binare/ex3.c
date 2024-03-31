#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main(int arcg,char** arcgv)
{
    //copiere binara dintr-un fisier in altul
    FILE *fin;
    FILE *fout;
    uint8_t n=0;
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
    while(fread(&n,sizeof(uint8_t),1,fin)==1)
    {
        fwrite(&n,sizeof(uint8_t),1,fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}