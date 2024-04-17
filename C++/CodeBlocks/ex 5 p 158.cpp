#include<iostream>
using namespace std;
int main()
{
    float x,y;
    do
    {
       cout<<"x=";cin>>x;
       y=1/x;
       cout<<"y="<<y<<endl;
    }
    while(x!=0);
    return 0;
}
