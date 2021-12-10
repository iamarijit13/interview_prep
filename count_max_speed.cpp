#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int main () {
    ll int tests;

    cin >> tests;
    
    while (tests--){
        ll int n, x, count = 1;
        vector<ll int> speeds;

        cin >> n;

        for (ll int i = 0; i < n; i++) {
            cin >> x;
            speeds.push_back(x);
        }

        for ( ll int i = 1; i < speeds.size(); i++) {
            if (speeds[i] < speeds[i - 1]) {
                count++;
            }
        }

        cout << count;
    }
    
}