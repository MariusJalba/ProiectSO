#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int sp,np,x,ni,si;
    float mp,mi;
    np=0;
    sp=0;
    mp=0;
    ni=0;
    si=0;
    mi=0;
    while(x!=0)
    {
        cout<<"x=";cin>>x;
        if (x%2==0)
        {
            sp=sp+x;
            np=np+1;
        }
        else
        {
            si=si+x;
            ni=ni+1;
        }
    }
    mp=sp;
    mi=si;
    mp=mp/np;
    mi=mi/ni;
    cout<<"mp="<<mp<<endl;
    cout<<"sp="<<sp<<endl;
    cout<<"mi="<<mi<<endl;
    cout<<"si="<<si<<endl;
    return 0;
}
