#include <stdio.h>
#include<errno.h>
#define MAX 100
void BubbleSort(int *v, int n)
{
    int s, i, aux;
    do
    {
        s = 0; // setam faptul ca nu au avut loc schimbari la iterarea curenta
        for (i = 1; i < n; i++)
        {
            // @1 - pornim de la 1 ca sa formam perechi (v[i-1],v[i])
            if (v[i - 1] > v[i])
            {
                // daca valorile NU respecta relatia de ordine
                aux = v[i - 1]; // interschimba valorile
                v[i - 1] = v[i];
                v[i] = aux;
                s = 1; // @2 - seteaza faptul ca a avut loc cel putin o schimbare
            }
        }
    } while (s); // daca s adevarat (!=0), atunci repeta iterarea
}
int main()
{
    FILE *fout;
    int numere[MAX] = {0};
    int n_valori = 0;
    printf("Introduceti numarul de valori:");
    scanf("%d", &n_valori);
    for (int i = 0; i < n_valori; i++)
    {
        scanf("%d", &numere[i]);
    }
    BubbleSort(numere, n_valori);
    if ((fout = fopen("out.txt", "w")) == NULL)
    {
        printf("Error");
    }
    fputc('|',fout);
    for(int i=0; i<n_valori;i++)
    {
        fprintf(fout,"%d",numere[i]);
        fputc('|',fout);
    }
    fclose(fout);
    return 0;
}