#include<iostream>
using namespace std;
int main()
{
    int s,i,n,x;
    s=0;
    cout<<"n=";cin>>n;
    for (i=1;i<=n;i++)
    {
        cout<<"x=";cin>>x;
        s=s+x;
    }
    cout<<"s="<<s<<endl;
    return 0;
}
