#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> we, vector<int> ve, int capacity) {
    vector<vector<int>> kn(we.size() + 1, vector<int> (capacity + 1));

    for (int i = 0; i <= ve.size(); i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                kn[i][j] = 0;
            } else if (we[i - 1] <= j) {
                kn[i][j] = max(ve[i - 1] +
                                kn[i - 1][j - we[i - 1]],
                                kn[i - 1][j]);
            } else {
                kn[i][j] = kn[i - 1][j];
            }
        }
    }
    
    for (int i = 0; i <= ve.size(); i++) {
        for (int j = 0; j <= capacity; j++) {
            cout << kn[i][j] << " ";
        }
        cout << "\n";
    }

    return kn[ve.size()][capacity];
}

int main () {
    int n = 6, capacity = 10;
    vector<int> we(n), ve(n);

    // ve = {60, 100, 120};
    // we = {10, 20, 30};

    we = {1, 3, 4, 6};
    ve = {20, 30, 10, 50};
    

    // for (int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     we.push_back(x);
    // }

    // for (int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     ve.push_back(x);
    // }

    int re = knapsack(we, ve, capacity);

    cout << "\nMaximum weight can carry: " << re << "\n\n";

    return 0;
}