#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    // Constructor to initialize the object's value
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Overloading (-) operator to perform decrement operation
    void operator-()
    {
        feet--;
        inch--;

        cout << "\nFeet & Inches (Decrement): "
             << feet << "'" << inch;
    }
     void operator+()
    {
        feet+3;
        inch+3;

        cout << "\nFeet & Inches (Decrement): "
             << feet << "'" << inch;
    }
};

int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    int a=10;
    int b=20;
    int c=a+b;
    cout<<"C:"<<c;


    // Use (-) unary operator by single operand
    -d1;
    +d2;
    cout<<"feet",<<feet;
    cout<<"Inch",<<inch;

    return 0;
}