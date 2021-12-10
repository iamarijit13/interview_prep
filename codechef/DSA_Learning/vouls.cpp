#include<iostream>
#include<unordered_map>
#include<vector>
#define ll long long int
using namespace std;

int main () {
    string st, re;
    unordered_map<char, int> mp;
    ll count = 0;

    getline(cin, st);

    for (int i = 0; i < st.size(); i++) {
        if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u' || st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U') {
            re += toupper(st[i]);
            if (mp.find(toupper(st[i])) == mp.end()) {
                mp.insert({toupper(st[i]), 1});
            } else {
                mp[toupper(st[i])]++;
            }
            count++;
            continue;
        }
        re += tolower(st[i]);
    }

    cout << re << endl;
    cout << count << endl;
    for (auto x : mp) {
        cout << "Count of '"  << x.first << "' - " << x.second <<endl; 
    }
    return 0;
}
