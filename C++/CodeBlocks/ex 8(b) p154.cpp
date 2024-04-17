#include<iostream>
using namespace std;
int main()
{
    int z,pc,n;
    cout<<"n=";cin>>n;
    z=1;
    while ((n/z)!=0)
    {
        pc=n/z;
        z=z*10;
    }
    cout<<"pc="<<pc<<endl;
    return 0;
}
