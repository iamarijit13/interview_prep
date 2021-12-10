#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main () {
    int tests;

    cin >> tests;

    while(tests--) {
        string expression;
        ll int open = 0, balance = 0, res = 0;

        cin >> expression;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[0] != '<') {
                break;
            }
            if (expression[i] == '<') {
                open++;
            }
            if (expression[i] == '>' && open > 0) {
                open--;
                balance += 2;
            }
            if (open == 0) {
                res = balance;
            }
        }
        cout << res << "\n";
    }
}