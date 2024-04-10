#include <stdio.h>
void suma(int s, int n)
{
    if (n > 0)
    {
        s = s + n;
        suma(s, n - 1);
    }
    else
    {
        printf("suma: %d", s);
    }
}
int main()
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);
    suma(0, n);
    return 0;
}