/*
Jumping Game:
Given an array of non-negative integers arr, you are initially positioned at the start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
Notice that you can not jump outside of the array at any time.
 
Example 1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3

Example 3:
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
Example 4:
Input: arr = [4,2,3,0,3,1,2,4]
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool find_zero(vector<int> arr, int start) {
    stack<int> track;
    track.push(start);

    while (!track.empty()) {
        int tm = track.top();
        track.pop();
        if (arr[tm] == 0) {
            return true;
        }
        arr[tm] = -1;

        if ((tm + arr[tm] <= arr.size()) && (tm + arr[tm] >= 0) && (arr[tm + arr[tm]] != -1)) {
            track.push(tm + arr[tm]);
        }
        if ((tm - arr[tm] <= arr.size()) && (tm - arr[tm] >= 0) && (arr[tm - arr[tm]] != -1)) {
            track.push(tm - arr[tm]);
        }
    }
    return false;
}

int main () {
    int start = 0;
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};

    bool decider = find_zero(arr, start);

    if (decider == true) {
        cout << "Possible.\n";
    } else {
        cout << "Not Possible.\n";
    }

    return 0;
}