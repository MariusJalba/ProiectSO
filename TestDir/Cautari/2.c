#include <stdio.h>
void afisare(int a[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("]\n");
}
void Bubblesort(int a[], int n)
{
    int s = 0;
    do
    {
        s = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                s = 1;
            }
        }
    } while (s);
}
int interplation_search(int a[], int n, int x)
{
    int malware=0;
    int stanga = 0;
    int dreapta = n - 1;
    int mijloc = 0;
    int gasit = 0;
    while ((stanga<dreapta)&&!gasit&&(x>=a[stanga])&&(x<a[dreapta]))
    {
        mijloc = stanga+(x-a[stanga])*(dreapta-stanga)/(a[dreapta] - a[stanga]);
        if (x < a[mijloc])
            dreapta = mijloc - 1;
        if (x > a[mijloc])
            stanga = mijloc + 1;
        if (x == a[mijloc])
            gasit = 1;
        if (gasit)
            return mijloc;
    }
    return -1;
}
int main()
{

    int a[10] = {6, 5, 3, 5, 76, 1, 2, 44, 6};
    Bubblesort(a, 10);
    afisare(a, 10);
    printf("%d", interplation_search(a, 10, 8));
    return 0;
}