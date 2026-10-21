```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Abstract base class
class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

protected:
    double getBalance() const {
        return balance;
    }

    void setBalance(double amount) {
        balance = amount;
    }

public:
    // Constructor
    BankAccount(int accNo, string name, double amount) {
        accountNumber = accNo;
        holderName = name;
        balance = amount;
    }

    // Encapsulation: public getter functions
    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

    // Pure virtual function: Abstraction
    virtual void calculateInterest() = 0;

    virtual void displayDetails() const {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << holderName;
        cout << fixed << setprecision(2);
        cout << "\nBalance: Rs. " << balance << endl;
    }

    virtual ~BankAccount() {}
};

// Inheritance
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int accNo, string name, double amount)
        : BankAccount(accNo, name, amount) {}

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            setBalance(getBalance() + amount);
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        } else if (amount <= getBalance()) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    // Check balance
    void checkBalance() const {
        cout << fixed << setprecision(2);
        cout << "Current Balance: Rs. "
             << getBalance() << endl;
    }

    // Abstraction: implementation of virtual function
    void calculateInterest() override {
        double interest = getBalance() * 0.04;
        setBalance(getBalance() + interest);

        cout << fixed << setprecision(2);
        cout << "Interest added: Rs. " << interest << endl;
    }

    // Display account details
    void displayDetails() const override {
        cout << "\n--- ACCOUNT DETAILS ---\n";
        BankAccount::displayDetails();
    }

    // Save account details to file
    void saveToFile() const {
        ofstream file("account.txt");

        if (file.is_open()) {
            file << getAccountNumber() << '\n';
            file << getHolderName() << '\n';
            file << fixed << setprecision(2)
                 << getBalance() << '\n';

            file.close();
            cout << "Account details saved successfully!\n";
        } else {
            cout << "Unable to open file!\n";
        }
    }
};

// Read account details from file
bool loadFromFile(int& accNo, string& name, double& balance) {
    ifstream file("account.txt");

    if (!file.is_open()) {
        return false;
    }

    if (!(file >> accNo)) {
        file.close();
        return false;
    }

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!getline(file, name) || !(file >> balance)) {
        file.close();
        return false;
    }

    file.close();
    return true;
}

int main() {
    int accNo;
    string name;
    double balance;

    if (loadFromFile(accNo, name, balance) && balance >= 0) {
        cout << "Previous account loaded successfully!\n";
    } else {
        cout << "Create a new account.\n";

        cout << "Enter account number: ";
        cin >> accNo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter account holder name: ";
        getline(cin, name);

        cout << "Enter opening balance: Rs. ";
        cin >> balance;

        if (balance < 0) {
            cout << "Balance cannot be negative!\n";
            return 0;
        }
    }

    SavingsAccount account(accNo, name, balance);

    int choice;
    double amount;

    do {
        cout << "\n============================\n";
        cout << "   ATM BANKING SYSTEM\n";
        cout << "============================\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Details\n";
        cout << "5. Add Interest (4%)\n";
        cout << "6. Save Account Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: Rs. ";
                if (cin >> amount)
                    account.deposit(amount);
                else {
                    cout << "Invalid amount!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                }
                break;

            case 2:
                cout << "Enter withdrawal amount: Rs. ";
                if (cin >> amount)
                    account.withdraw(amount);
                else {
                    cout << "Invalid amount!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                }
                break;

            case 3:
                account.checkBalance();
                break;

            case 4:
                account.displayDetails();
                break;

            case 5:
                account.calculateInterest();
                cout << "Interest calculated successfully!\n";
                break;

            case 6:
                account.saveToFile();
                break;

            case 0:
                account.saveToFile();
                cout << "Thank you for using ATM Banking System!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
```