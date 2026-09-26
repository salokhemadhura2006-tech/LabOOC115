#include <iostream>
using namespace std;

class Matrix
{
    int a[2][2];

public:
    void input()
    {
        cout << "Enter 2x2 matrix elements:\n";
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void display()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload + operator
    Matrix operator+(Matrix m)
    {
        Matrix temp;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    // Overload - operator
    Matrix operator-(Matrix m)
    {
        Matrix temp;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }

    // Overload == operator
    bool operator==(Matrix m)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                if(a[i][j] != m.a[i][j])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Matrix A, B, C;

    cout << "Enter Matrix A:\n";
    A.input();

    cout << "\nEnter Matrix B:\n";
    B.input();

    C = A + B;

    cout << "\nMatrix Addition (A + B):\n";
    C.display();

    C = A - B;

    cout << "\nMatrix Subtraction (A - B):\n";
    C.display();

    if(A == B)
        cout << "\nMatrices are Equal.";
    else
        cout << "\nMatrices are Not Equal.";

    return 0;
}