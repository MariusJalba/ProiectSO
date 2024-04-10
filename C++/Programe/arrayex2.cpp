#include<iostream>
#include<climits>
using namespace std;
void trei_mari(int x[],int size)
{
    int i,first,second,third;
    first=second=third=INT_MIN;
    for(i=1; i<=size; i++)
    {
        if(x[i]>first)
        {
        third=second;
        second=first;
        first=x[i];
        }
        else 
        if(x[i]>second)
        {
        third=second;
        second=x[i];
        }
        else if(x[i]>third)
        {
            third=x[i];
        }
    }
    cout<<"1="<<first<<endl<<"2="<<second<<endl<<"3="<<third<<endl;
}
int main()
{
int x[]={};
int i;
int size;
cout<<"size=";cin>>size;
for (i=1; i<=size; i++)
{
    cout<<"x."<<i<<"="<<endl;
    cin>>x[i];
}
trei_mari(x,size);
return 0;
}
