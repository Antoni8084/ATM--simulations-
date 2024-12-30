#include <iostream>
#include <string>

using namespace std;

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

    return 0;
}