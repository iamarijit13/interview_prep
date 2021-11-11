#include<iostream>
#include<unordered_map>
using namespace std;

int maximum_partition(string str) {
    int i = 0, j = 0, k = 0, c = 0, r = 0;
    unordered_map<char, int> m;

    for (i = str.length() - 1; i >= 0; i--) {
       if (m[str[i]] == 0) {
           m[str[i]] = i;
       }
    }

    for (auto x : m) {
        cout << x.first << " " << x.second << "\n";
    }

    return r;
}

int main () {
    string str = "ababcbacadefegdehijhklij";
    cout << maximum_partition(str);

    return 0;
}