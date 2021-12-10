#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

int main () {
    ll tests;

    cin >> tests;

    while (tests--) {
        ll n, x, depth = 0, dep_fir = 0, len = 0, len_fir = 0, open = 0, t_len = 0;
        vector<ll> sequence;

        cin >> n;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            sequence.push_back(x);
        }

        for (ll i = 0; i < n; i++) {
            if (sequence[i] == 1) {
                open++;
            }
            if (open > 0) {
                t_len++;
                if (t_len > len) {
                    len = t_len;
                    len_fir = (i + 1) - (len - 1);
                }
            } 
            if (depth < open) {
                depth = open;
                dep_fir = i + 1;
            }
            if (sequence[i] == 2) {
                open--;
            }
            if (open == 0) {
                t_len = 0;
            }
        }
        cout << depth << " " << dep_fir << " " << len << " " << len_fir << " \n";
    }
    return 0;
}