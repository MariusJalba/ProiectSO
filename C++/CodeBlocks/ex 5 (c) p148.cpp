#include<iostream>
using namespace std;
int main()
{
    int z,x,i;
    for(i=1; i<=4; i++)
    {
        for (x=i; x<=i; x++)
        {
            for (z=1;z<=i; z++)
            {
                cout<<x;
            }
        }
        cout<<endl;
    }
    return 0;
}
