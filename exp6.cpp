#include <iostream>
using namespace std;

class Shape{
private:
     int s, l, b;
     float r, bs, ht;


public:
// Area of square
int area(int s)
{
    return s * s;
}

// Area of rectangle
int area(int l, int b)
{
    return l * b;
}

// Area of circle
float area(float r)
{
    return 3.14f * r * r;
}

// Area of triangle
float area(float bs, float ht)
{
    return (bs * ht) / 2;
}      
};     

int main()
{

    Shape s;

    cout << "\nArea of square is " << s.area(4);
    cout << "\nArea of rectangle is " << s.area(5,6);
    cout << "\nArea of circle is " << s.area(3.4f);
    cout << "\nArea of triangle is " << s.area(8.0f,5.0f);

    return 0;
}

