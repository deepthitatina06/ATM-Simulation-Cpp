#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ATM {
private:
    int pin;
    double balance;
    vector<string> history;

public:
    ATM(int userPin, double initialBalance) {
        pin = userPin;
        balance = initialBalance;
    }

    bool verifyPin(int enteredPin) {
        // DEBUG LINE - remove later
        cout << "DEBUG: System PIN is = " << pin << endl;
        return enteredPin == pin;
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
        history.push_back("Checked balance");
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        balance += amount;
        cout << "₹" << amount << " deposited successfully." << endl;
        history.push_back("Deposited ₹" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "₹" << amount << " withdrawn successfully." << endl;
        history.push_back("Withdrew ₹" + to_string(amount));
    }

    void showHistory() {
        cout << "\n--- Transaction History ---" << endl;
        if (history.empty()) {
            cout << "No transactions yet." << endl;
        } else {
            for (int i = 0; i < history.size(); i++) {
                cout << i + 1 << ". " << history[i] << endl;
            }
        }
    }
};

int main() {
    // CHANGE PIN HERE
    ATM user(2387, 5000);   // PIN = 2387, Balance = 5000

    int enteredPin;
    cout << "===== Welcome to ATM =====" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (!user.verifyPin(enteredPin)) {
        cout << "Incorrect PIN. Access denied!" << endl;
        return 0;
    }

    int choice;
    double amount;

    do {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                user.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                user.withdraw(amount);
                break;
            case 4:
                user.showHistory();
                break;
            case 5:
                cout << "Thank you for using ATM!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
