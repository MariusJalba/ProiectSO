#include <iostream>
#include<string>
using namespace std;
class car
{
    private:
    string company, model;
    int year;
    public:
    car(const string &c, const string &m,const int &y):company(c),model(m),year(y){};
    void set_company(string c)
    {
        company=c;
    };
    void set_model(string m)
    {
        model=m;
    };
    void set_year(int y)
    {
        year=y;
    };
    string get_company()
    {
        return company;
    }
    string get_model()
    {
        return model;
    }
    int get_year()
    {
        return year;
    }
};
int main()
{
    car masina("Ford","Mustang",2023);
    cout<<"Company:"<<masina.get_company()<<endl;
    cout<<"Model:"<<masina.get_model()<<endl;
    cout<<"Year:"<<masina.get_year()<<endl;
    return 0;
}