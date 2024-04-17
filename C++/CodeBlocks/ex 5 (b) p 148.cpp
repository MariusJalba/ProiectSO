#include<iostream>
using namespace std;
int main()
{
    int x,i;
    for (i=6; i>=1; i--)
    {
        for(x=1; x<=i; x++)
        {
            cout<<x;
        }
        cout<<endl;
    }
    return 0;
}
