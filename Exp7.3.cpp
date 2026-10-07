#include <iostream>
using namespace std;

// Base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// First subclass
class Car : private Vehicle
{
public:
    Car()
    {
        cout << "This Vehicle is Car" << endl;
    }
};

// Second subclass
class Bus : public Vehicle
{
public:
    Bus()
    {
        cout << "This Vehicle is Bus" << endl;
    }
};

// Main function
int main()
{
    // Creating object of subclass will
    // invoke the constructor of base class.
    Car obj1;
    Bus obj2;

    return 0;
}