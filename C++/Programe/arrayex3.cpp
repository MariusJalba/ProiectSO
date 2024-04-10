#include<iostream>
using namespace std;
void second_largest(int x[],int size)
{
    int second;
    int first;
    int i;
    first=second=INT_MIN;
    for (i=1; i<=size; i++)
    {
        if (x[i]>first) 
        {
        second=first;
        first=x[i];
        }
        else 
        if (x[i]>second)
        second=x[i];
    }
     cout<<"second="<<second<<endl;
}
int main()
{
    int x[]={};
    int size;
    int i;
    cout<<"size=";cin>>size;
    for (i=1; i<=size; i++)
    {
        cout<<"x."<<i<<"=";
        cin>>x[i];
    }
    second_largest(x,size);
    return 0;
}