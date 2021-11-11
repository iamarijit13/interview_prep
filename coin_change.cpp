#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>, int, vector<int>);

int main () {
    int target = 18;
    vector<int> coins = {7, 5, 1};
    vector<int> dp(target + 1);

    fill(dp.begin(), dp.end(), -1);
    int re = coinChange(coins, target, dp);

    cout << "\nMinimum coins needed: " << re << "\n\n";
}

int coinChange (vector<int> coins, int target, vector<int> dp) {
    if (target == 0) return 0;

    int res = INT_MAX;

    for (int coin = 0; coin < coins.size(); coin++) {
        int remainder = target - coins[coin];

        if (remainder >= 0) {
            int subre = 0;
            if (dp[remainder] != -1) {
                subre = dp[remainder];
            } else {
                subre = coinChange(coins, remainder, dp);
            }

            if (subre != INT_MAX && subre + 1 < res) {
                res = subre + 1;
            }
        }
    }
    return dp[target] = res;
}