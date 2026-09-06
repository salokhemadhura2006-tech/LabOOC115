#include <iostream>
#include <string>
using namespace std;

class MobileRecharge {
private:
    string mobileNumber;
    string customerName;
    float balance;

public:
    // Constructor
    MobileRecharge(string number, string name) {
        mobileNumber = number;
        customerName = name;
        balance = 0;
    }

    // Add recharge
    void recharge(float amount) {
        balance = balance + amount;
        cout << "Recharge successful!" << endl;
    }

    // Deduct balance
    void deductBalance(float amount) {
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Balance deducted successfully!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Display account details
    void displayAccount() {
        cout << "\nMobile Number: " << mobileNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    // Object creation
    MobileRecharge m1("9876543210", "Rahul");

    m1.displayAccount();

    m1.recharge(500);
    m1.displayAccount();

    m1.deductBalance(200);
    m1.displayAccount();

    return 0;
}