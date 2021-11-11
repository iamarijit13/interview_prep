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