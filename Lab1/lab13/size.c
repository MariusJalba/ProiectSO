#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fin;
    int size=0;
    if((fin=fopen("movies.txt","r"))==NULL)
    {
        printf("eroare la deschidere fisier");
        exit(EXIT_FAILURE);
    }
    fseek(fin,0,SEEK_END);
    size=ftell(fin);
    printf("size:%d",size);
    fclose(fin);
    return 0;
}