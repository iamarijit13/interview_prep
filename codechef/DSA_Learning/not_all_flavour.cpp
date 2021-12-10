#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main () {
    int tests;

    cin >> tests;

    while (tests--) {
        int n, k, x, max = 0, count = 0, start = 0, step = 0;
        vector<int> flavours;
        vector<int> track;
        unordered_map<int, int> mp;

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> x;
            flavours.push_back(x);
        }
        track.push_back(0);
        mp.insert(make_pair(flavours[0], 1));
        count++;
        for (int i = 1; i < n; i++) {
            if (mp.find(flavours[i]) == mp.end()) {
                mp.insert(make_pair(flavours[i], 1));
                track.push_back(i);
                count++;
                cout << "count: " << count << "\n";
            }
            if (count == k) {
                if ((track.back() - start) > max) {
                    max = track.back() - start;
                    cout << "max: " << max << "\n";
                }
                step++;
                start = track[step];
                count--;
                cout << "step: " << step << "\n";
                cout << "start: " << start << "\n";
                cout << "count--: " << count << "\n";
            } else if (i == (n - 1)){
                max = ((n - start) > max) ? (n - start) : max;
                cout << "max_end: " << max << "\n";
            } 
        }
        cout << max << "\n";
    }
    return 0;
}