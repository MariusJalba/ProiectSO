#include<stdio.h>
int recursiv(int A[],int n,int sp, int si)
{
    if(n < 0)
    {
        return si-sp;
    }
    else
    {
        if(A[n] % 2 == 0)
        {
            sp+=A[n];
        }
        else
        {
            si+=A[n];
        }
        recursiv(A,n-1,sp,si);
    }
}
int main()
{
    int A[6] ={4,5,6,3,2,9};
    int n=5;
    printf("%d",recursiv(A,n,0,0));
    return 0;
}