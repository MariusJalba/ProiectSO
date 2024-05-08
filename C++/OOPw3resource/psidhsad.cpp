#include <iostream>
using namespace std;
class rectg
{
private:
    float length;
    float width;

public:
    rectg(float l, float w) : length(l), width(w){};
    float area()
    {
        return (length * width);
    }
    float perimeter()
    {
        return (2 * length + 2 * width);
    }
};
int main()
{
    float length = 0;
    float width = 0;
    cout << "Length:";
    cin >> length;
    cout << "Width:";
    cin >> width;
    rectg rectangle(length, width);
    float area = rectangle.area();
    float perimeter = rectangle.perimeter();
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
    return 0;
}