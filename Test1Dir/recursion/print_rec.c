#include<stdio.h>
#include<stdlib.h>
void citire(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void printare(int *a,int i,int n)
{
    if(i<n)
    {
        printf("%d\n",a[i]);
        printare(a,i+1,n);
    }
}
int main()
{
    int *v={0};
    int n=0;
    printf("n:");
    scanf("%d",&n);
    if((v=malloc(n*sizeof(int)))==NULL)
    {
        printf("memorie null");
        exit(EXIT_FAILURE);
    }
    citire(v,n);
    printare(v,0,n);
    return 0;
}