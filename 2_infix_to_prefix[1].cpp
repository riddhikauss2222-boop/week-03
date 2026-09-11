#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, prefix = "", temp;
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    for (char ch : infix) {
        if (isalnum(ch))
            temp += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                temp += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' &&
                   precedence(s.top()) > precedence(ch)) {
                temp += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        temp += s.top();
        s.pop();
    }

    reverse(temp.begin(), temp.end());
    cout << "Prefix: " << temp << endl;

    return 0;
}
