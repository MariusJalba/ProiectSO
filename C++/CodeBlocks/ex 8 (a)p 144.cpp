#include<iostream>
using namespace std;
int main()
{
    int i,n,x;
    cout<<"n=";cin>>n;
    for (i=1;i<=n;i++)
    {
        cout<<"x=";cin>>x;
        if (x%2==0) cout<<"nr.este par"<<endl;
        else cout<<"nr. este impar"<<endl;
    }
    return 0;
}
