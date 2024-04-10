#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    string surname;
    string country;
    int age;

public:
    void set_name(const string n)
    {
        name=n;
    };
    void set_surname(const string s)
    {
        surname=s;
    };
    void set_country(const string c)
    {
        country=c;
    };
    void set_age(const int a)
    {
        age=a;
    };
    string print_name()
    {
        return name;
    };
    string print_surname()
    {
        return surname;
    };
    string print_country()
    {
        return country;
    };
    int print_age()
    {
        return age;
    };
};
int main()
{
    Person om;
    om.set_name("Marius");
    om.set_surname("Jalba");
    om.set_country("Moldova");
    om.set_age(20);
    cout << "Name:" << om.print_name() << endl;
    cout << "Surname:" << om.print_surname() << endl;
    cout << "Country:" << om.print_country() << endl;
    cout << "Age:" << om.print_age() << endl;
    return 0;
}