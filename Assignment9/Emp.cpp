#include <iostream>
using namespace std;

// Base class
class Employee
{
public:
    virtual void calculateBonus()
    {
        cout << "Employee bonus" << endl;
    }
};

// Derived class Manager
class Manager : public Employee
{
public:
    void calculateBonus() override
    {
        cout << "Manager Bonus = 20% of salary" << endl;
    }
};

// Derived class Developer
class Developer : public Employee
{
public:
    void calculateBonus() override
    {
        cout << "Developer Bonus = 10% of salary" << endl;
    }
};

int main()
{
    Employee *e;

    Manager m;
    Developer d;

    // Runtime polymorphism
    e = &m;
    e->calculateBonus();

    e = &d;
    e->calculateBonus();

    return 0;
}