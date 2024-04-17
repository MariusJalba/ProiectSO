#include<iostream>
using namespace std;
int main()
{
    int i,x;
    i=0;
    cout<<"x=";cin>>x;
    if (x%2==0) goto r1;
    goto r2;
    r1: cout<<"este nr.par"<<endl;
    r2: cout<<"nu este nr.par"<<endl;
    return 0;
}
