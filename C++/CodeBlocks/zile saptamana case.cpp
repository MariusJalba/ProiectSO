#include<iostream>
using namespace std;
int main()
{
    int x,b;
    cout<<"x="; cin>>x;
    switch(x)
    {
    case 1:
        cout<<"Luni"<<endl;
        break;
    case 2:
        cout<<"Marti"<<endl;
            break;
    case 3:
        cout<<"Miercuri"<<endl;
        break;
    case 4:
        cout<<"Joi"<<endl;
        break;
    case 5:
        cout<<"Vineri"<<endl;
        break;
    case 6:
        cout<<"Sambata"<<endl;
        break;
    case 7:
        cout<<"Duminica"<<endl;
        break;
    default:
        cout<<"Introduce-ti nr. de la 1 la 7"<<endl;
        break;
    }
    if (x<=5 && x>=1) b=8;
    if (x==6 || x==7) b=9;
    switch (b)
    {
        case 8:cout<<"Zi de munca"<<endl; break;
        case 9:cout<<"Zi de odihna"<<endl; break;
    }
    return 0;
}
