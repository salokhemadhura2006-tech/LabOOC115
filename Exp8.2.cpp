#include <iostream>
using namespace std;

class MyClass
{
private:
    int value;   // Private member to store the value

public:
    // Constructor to initialize MyClass objects
    MyClass(int val) : value(val)
    {
    }

    // Overloading the equality operator (==)
    bool operator==(const MyClass& other) const
    {
        return value == other.value;
    }

    // Overloading the inequality operator (!=)
    bool operator!=(const MyClass& other) const
    {
        return !(*this == other);
    }

    // Overloading the less than operator (<)
    bool operator<(const MyClass& other) const
    {
        return value < other.value;
    }

    // Overloading the greater than operator (>)
    bool operator>(const MyClass& other) const
    {
        return value > other.value;
    }

    // Overloading the less than or equal to operator (<=)
    bool operator<=(const MyClass& other) const
    {
        return !(*this > other);
    }

    // Overloading the greater than or equal to operator (>=)
    bool operator>=(const MyClass& other) const
    {
        return !(*this < other);
    }
};

int main()
{
    MyClass obj1(20);
    MyClass obj2(20);

    // Using overloaded equality operator
    if (obj1 == obj2)
    {
        cout << "obj1 is equal to obj2" << endl;
    }
    else
    {
        cout << "obj1 is not equal to obj2" << endl;
    }

    // Using overloaded less than operator
    if (obj1 < obj2)
    {
        cout << "obj1 is less than obj2" << endl;
    }
    else
    {
        cout << "obj1 is not less than obj2" << endl;
    }

    // Using overloaded inequality operator
    if (obj1 != obj2)
    {
        cout << "obj1 is not equal to obj2" << endl;
    }
    else
    {
        cout << "obj1 is equal to obj2" << endl;
    }

    // Using overloaded greater than operator
    if (obj1 > obj2)
    {
        cout << "obj1 is greater than obj2" << endl;
    }
    else
    {
        cout << "obj1 is not greater than obj2" << endl;
    }

    // Using overloaded less than or equal to operator
    if (obj1 <= obj2)
    {
        cout << "obj1 is less than or equal to obj2" << endl;
    }
    else
    {
        cout << "obj1 is not less than or equal to obj2" << endl;
    }

    // Using overloaded greater than or equal to operator
    if (obj1 >= obj2)
    {
        cout << "obj1 is greater than or equal to obj2" << endl;
    }
    else
    {
        cout << "obj1 is not greater than or equal to obj2" << endl;
    }

    return 0;
}