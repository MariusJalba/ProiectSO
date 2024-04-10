#include<iostream>
using namespace std;
int nr[5] ={0};
int main()
{
    int max=nr[0];
    int i;
    for (i=0; i<=5; i++)
    {
        cout<<"nr"<<i<<"="<<endl;
        cin>>nr[i];
    }
    for (i=0; i<=5; i++)
    {
        if(nr[i] > max) max=nr[i];
    }
    cout<<"max="<<max<<endl;
    return 0;
}