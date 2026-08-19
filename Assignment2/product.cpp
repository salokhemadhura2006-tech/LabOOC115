#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string pname;
    int pid;
    int price;

public:
    void getdata()
    {
        cout << "\nEnter product name: ";
        cin >> pname;

        cout << "Enter product id: ";
        cin >> pid;

        cout << "Enter product price: ";
        cin >> price;
    }

    void display()
    {
        cout << "\n---- Product Details ----" << endl;
        cout << "Product Name: " << pname << endl;
        cout << "Product Id: " << pid << endl;
        cout << "Product Price: " << price << endl;
    }
};

int main()
{
    Product p;

    p.getdata();
    p.display();

    return 0;
}