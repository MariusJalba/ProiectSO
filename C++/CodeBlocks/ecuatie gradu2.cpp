#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float a,b,c,d,x1,x2;
    cout<<"a=",cin>>a;
    cout<<"b=",cin>>b;
    cout<<"c=",cin>>c;
    d=pow(b,2)-4*a*c;
    cout<<"d="<<d<<endl;
    if (d>0)   {
                 x1=(-b+sqrt(d)) / (2*a);
                 x2=(-b-sqrt(d)) / (2*a);
                 cout<<"x1="<<x1<<endl;
                 cout<<"x2="<<x2<<endl;
               }
    if (d==0)  {
                 x1=-b/2*a;
                 cout<<"x1="<<x1<<endl;
               }
    if (d<0) cout<<"ecutia nu are raspuns";

    return 0;
}
