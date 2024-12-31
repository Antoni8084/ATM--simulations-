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

int main() {
    string pin = "1234";
    string enteredPIN;
    int attempts = 0;
    bool authenticated = false;

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
            case 4:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}