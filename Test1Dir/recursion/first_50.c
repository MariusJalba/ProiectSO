#include<stdio.h>
void print(int k, int n)
{
    if(k<=n)
    {
        printf("%d ",k);
        print(k+1,n);
    }

}
int main()
{
    int n=0;
    printf("n:");
    scanf("%d",&n);
    print(0,n);
    return 0;
}