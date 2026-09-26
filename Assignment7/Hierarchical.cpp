#include <iostream>
using namespace std;

// Base Class
class Employee
{
protected:
    int employeeID;
    string employeeName, department;

public:
    void getEmployeeDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Employee Name: ";
        cin >> employeeName;

        cout << "Enter Department: ";
        cin >> department;
    }

    void displayEmployeeDetails()
    {
        cout << "\nEmployee ID: " << employeeID;
        cout << "\nEmployee Name: " << employeeName;
        cout << "\nDepartment: " << department;
    }
};

// Derived Class 1
class TeachingStaff : public Employee
{
private:
    string subject, qualification;

public:
    void getTeachingDetails()
    {
        getEmployeeDetails();

        cout << "Enter Subject: ";
        cin >> subject;

        cout << "Enter Qualification: ";
        cin >> qualification;
    }

    void displayTeachingDetails()
    {
        displayEmployeeDetails();

        cout << "\nSubject: " << subject;
        cout << "\nQualification: " << qualification;
    }
};

// Derived Class 2
class NonTeachingStaff : public Employee
{
private:
    string designation;
    int workingHours;

public:
    void getNonTeachingDetails()
    {
        getEmployeeDetails();

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Working Hours: ";
        cin >> workingHours;
    }

    void displayNonTeachingDetails()
    {
        displayEmployeeDetails();

        cout << "\nDesignation: " << designation;
        cout << "\nWorking Hours: " << workingHours << " hours";
    }
};

int main()
{
    TeachingStaff teacher;
    NonTeachingStaff staff;

    cout << "\n--- Enter Teaching Staff Details ---\n";
    teacher.getTeachingDetails();

    cout << "\n--- Enter Non-Teaching Staff Details ---\n";
    staff.getNonTeachingDetails();

    cout << "\n\n--- Teaching Staff Details ---";
    teacher.displayTeachingDetails();

    cout << "\n\n--- Non-Teaching Staff Details ---";
    staff.displayNonTeachingDetails();

    return 0;
}