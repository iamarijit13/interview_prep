#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse_ar(vector<int> ar) {
    std :: reverse(ar.begin(), ar.end());
    return ar;
}

void print(vector<int> re) {
    for (auto x : re) {
        cout << x << " ";
    }
}

int main () {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> re = reverse_ar(arr);
    print(re);

    return 0;
}
