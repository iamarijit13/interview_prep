#include<iostream>
#include<vector>
using namespace std;

vector<int> largest(vector<int>, int);
void print(vector<int>);

int main () {
    vector<int> array = {1, 2, 3, 4, 8, 0, -1, 12, 5, 13, 25}, result; 
    int k = 4;

    result = largest(array, k);

    print(result);

    return 0;
}

vector<int> largest(vector<int> arr, int k) {
    vector<int> temp(arr.begin(), arr.begin() + (k -1));

    int min = 0;

    for (int i = k; i < arr.size(); i++) {
        for (int j = 1; j < temp.size(); j++) {
            if (temp[min] > temp[j]) {
                min = j;
            }
        }

        if (arr[i] > temp[min]) {
            temp[min] = arr[i];
        }
    }

    return temp;
}

void print(vector<int> result) {
    cout << "\nResult: ";
    for (auto x : result) {
        cout << x << " ";
    }
}

//By sorting.

// vector<int> Solution::solve(vector<int> &A, int B) {
//     sort(A.rbegin(), A.rend());
//     vector<int> re;

//     for (int i = 0; i < B; i++) {
//         re.push_back(A[i]);
//     }

//     return re;
// }


// Using Priority_Queue
// vector<int> Solution::solve(vector<int> &A, int B) {
//     priority_queue<int> qu;
//     vector<int> re;

//     for ( auto x : A) {
//         qu.push(x);
//     }

//     while (B) {
//         re.push_back(qu.top());
//         qu.pop();
//         B--;
//     }

//     return re;
// }