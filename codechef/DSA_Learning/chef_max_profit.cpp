#include<iostream>
#include<vector>
using namespace std;

int main () {
    int tests;

    cin >> tests;

    while (tests--) {
        int n, x, max_profit = 0;
        vector<int> shops, people, values;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            shops.push_back(x);
            cin >> x;
            people.push_back(x);
            cin >> x;
            values.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            int profit = (people[i] / (shops[i] + 1)) * values[i];

            if (profit > max_profit) {
                max_profit = profit;
            }
        }

        cout << max_profit << "\n\n";
    }

    return 0;
}