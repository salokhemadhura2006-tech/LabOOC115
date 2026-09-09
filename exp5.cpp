#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(1.0), width(1.0) {}

    // Parameterized constructor
    Rectangle(double len, double wid) : length(len), width(wid) {}

    // Destructor
    ~Rectangle()
    {
        cout << "Rectangle object destroyed." << endl;
    }

    // Getter for length
    double getLength() const
    {
        return length;
    }

    // Getter for width
    double getWidth() const
    {
        return width;
    }

    // Setter for length
    void setLength(double len)
    {
        length = len;
    }

    // Setter for width
    void setWidth(double wid)
    {
        width = wid;
    }

    // Calculate area
    double calculateArea() const
    {
        return length * width;
    }

    // Calculate perimeter
    double calculatePerimeter() const
    {
        return 2 * (length + width);
    }
};

int main()
{
    // Create a rectangle with custom values
    Rectangle rect(4.0, 40.0);
    
    // Display properties
    cout << "Rectangle properties:" << endl;
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Area: " << rect.calculateArea() << endl;
    cout << "Perimeter: " << rect.calculatePerimeter() << endl;


    Rectangle r;
    cout << "Rectangle properties:" << endl;
    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    return 0;
}