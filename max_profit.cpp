#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main () {
    ll int n, x, max = 0;
    vector<ll int> budgets;

    cin >> n;

    for (ll int i = 0; i < n; i++) {
        cin >> x;
        budgets.push_back(x);
    }

    std :: sort(budgets.begin(), budgets.end());

    for (ll int i = 0; i < n; i++) {
        if ((budgets[i] * (n - i)) > max) {
            max = (budgets[i] * (n - i));
        }
    }

    cout << max << "\n\n";

    return 0;
}