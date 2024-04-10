#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.14;
class Circle
{
private:
    int radius;

public:
    Circle(float r) : radius(r) {}
    float circumference()
    {
        return (2 * pi * radius);
    };
    float area()
    {
        return (pi * pow(radius, 2));
    };
};
int main()
{
    float r = 0;
    cout << "r:";
    cin >> r;
    Circle cerc(r);
    double area=cerc.area();
    double circumference=cerc.circumference();
    cout<<circumference<<" ";
    cout<<area;
    return 0;
}