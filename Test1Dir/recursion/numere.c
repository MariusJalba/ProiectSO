#include <stdio.h>
#define true 1
#define false 0
int type(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void recursivitate(int n, int p, int i)
{
    if (n < 9)
    {
        if (type(n) == 1)
        {
            printf("%d\n", p * 10 + n);
            printf("%d", i);
        }
        else
        {
            printf("%d\n", p);
            printf("%d", i * 10 + n);
        }
        return;
    }
    else
    {
        int c = n % 10;
        if (type(c) == 1)
        {
            p = p * 10 + c;
        }
        else
        {
            i = i * 10 + c;
        }
        recursivitate(n / 10, p, i);
    }
}
int main()
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);
    recursivitate(n, 0, 0);
    return 0;
}