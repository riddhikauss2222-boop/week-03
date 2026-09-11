#include <iostream>
using namespace std;

// 1. Factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 2. Fibonacci
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 4. Sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int choice, n, a, b;

    cout << "1. Factorial\n";
    cout << "2. Fibonacci\n";
    cout << "3. GCD\n";
    cout << "4. Sum of Digits\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter number: ";
            cin >> n;
            cout << "Factorial = " << factorial(n) << endl;
            break;

        case 2:
            cout << "Enter number of terms: ";
            cin >> n;
            cout << "Fibonacci: ";
            for (int i = 0; i < n; i++)
                cout << fibonacci(i) << " ";
            cout << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "GCD = " << gcd(a, b) << endl;
            break;

        case 4:
            cout << "Enter number: ";
            cin >> n;
            if (n < 0) n = -n;
            cout << "Sum of digits = " << sumOfDigits(n) << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
