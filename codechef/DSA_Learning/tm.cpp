#include<iostream>
#include<vector>
#include<stack>
#define ll long long int
#define mod 1000000007
using namespace std;

ll fear (vector<ll> a) {
    stack<ll> s, s1;
    ll i, mul = 1, n = a.size();

    for (i = n - 1; i >= 0; i--) {
        ll sum = 1;

        while (!s.empty() && s.top() >= a[i]) {
            s.pop();
            s1.pop();
        }
        if (s.empty()) {
            sum = 1;
        } else {
            sum = s1.top() - i + 1;
        }
        s.push(a[i]);
        s1.push(i);
        mul = (mul * sum) % mod;
    }
    return mul;
}

int main () {
    ll n, k, i, x;
    vector<ll> a;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }

    cout << fear(a) << "\n";

    return 0;
}
