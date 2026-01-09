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

    void changePin(int oldPin, int newPin) {
        if (oldPin == pin) {
            pin = newPin;
            cout << "PIN changed successfully." << endl;
            history.push_back("PIN changed");
        } else {
            cout << "Incorrect old PIN. PIN not changed." << endl;
        }
    }
};


int main() {
    ATM user(2387, 5000);   // PIN = 2387, Balance = 5000

    int enteredPin;
    int attempts = 0;

    // 3-attempt PIN logic
    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (user.verifyPin(enteredPin)) {
            break;   // correct PIN
        } else {
            attempts++;
            cout << "Wrong PIN! Attempts left: " << 3 - attempts << endl;
        }
    }

    if (attempts == 3) {
        cout << "Account locked. Too many wrong attempts." << endl;
        return 0;
    }

    // DIRECTLY go to menu – DO NOT ask PIN again
    int choice;
    double amount;

    do {
    cout << "\n===== ATM MENU =====" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transaction History" << endl;
    cout << "5. Exit" << endl;
    cout << "6. Change PIN" << endl;
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

        case 6: {
            int oldPin, newPin;
            cout << "Enter old PIN: ";
            cin >> oldPin;

            cout << "Enter new PIN: ";
            cin >> newPin;

            user.changePin(oldPin, newPin);
            break;
        }

        default:
            cout << "Invalid choice. Try again." << endl;
    }

} while (choice != 5);
return 0;
}
