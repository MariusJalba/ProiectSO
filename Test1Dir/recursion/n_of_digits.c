#include <stdio.h>
void n_of_digits(int n, int c)
{
    if (n < 10)
    {
        printf("%d", c + 1);
    }
    else
    {
        n_of_digits(n/10,c+1);
    }
}
int main()
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);
    n_of_digits(n,0);
    return 0;
}