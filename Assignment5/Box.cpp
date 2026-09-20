#include <iostream>
using namespace std;

class Box
{
    float length, width, height;

public:
    // Default constructor
    Box()
    {
        length = 3;
        width = 2;
        height = 5;
    }

    // Parameterized constructor
    Box(float l, float w, float h)
    {
        length = l;
        width = w;
        height = h;
    }

    // Copy constructor
    Box(const Box &b)
    {
        length = b.length;
        width = b.width;
        height = b.height;
    }

    // Calculate volume
    float volume()
    {
        return length * width * height;
    }

    // Display object information
    void display()
    {
        cout << "Length : " << length << endl;
        cout << "Width  : " << width << endl;
        cout << "Height : " << height << endl;
        cout << "Volume : " << volume() << endl;
    }

    // Destructor
    ~Box()
    {
        cout << "Destructor called. Box object destroyed." << endl;
    }
};

int main()
{
    // Default constructor
    Box box1;

    cout << "--- Box 1 (Default Constructor) ---" << endl;
    box1.display();

    // Parameterized constructor
    Box box2(10, 5, 4);

    cout << "\n--- Box 2 (Parameterized Constructor) ---" << endl;
    box2.display();

    // Copy constructor
    Box box3(box2);

    cout << "\n--- Box 3 (Copy Constructor) ---" << endl;
    box3.display();

    return 0;
}