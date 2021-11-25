#include<iostream>
#include<vector>
using namespace std;

// int max_product (vector<int> ar) {
//     if (ar.size() == 0) return 1;

//     int max = 1;

//     for (int i = 0; i < ar.size(); i++) {
//         ar.erase(ar.begin());
//         int res = max_product(ar);
//         if (res * max * ar[0] > max) {
//             max *= res * ar[0];
//         } else {
//             return 1;
//         }
//     }
//     return max;
// }

// int max_product(vector<int> A) {
//     int r = A[0];

//     for (int i = 1, imax = r, imin = r; i < A.size(); i++) {
//         if (A[i] < 0)
//             swap(imax, imin);

//         imax = max(A[i], imax * A[i]);
//         imin = min(A[i], imin * A[i]);

        
//         r = max(r, imax);
//     }
//     return r;
// }

// Kadane algorithm

int max_product (vector<int> ar) {
    int max_ends_here = 1, max_so_far = INT_MIN;

    for (int i = 0; i < ar.size(); i++) {

        if (max_ends_here * ar[i] >= ar[i]) {
            max_ends_here *= ar[i];
        } else {
            max_ends_here = ar[i];
        }

        if (max_ends_here > max_so_far) {
            max_so_far = max_ends_here;
        }
    }

    return max_so_far;
}

int main () {
    vector<int> ar = {2, 3, -2, 4};
    vector<int> dp(ar.size() + 1);

    int re = max_product(ar);

    cout << re << "\n\n";
}