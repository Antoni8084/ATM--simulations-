#include <iostream>
#include <string>
#include <vector>
#include <deque> // For Mini Statement implementation
#include <thread>
#include <chrono>
using namespace std;

// Function to display the ATM menu
void showMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Balance Inquiry\n";
    cout << "2. Cash Withdrawal\n";
    cout << "3. Change PIN\n";
    cout << "4. Deposit Cash\n";
    cout << "5. Transaction History\n";
    cout << "6. Mini Statement\n";
    cout << "7. Exit\n";
}

// Function to check balance
void checkBalance(double balance, deque<string> &miniStatement) {
    cout << "Your current balance is: $" << balance << endl;
    miniStatement.push_back("Checked balance: $" + to_string(balance));
    if (miniStatement.size() > 5) miniStatement.pop_front(); // Keep only 5 transactions
}

// Function to withdraw cash
void withdrawCash(double &balance, deque<string> &miniStatement) {
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
        miniStatement.push_back("Withdrew: $" + to_string(amount));
        if (miniStatement.size() > 5) miniStatement.pop_front();
    }
}

// Function to deposit cash
void depositCash(double &balance, deque<string> &miniStatement) {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value.\n";
    } else {
        balance += amount;
        cout << "Deposit successful. Your new balance is: $" << balance << endl;
        miniStatement.push_back("Deposited: $" + to_string(amount));
        if (miniStatement.size() > 5) miniStatement.pop_front();
    }
}

// Function to change PIN
void changePIN(string &pin, deque<string> &miniStatement) {
    string oldPIN, newPIN;
    cout << "Enter your current PIN: ";
    cin >> oldPIN;

    if (oldPIN == pin) {
        cout << "Enter your new PIN: ";
        cin >> newPIN;
        pin = newPIN;
        cout << "PIN changed successfully.\n";
        miniStatement.push_back("Changed PIN");
        if (miniStatement.size() > 5) miniStatement.pop_front();
    } else {
        cout << "Incorrect PIN. PIN change failed.\n";
    }
}

// Function to display transaction history
void showHistory(const deque<string> &miniStatement) {
    cout << "\nMini Statement (Last 5 Transactions):\n";
    if (miniStatement.empty()) {
        cout << "No transactions yet.\n";
    } else {
        for (const auto &record : miniStatement) {
            cout << "- " << record << endl;
        }
    }
}

// Function to display all transactions
void showFullHistory(const vector<string> &history) {
    cout << "\nTransaction History:\n";
    if (history.empty()) {
        cout << "No transactions yet.\n";
    } else {
        for (const auto &record : history) {
            cout << "- " << record << endl;
        }
    }
}

int main() {
    string pin = "1234"; // Default PIN
    string enteredPIN;
    int attempts = 0;
    bool authenticated = false;
    double balance = 5000.00; // Initial balance
    vector<string> history;  // Stores full transaction history
    deque<string> miniStatement; // Stores last 5 transactions

    cout << "Welcome to ATM Simulation\n";

    // PIN authentication with locking mechanism
    while (true) {
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

        if (authenticated) {
            break;
        } else {
            cout << "Too many incorrect attempts. Your account is locked for 10 seconds.\n";
            this_thread::sleep_for(chrono::seconds(10));
            attempts = 0; // Reset attempts after locking
        }
    }

    // Main menu
    int choice;
    do {
        showMenu();
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance, miniStatement);
                history.push_back("Checked balance: $" + to_string(balance));
                break;
            case 2:
                withdrawCash(balance, miniStatement);
                history.push_back("Withdrew cash");
                break;
            case 3:
                changePIN(pin, miniStatement);
                history.push_back("Changed PIN");
                break;
            case 4:
                depositCash(balance, miniStatement);
                history.push_back("Deposited cash");
                break;
            case 5:
                showFullHistory(history);
                break;
            case 6:
                showHistory(miniStatement);
                break;
            case 7:
                cout << "Thank you for using our ATM.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}