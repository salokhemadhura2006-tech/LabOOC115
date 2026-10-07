#include <iostream>
using namespace std;

// Abstract class
class Vehicle
{
public:
    // Pure virtual functions
    virtual void start() = 0;
    virtual void stop() = 0;
};

// Derived class Car
class Car : public Vehicle
{
public:
    void start() override
    {
        cout << "Car starts with a key." << endl;
    }

    void stop() override
    {
        cout << "Car stops using brakes." << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle
{
public:
    void start() override
    {
        cout << "Bike starts with a self-start." << endl;
    }

    void stop() override
    {
        cout << "Bike stops using brakes." << endl;
    }
};

int main()
{
    //Vehicle *v;

    Car c;
    Bike b;

    // Runtime polymorphism
    //v = &c;
    c.start();
    c.stop();

    //v = &b;
    b.start();
    b.stop();

    return 0;
}