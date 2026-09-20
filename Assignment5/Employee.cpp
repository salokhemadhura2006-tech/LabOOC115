#include <iostream>
using namespace std;

class Employee
{
    int employeeID;
    float HRA, DA, basicSalary, grossSalary;
    string employeeName;

public:
    // Constructor
    Employee(int id, string name, float basic, float hra, float da)
    {
        employeeID = id;
        employeeName = name;
        basicSalary = basic;
        HRA = hra;
        DA = da;
    }

    // Calculate Gross Salary
    void calculateGrossSalary()
    {
        grossSalary = basicSalary + HRA + DA;
    }

    // Display Employee Details
    void display()
    {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID   : " << employeeID << endl;
        cout << "Employee Name : " << employeeName << endl;
        cout << "Basic Salary  : " << basicSalary << endl;
        cout << "HRA           : " << HRA << endl;
        cout << "DA            : " << DA << endl;
        cout << "Gross Salary  : " << grossSalary << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "\nDestructor called. Employee object destroyed." << endl;
    }
};

int main()
{
    Employee emp(101, "Madhura", 30000, 5000, 3000);

    emp.calculateGrossSalary();
    emp.display();

    return 0;
}