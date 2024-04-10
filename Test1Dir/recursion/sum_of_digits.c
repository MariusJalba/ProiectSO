#include <stdio.h>
void sum_of_digits(int n, int s)
{
    if (n != 0)
    {
        sum_of_digits(n/10,s+n%10);
    }
    else
    {
        printf("%d",s);
    }
}
int main()
{
    int n = 0;
    printf("n:");
    scanf("%d", &n);
    sum_of_digits(n,0);
    return 0;
}