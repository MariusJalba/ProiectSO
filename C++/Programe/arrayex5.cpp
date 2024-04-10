#include<iostream>
using namespace std;
int second_smallest(int x[], int i,int s) 
{
  int min; int second_min;
  if(x[0]<x[1]) 
  {min=x[0];
  second_min=x[1];
  }
  else
  {
  min=x[1];
  second_min=x[0];
  }
  for (i=1; i<=s; i++)
  {
    if(min>x[i])
    {
      second_min=min;
      min=x[i];
    }
    else if(min<x[i] && x[i]<second_min)
    {
      second_min=x[i];
    }
  }
   return second_min;
}
int main()
{
  int x[]={};
  int s;
  int i;
  cout<<"s=";
  cin>>s;
  for (i=1; i <=s; i++)
  {
    cout<<"x."<<i<<"=";
    cin>>x[i];
  }
  int second_min=second_smallest(x,i,s);
  cout<<second_min;
    return 0;
}