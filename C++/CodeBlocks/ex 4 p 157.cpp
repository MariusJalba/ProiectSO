#include<iostream>
using namespace std;
int main()
{
    int z,p,i;
    char c;
    z=0;
    p=0;
    i=0;
    do
    {
        cout<<"c=";cin>>c;
        if (c>='0' && c<='9') z++;
        if (c=='0' || c=='2' || c=='4' || c=='6' || c=='8') p++;
        if (c=='1' || c=='3' || c=='5' || c=='7' || c=='9') i++;
    }
    while(c!='*');
    cout<<"z="<<z<<endl;
    cout<<"p="<<p<<endl;
    cout<<"i="<<i<<endl;
    return 0;
}
