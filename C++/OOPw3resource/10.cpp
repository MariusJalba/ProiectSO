#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.14;
class Shape
{
public:
    virtual void calculate() const = 0;
};
class Circle : public Shape
{
private:
    int radius;

public:
    Circle(const int &r) : radius(r){};
    void calculate() const
    {
        float area = pi * pow(radius, 2);
        float per = 2 * pi * radius;
        cout << "Circle area:" << area << endl;
        cout << "Circle circumference:" << per << endl;
    }
};
class Rectangle : public Shape
{
private:
    int length, width;

public:
    Rectangle(const int &l, const int &w) : length(l), width(w){};
    void calculate() const
    {
        int area = length * width;
        int per = 2 * length + 2 * width;
        cout << "Rectangle area:" << area << endl;
        cout << "Rectangle perimeter:" << per << endl;
    }
};
class Triangle : public Shape
{
private:
    int a, b, c;

public:
    Triangle(const int &a, const int &b, const int &c) : a(a), b(b), c(c){};
    void calculate() const
    {
        int per = a + b + c;
        float s = per / 2.0;
        int area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Triangle area:" << area << endl;
        cout << "Triangle perimeter:" << per << endl;
    };
};
int main()
{
    Circle cerc(5);
    Shape *figura = &cerc;
    figura->calculate();
    Rectangle rect(4, 7);
    figura = &rect;
    figura->calculate();
    Triangle tri(3, 5, 4);
    figura = &tri;
    figura->calculate();
    return 0;
}