
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, std::string name, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialDeposit;
    }

    // Getters
    int getAccountNumber() const {
        return accountNumber;
    }

    std::string getName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited Rs." << amount << "\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds! Current balance is Rs."
                      << balance << "\n";
        } 
        else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!\n";
        } 
        else {
            balance -= amount;
            std::cout << "Successfully withdrew Rs." << amount << "\n";
        }
    }

    // Display account details
    void displayAccountDetails() const {
        std::cout << std::left
                  << std::setw(15) << accountNumber
                  << std::setw(25) << accountHolderName
                  << "Rs." << std::setw(12)
                  << std::fixed << std::setprecision(2)
                  << balance << "\n";
    }
};

class BankSystem {
private:
    std::vector<BankAccount> accounts;
    int nextAccountNumber = 1001;

public:
    // 1. Create new account
    void createAccount() {
        std::string name;
        double initialDeposit;

        std::cin.ignore();

        std::cout << "\nEnter Account Holder Full Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Initial Deposit Amount: Rs.";
        std::cin >> initialDeposit;

        if (initialDeposit < 0) {
            std::cout << "Initial deposit cannot be negative!\n";
            return;
        }

        BankAccount newAccount(
            nextAccountNumber,
            name,
            initialDeposit
        );

        accounts.push_back(newAccount);

        std::cout << "\nAccount created successfully!\n";
        std::cout << "Your Account Number is: "
                  << nextAccountNumber << "\n";

        nextAccountNumber++;
    }

    // 2. Deposit money
    void handleDeposit() {
        int accNum;
        double amount;

        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {

                std::cout << "Enter Amount to Deposit: Rs.";
                std::cin >> amount;

                account.deposit(amount);
                return;
            }
        }

        std::cout << "Account number not found!\n";
    }

    // 3. Withdraw money
    void handleWithdrawal() {
        int accNum;
        double amount;

        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {

                std::cout << "Enter Amount to Withdraw: Rs.";
                std::cin >> amount;

                account.withdraw(amount);
                return;
            }
        }

        std::cout << "Account number not found!\n";
    }

    // 4. Check balance
    void checkBalance() const {
        int accNum;

        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {

                std::cout << "\n--- Account Details ---\n";

                std::cout << "Account Number: "
                          << account.getAccountNumber() << "\n";

                std::cout << "Holder Name:    "
                          << account.getName() << "\n";

                std::cout << "Current Balance: Rs."
                          << std::fixed
                          << std::setprecision(2)
                          << account.getBalance() << "\n";

                return;
            }
        }

        std::cout << "Account number not found!\n";
    }

    // 5. Display all accounts
    void displayAllAccounts() const {
        if (accounts.empty()) {
            std::cout << "\nNo accounts found in the bank registry.\n";
            return;
        }

        std::cout << "\n-----------------------------------------------------------\n";

        std::cout << std::left
                  << std::setw(15) << "Account No."
                  << std::setw(25) << "Account Holder"
                  << std::setw(15) << "Balance"
                  << "\n";

        std::cout << "-----------------------------------------------------------\n";

        for (const auto& account : accounts) {
            account.displayAccountDetails();
        }

        std::cout << "-----------------------------------------------------------\n";
    }
};

int main() {

    BankSystem centralBank;
    int choice;

    while (true) {

        std::cout << "\n======= APEX BANKING SYSTEM =======\n";
        std::cout << "1. Open New Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance Inquiry\n";
        std::cout << "5. Display All Bank Registry\n";
        std::cout << "6. Exit Application\n";

        std::cout << "Enter choice (1-6): ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                centralBank.createAccount();
                break;

            case 2:
                centralBank.handleDeposit();
                break;

            case 3:
                centralBank.handleWithdrawal();
                break;

            case 4:
                centralBank.checkBalance();
                break;

            case 5:
                centralBank.displayAllAccounts();
                break;

            case 6:
                std::cout << "\nThank you for banking with us. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid action code! Try again.\n";
        }
    }

    return 0;
}






