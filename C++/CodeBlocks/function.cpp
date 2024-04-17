#include<iostream>
using namespace std;
int addnumbers (int first_number,int second_number){
 int result=first_number+second_number;
 return result;
}
int main()
{
    int age1 {15};
    int age2 {17};
    int sum=addnumbers(age1,age2);
    cout<<"sum="<<sum<<endl;
    return 0;
}