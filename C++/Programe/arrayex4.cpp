#include<iostream>
#include<algorithm>
using namespace std;
void mari(int x[],int n, int k )
{
    
    sort (x, x+n, greater<int>());
    cout<<"cele mai mari:"<<k<<" elemente:"<<endl;
    for (int i=0; i < k; i++)
    {
      cout<<x[i]<<" ";
    }   
}
int main()
{
    int s=0;
    cout<<"Introduce the size of array"<<endl;
    cin>>s;
    int x[s]={0};
    int k=0;
    int i=0;
   
   for (i=0; i < s; i++)
   {
    cout<<"x."<<i<<"=";
    cin>>x[i];
   }
   int n = sizeof(x)/sizeof(x[0]);
   cout<<"input k"<<endl;
   cin>>k;
   mari(x,n,k);
    return 0;
}