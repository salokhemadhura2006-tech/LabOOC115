#include <iostream>
using namespace std;

class Time
{
    int h, m, s;

public:

    // Constructor
    Time(int hours = 0, int minutes = 0, int seconds = 0)
    {
        h = hours;
        m = minutes;
        s = seconds;
    }

    // Addition
    Time add(Time t)
    {
        Time result;

        result.s = s + t.s;
        result.m = m + t.m;
        result.h = h + t.h;

        if (result.s >= 60)
        {
            result.s = result.s - 60;
            result.m++;
        }

        if (result.m >= 60)
        {
            result.m = result.m - 60;
            result.h++;
        }

        return result;
    }

    // Subtraction
    Time subtract(Time t)
    {
        Time result;

        result.s = s - t.s;
        result.m = m - t.m;
        result.h = h - t.h;

        if (result.s < 0)
        {
            result.s = result.s + 60;
            result.m--;
        }

        if (result.m < 0)
        {
            result.m = result.m + 60;
            result.h--;
        }

        return result;
    }

    void display()
    {
        cout << h << " hours "
             << m << " minutes "
             << s << " seconds" << endl;
    }
};

int main()
{
    Time t1(5, 45, 30);
    Time t2(2, 30, 45);

    Time addition = t1.add(t2);
    Time subtraction = t1.subtract(t2);

    cout << "Addition = ";
    addition.display();

    cout << "Subtraction = ";
    subtraction.display();

    return 0;
}