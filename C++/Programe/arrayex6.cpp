#include<iostream>
using namespace std;
void two_greater_numbers(int x[],int s)
{
    int j;
    int i;
   for(i=1; i <= s; i++)
   {
    int c=0;
    for(j=1; j<=s; j++)
    if (x[j]>x[i])
        c++;
        if(c >=2)
        cout<<x[i]<<" ";
}
}
int main()
{
    int x[]={};
    int i;
    int s=0;
    cout<<"s=",
    cin>>s;
    for (i=1; i <= s; i++)
    {
        cout<<"x."<<i<<"=";
        cin>>x[i];
    }
    two_greater_numbers(x,s);
    return 0;
}