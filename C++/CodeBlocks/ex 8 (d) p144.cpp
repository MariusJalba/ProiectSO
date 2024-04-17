#include<iostream>
using namespace std;
int main()
{
    int s,i,n,x;
    float m;
    s=0;
    cout<<"n=";cin>>n;
    for (i=1;i<=n;i++)
    {
        cout<<"x=";cin>>x;
        s=s+x;
        m=s/n;
    }
    cout<<"m="<<m<<endl;
    return 0;
}
