#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"a=",cin>>a;
    cout<<"b=",cin>>b;
    cout<<"c=",cin>>c;
 if (c<(b+a) && b<(c+a) && a<(b+a))
    {
    cout<<"triunghiul poate fi construit"<<endl;
    if (c==b || c==a || b==a)           cout<<"isoscel"<<endl;
    if ( c==a && b==a && c==b)          cout<<"echilateral"<<endl;
    if ( !(c==a) && !(b==a) && !(c==b)) cout<<"scalen"<<endl;
    }
return 0;
}
