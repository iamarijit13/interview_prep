#include<iostream>
#include<vector>
using namespace std;

int lcs (string one, string two) {
    vector<vector<int>> lcs(one.size() + 1, vector<int> (two.size() + 1));

    for (int i = 0; i <= one.size(); i++) {
        for (int j = 0; j <= two.size(); j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (one[i - 1] == two[j -1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }

    return lcs[one.size()][two.size()];
}

int main () {
    string one, two;
    getline(cin, one);
    getline(cin, two);

    int re = lcs(one, two);
    cout << "\nLongest common subscquence: " << re << "\n\n";

    return 0;
}