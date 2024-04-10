#include<iostream>
using namespace std;
void most_occurring(int x[], int s)
{
     int c=0;
     cout<<"most occured number:";
    for ( int i=0; i<s; i++)
    {
        int k=1;
     for(int j=i+1; j<s; j++)
        if(x[i]==x[j]) 
            k++;
        if (k>c) c=k;
    }

    for (int i=0; i<s; i++)
    {
        int k=1;
        for (int j=i+1; j<s; j++)
        if(x[i]==x[j])
        k++;
        if(k==c);
        cout<<x[i]<<endl;
        break;
    }
}
int main()
{
    int x[]={};
    int i;
    int s=0;
    cout<<"s=";
    cin>>s;
    for (i=1; i<=s; i++)
    {
        cout<<"x."<<i<<"=";
        cin>>x[i];
    }
    most_occurring(x,s);
    return 0;
}