#include <iostream>
using namespace std;
class triangle
{
private:
    int a, b, c;
public:
    triangle(const int &a,const  int &b, const int &c) : a(a), b(b), c(c){};
    void set_a(int n)
    {
        a=n;
    }
    void set_b(int n)
    {
        b=n;
    }
    void set_c(int n)
    {
        c=n;
    }
    void trig_type()
    {
        if (a != b && b != c && a != c)
        {
            cout << "Scalene" << endl;
        }
        else if (a == b && b == c)
        {
            cout << "Equilateral" << endl;
        }
        else
            cout << "Isosceles" << endl;
    };
};
int main()
{
    triangle t1(10,6,7);
    triangle t2(5,5,5);
    triangle t3(3,2,3);
    t1.trig_type();
    t2.trig_type();
    t3.trig_type();
    return 0;
}