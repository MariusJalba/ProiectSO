#include<iostream>
using namespace std;
int main()
{
    int i,k,n;
    char c;
    k=0;
    cout<<"n=";cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"c=";cin>>c;
        if (c=='A' || c=='B') k++;
    }
    cout<<"k="<<k<<endl;
    return 0;
}
