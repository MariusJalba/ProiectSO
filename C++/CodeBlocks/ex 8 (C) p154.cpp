#include<iostream>
using namespace std;
int main()
{
    int s,n;
    cout<<"n=";cin>>n;
    s=0;
    while (n)
    {
        s=s+n%10;
        n=n/10;
    }
    cout<<"s="<<s<<endl;
    return 0;
}
