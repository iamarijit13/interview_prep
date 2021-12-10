#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;

int main () {
    int tests;

    cin >> tests;

    while (tests--) {
        ll n, z, x, count = 0, t;
        priority_queue<ll> soldier;

        cin >> n >> z;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            soldier.push(x);
        }

        while (!soldier.empty() && z > 0) {
            z -= soldier.top();
            t = soldier.top() / 2;
            soldier.pop();
            if (t > 0) {
                soldier.push(t);
            }
            count++;
        }
        if (z > 0) {
            cout << "Evacuate\n";
        } else {
            cout << count << "\n";
        }
    }
}