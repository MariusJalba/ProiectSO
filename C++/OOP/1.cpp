#include <iostream>
#include <string>
using namespace std;
class animal
{
protected:
    string name;
    int age;
    string place_of_origin;

public:
    void set_name(string n)
    {
        name = n;
    }
    void set_age(int a)
    {
        age = a;
    }
    void set_place(string p)
    {
        place_of_origin = p;
    }
};
class Zebra : public animal
{
public:
    void get_place()
    {
        cout << "Place of origin:";
        cout << place_of_origin << endl;
    }
    void get_age()
    {
        cout << "Age:";
        cout << age << endl;
    }
    void get_name()
    {
        cout << "Zebra name:";
        cout << name << endl;
    }
};
class Dolphin : public animal
{
public:
    void get_place()
    {
        cout << "Place of origin:";
        cout << place_of_origin << endl;
    }
    void get_age()
    {
        cout << "Age:";
        cout << age << endl;
    }
    void get_name()
    {
        cout << "Dolphin name:";
        cout << name << endl;
    }
};
int main()
{
    Zebra zeb;
    Dolphin dol;
    string n1="ciucea";
    string n2="vasea";
    zeb.set_name(n1);
    zeb.set_age(6);
    zeb.set_place("Africa");
    dol.set_name(n1);
    dol.set_age(10);
    dol.set_place("Pacific");
    dol.get_name();
    dol.get_age();
    dol.get_place();
    zeb.get_name();
    zeb.get_age();
    zeb.get_place();
    return 0;
}