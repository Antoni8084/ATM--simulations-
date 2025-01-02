#include <iostream>
#include <string>
using namespace std;

// Function to display the ATM menu
void showMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Balance Inquiry\n";
    cout << "2. Cash Withdrawal\n";
    cout << "3. Change PIN\n";
    cout << "4. Deposit Cash\n";
    cout << "5. Exit\n";
}

// Function to check balance
void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

// Function to withdraw cash
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

// Function to deposit cash
void depositCash(double &balance) {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value.\n";
    } else {
        balance += amount;
        cout << "Deposit successful. Your new balance is: $" << balance << endl;
    }
}

// Function to change PIN
void changePIN(string &pin) {
    string oldPIN, newPIN;
    cout << "Enter your current PIN: ";
    cin >> oldPIN;

    if (oldPIN == pin) {
        cout << "Enter your new PIN: ";
        cin >> newPIN;
        pin = newPIN;
        cout << "PIN changed successfully.\n";
    } else {
        cout << "Incorrect PIN. PIN change failed.\n";
    }
}

int main() {
    string pin = "1234"; // Default PIN
    string enteredPIN;
    int attempts = 0;
    bool authenticated = false;
    double balance = 5000.00; // Initial balance

    cout << "Welcome to ATM Simulation\n";

    // PIN authentication
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

    // Main menu
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
            case 3:
                changePIN(pin);
                break;
            case 4:
                depositCash(balance);
                break;
            case 5:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}