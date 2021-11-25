#include<iostream>
#include<vector>
using namespace std;

int unique_bst (int n) {
    vector<int> dp(n + 1);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[i - j] * dp[j - 1];
            cout << dp[j] << " ";
        }
        cout << "\n";
    }

    return dp[n];
}

int main () {
    int n = 3, re;
    re = unique_bst(3);

    cout << "\nunique BST with n = " << n << ": " << re << "\n\n";

    return 0;  
}