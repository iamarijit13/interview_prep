#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main () {
    int tests;
    cin >> tests;

    while (tests--) {
        ll int n, x, min = INT_MAX, res = 0, deduct = 0;
        vector<pair<ll int, ll int>> boxes;
        cin >> n;

        for (ll int i = 0; i < n; i++) {
            cin >> x;
            boxes.push_back(make_pair(i, x));
        }

        for (int i = 0; i < n; i++) {
            min = *min_element(boxes.begin(), boxes.end());
            res += ((min * boxes.size()) - deduct);
            deduct += min;
            boxes.pop_back();
        }
        cout << res << "\n";
    }
}