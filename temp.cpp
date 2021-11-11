#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>, vector<int>, int);

int main () {
    int n = 4, capacity = 10;
    vector<int> we(n), ve(n);

    we = {1, 3, 4, 6};
    ve = {20, 30, 10, 50};

    int re = knapsack(we, ve, capacity);

    cout << re << "\n\n";

    return 0;
}

int knapsack (vector<int> we, vector<int> ve, int capacity) {
    int n = ve.size();
    vector<vector<int>> kn(n + 1, vector<int> (capacity + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                kn[i][j] = 0;
            } else if (we[i - 1] <= j) {
                kn[i][j] = max(ve[i - 1] + kn[i - 1][j - we[i - 1]], ve[j - 1]);
            } else {
                kn[i][j] = kn[i - 1][j];
            }
        }
    }
    return kn[n][capacity];
}