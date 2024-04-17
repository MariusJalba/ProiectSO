#include<iostream>
using namespace std;
int main()
{
    int z,m,n;
    cout<<"n=";cin>>n;
    m=0;
    z=0;
    while(n>0)
    {
       z=(n%10)*10;
        n=n/10;
        m=m*10;
        m=m+z;
    }
    if(n==0) m=m/10;
    cout<<"m="<<m<<endl;
    return 0;
}
