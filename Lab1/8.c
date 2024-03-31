#include<stdio.h>
#include<stdlib.h>
int main(int arcg, char **arcgv)
{
    if(arcg != 4)
    {
        printf("Numar incorect de argumente");
    }
    int x = atoi(arcgv[1]);
    int y = atoi(arcgv[2]);
    int z = atoi(arcgv[3]);
    printf("%d\n",x+y+z);
    return 0;
}