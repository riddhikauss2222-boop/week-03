#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;

int main() {
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push((int)pow(a, b)); break;
            }
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}
