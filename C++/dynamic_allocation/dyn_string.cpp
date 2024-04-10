#include<iostream>
using namespace std;
int main()
{
    string *s=new string;
    cout<<"Enter string:";
    cin>>*s;
    cout<<"Inputed string:"<<*s;
    delete s;
    return 0;
}