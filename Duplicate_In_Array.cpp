/*
Problem Description

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>);

int main() {
    vector<int> arr = {3, 4, 1, 4, 1};

    cout << findDuplicate(arr);

    return 0;
}

int findDuplicate(vector<int> A) {
    vector<int> v(A.size(), 0);

    for (auto x : A) {
        v[x]++;

        if (v[x] == 2) return x;
    }

    return -1;
}