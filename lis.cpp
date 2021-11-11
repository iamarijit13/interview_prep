#include<iostream>
#include<vector>
using namespace std;

int lis (vector<int> ar) {
    vector<int> lis(ar.size());

    lis[0] = 1;

    for (int i = 1; i < ar.size(); i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (ar[j] < ar[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main () {
    vector<int> ar = {2, 4, 7, 1, 3, 0, -3, 43, 23, 45, 90};

    int re = lis(ar);

    cout << "\nLongest increasing subsiquence: " << re << "\n\n";

    return 0;
}