#include <stdio.h>
#include <stdlib.h>
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
void ShakerSort(int a[], int n)
{
    int s = 0;
    do
    {
        s = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    s = 1;
                }
            }
            for (int j = n - i - 2; j >= 0; j--)
            {
                if (a[j] < a[j - 1])
                {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    s = 1;
                }
            }
        }
    } while (s);
}
int binary_search(int a[], int n, int x)
{
    int stanga = 0;
    int dreapta = n - 1;
    int mijloc = 0;
    int gasit = 0;
    while ((stanga < dreapta) && (!gasit))
    {
        int mijloc = (dreapta + stanga) / 2;
        if (x < a[mijloc])
            dreapta = mijloc - 1;
        if (x > a[mijloc])
            stanga = mijloc + 1;
        if (x == a[mijloc])
            gasit = 1;
        if (gasit)
        {
            return mijloc;
        }
    }
    return -1;
}
int main()
{
    int a[10] = {6, 5, 3, 5, 76, 1, 2, 44, 6};
    ShakerSort(a, 10);
    afisare(a, 10);
    printf("%d", binary_search(a, 10, 8));
    return 0;
}