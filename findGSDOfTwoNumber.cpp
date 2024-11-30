#include <iostream>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    while (true) {
        int choice;
        cout << "Enter 1 to continue or 0 to exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter first number: ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;
            cout << "The GCD of the given numbers is: " << gcd(a, b) << endl; // Added newline for better readability
        } else if (choice == 0) {
            cout << "Exiting the program." << endl;
            break; // Replacing `exit(0)` with `break` for better readability
        } else {
            cout << "Invalid choice. Please enter 1 to continue or 0 to exit." << endl;
        }
    }
    return 0;
}
