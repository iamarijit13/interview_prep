#include<iostream>
#include<stack>
#define ll long long int
using namespace std;

string infix_to_postfix(string);
int precedence (char);

int main () {
    ll tests;

    cin >> tests;

    while (tests--) {
        ll n;
        string expression, postfix;

        cin >> n;
        cin >> expression;

        postfix = infix_to_postfix(expression);
        cout << postfix << "\n";
    }

    return 0;
}

int precedence (char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

string infix_to_postfix(string expression) {
    stack<char> st;
    string postfix;
    for (ll i = 0; i < expression.length(); i++) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9')) {
            postfix += expression[i];
        } else if (expression[i] == '(') {
            st.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(expression[i]) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
    }
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
