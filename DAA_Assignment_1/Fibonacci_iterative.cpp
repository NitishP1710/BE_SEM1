#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int choice;
    while (true) {
        cout << "Fibonacci Calculator" << endl;
        cout << "1. Calculate Fibonacci number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        if (choice == 1) {
            int n;
            cout << "Enter a number: ";
            cin >> n;

            if (n < 0) {
                cout << "Invalid input. Please enter a non-negative number." << endl;
            } else {
                cout << "Fibonacci number at index " << n
                     << " is " << fibonacci(n) << endl;
            }
        } else {
            cout << "Invalid choice. Please select 1 or 0." << endl;
        }
    }

    return 0;
}