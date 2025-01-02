#include <iostream>
#include <string>
using namespace std;

void showMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Balance Inquiry\n";
    cout << "2. Cash Withdrawal\n";
    cout << "3. Change PIN\n";
    cout << "4. Exit\n";
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

void withdrawCash(double &balance) {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient balance. Transaction declined.\n";
    } else if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value.\n";
    } else {
        balance -= amount;
        cout << "Transaction successful. Please collect your cash.\n";
        cout << "Remaining balance: $" << balance << endl;
    }
}

int main() {
    string pin = "1234";
    string enteredPIN;
    int attempts = 0;
    bool authenticated = false;
    double balance = 5000.00;

    cout << "Welcome to ATM Simulation\n";

    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pin) {
            authenticated = true;
            cout << "Authentication Successful!" << endl;
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts remaining: " << 3 - attempts << endl;
        }
    }

    if (!authenticated) {
        cout << "Too many incorrect attempts. Exiting...\n";
        return 0;
    }

    int choice;
    do {
        showMenu();
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                withdrawCash(balance);
                break;
            case 4:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}