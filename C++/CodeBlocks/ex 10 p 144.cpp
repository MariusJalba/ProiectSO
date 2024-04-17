#include<iostream>
using namespace std;
int main()
{
    int i,p,n;
    float m;
    m=0;
    cout<<"n=";cin>>n;
    cout<<"p=";cin>>p;
    cout<<"m=";cin>>m;
    for(i=1;i<=n;i++)
    {
        m=m+(m*p)/100;
    }
    cout<<"m="<<m<<endl;
    return 0;

}
