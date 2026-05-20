#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    int getAccountNumber() const { 
        return accountNumber; 
    }
    
    string getAccountHolder() const { 
        return accountHolder; 
    }
    
    double getBalance() const { 
        return balance; 
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << fixed << setprecision(2) << amount << "\n";
        } else {
            cout << "Error: Deposit amount must be positive.\n";
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds! Available balance: $" << fixed << setprecision(2) << balance << "\n";
            return false;
        }
        balance -= amount;
        cout << "Successfully withdrew $" << fixed << setprecision(2) << amount << "\n";
        return true;
    }

    void displayInfo() const {
        cout << "Account Holder : " << accountHolder << "\n";
        cout << "Account Number : " << accountNumber << "\n";
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << "\n";
    }
};

BankAccount* findAccount(vector<BankAccount>& accounts, int accNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNum) {
            return &acc;
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> bankDatabase;
    int nextAccountNumber = 1001;
    int choice;

    while (true) {
        cout << "=================================\n";
        cout << "      BANKING SYSTEM UTILITY     \n";
        cout << "=================================\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. View Account Details\n";
        cout << "6. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice (1-6): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a valid number.\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            string name;
            double initialDeposit;
            cout << "\n--- CREATE NEW ACCOUNT ---\n";
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Enter Initial Deposit Amount: $";
            while (!(cin >> initialDeposit) || initialDeposit < 0) {
                cout << "Invalid amount. Enter a valid starting balance: $";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            bankDatabase.push_back(BankAccount(name, nextAccountNumber, initialDeposit));
            cout << "Account created successfully! Your Account Number is: " << nextAccountNumber << "\n";
            nextAccountNumber++;

        } else if (choice == 2) {
            int accNum;
            double amount;
            cout << "\n--- DEPOSIT FUNDS ---\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            BankAccount* account = findAccount(bankDatabase, accNum);
            if (account != nullptr) {
                cout << "Enter Deposit Amount: $";
                cin >> amount;
                account->deposit(amount);
            } else {
                cout << "Error: Account number not found.\n";
            }

        } else if (choice == 3) {
            int accNum;
            double amount;
            cout << "\n--- WITHDRAW FUNDS ---\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            BankAccount* account = findAccount(bankDatabase, accNum);
            if (account != nullptr) {
                cout << "Enter Withdrawal Amount: $";
                cin >> amount;
                account->withdraw(amount);
            } else {
                cout << "Error: Account number not found.\n";
            }

        } else if (choice == 4) {
            int senderNum, receiverNum;
            double amount;
            cout << "\n--- TRANSFER FUNDS ---\n";
            cout << "Enter Your Account Number: ";
            cin >> senderNum;

            BankAccount* sender = findAccount(bankDatabase, senderNum);
            if (sender == nullptr) {
                cout << "Error: Source account number not found.\n";
                continue;
            }

            cout << "Enter Destination Account Number: ";
            cin >> receiverNum;

            BankAccount* receiver = findAccount(bankDatabase, receiverNum);
            if (receiver == nullptr) {
                cout << "Error: Destination account number not found.\n";
                continue;
            }

            if (senderNum == receiverNum) {
                cout << "Error: Cannot transfer money to the same account.\n";
                continue;
            }

            cout << "Enter Transfer Amount: $";
            cin >> amount;

            if (sender->withdraw(amount)) {
                receiver->deposit(amount);
                cout << "Transfer complete! Successfully moved $" << amount << " to Account #" << receiverNum << ".\n";
            }

        } else if (choice == 5) {
            int accNum;
            cout << "\n--- VIEW ACCOUNT PROFILE ---\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            BankAccount* account = findAccount(bankDatabase, accNum);
            if (account != nullptr) {
                cout << "---------------------------------\n";
                account->displayInfo();
                cout << "---------------------------------\n";
            } else {
                cout << "Error: Account number not found.\n";
            }

        } else if (choice == 6) {
            cout << "\nClosing banking engine safely. Goodbye!\n";
            break;
        } else {
            cout << "Invalid selection! Please choose an option between 1 and 6.\n";
        }
        cout << "\n";
    }

    return 0;
}