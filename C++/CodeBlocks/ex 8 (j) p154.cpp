#include<iostream>
using namespace std;
int main()
{
    int a,z,m,n;
    cout<<"n=";cin>>n;
    m=0;
    z=0;
    a=n;
    while(n>0)
    {
        z=(n%10)*10;
        n=n/10;
        m=m*10;
        m=m+z;
    }
    if (n==0) m=m/10;
    if (a==m) cout<<"Nr.este palindrom"; else cout<<"Nr.nu este palindrom";
    return 0;
}
