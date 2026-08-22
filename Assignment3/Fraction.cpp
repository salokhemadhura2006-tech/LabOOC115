#include <iostream>
using namespace std;

class Fraction
{
    int num, den;

public:
    // Constructor
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }

    // Addition
    void add(Fraction f)
    {
        int n = (num * f.den) + (f.num * den);
        int d = den * f.den;

        cout << "Addition = " << n << "/" << d << endl;
    }

    // Subtraction
    void subtract(Fraction f)
    {
        int n = (num * f.den) - (f.num * den);
        int d = den * f.den;

        cout << "Subtraction = " << n << "/" << d << endl;
    }
};

int main()
{
    Fraction f1(-1, 2);
    Fraction f2(1, -3);

    f1.add(f2);
    f1.subtract(f2);

    return 0;
}
