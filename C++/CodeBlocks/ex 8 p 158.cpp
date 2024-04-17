#include<iostream>
using namespace std;
int main()
{
    int k,mic,mare;
    char c;
    mic=0;
    mare=0;
    do
    {
        cout<<"c=";cin>>c;
        if (c>='A' && c<='Z') mare++;
        if (c>='a' && c<='z') mic++;
    }
    while (c!='*');
    k=mare+mic;
    cout<<"Litere="<<k<<endl;
    cout<<"mici="<<mic<<endl;
    cout<<"mari="<<mare<<endl;
    return 0;
}
