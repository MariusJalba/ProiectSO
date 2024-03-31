#include<stdio.h>
int main(int arcg, char **arcgv)
{
    if(arcg != 5)
    {
        printf("Numar incorect de argumente");
    }
    printf("Argument 1:%s\n",arcgv[1]);
    printf("Argument 2:%s\n",arcgv[2]);
    printf("Argument 3:%s\n",arcgv[3]);
    printf("Argument 4:%s\n",arcgv[4]);
    return 0;
}