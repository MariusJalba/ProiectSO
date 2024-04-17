#include<iostream>
using namespace std;
int main()
{
    float x,y,r;
    int c;
    cout<<"x=";cin>>x;
    cout<<"y=";cin>>y;
do{
    cout<<"c=";cin>>c;
switch(c)
    {
    case 1:
           {
            r=x+y;
            cout<<"r="<<r<<endl;
            break;
           }
    case 2:
        {
            r=x-y;
            cout<<"r="<<r<<endl;
            break;
        }
    case 3:
        {
            r=x*y;
            cout<<"r="<<r<<endl;
            break;
        }
    case 4:
        {
            r=x/y;
            cout<<"r="<<r<<endl;
            break;
        }
    case 5:
        {
          return 0;
        }
     }
  } while(c>0);
}
