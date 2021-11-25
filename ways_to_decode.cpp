#include<iostream>
#include<map>
#include<vector>
using namespace std;

int decode(string, map<string, int>&, int);

int main () {
    string st = "12";
    int re;
    map<string, int> memo;
    //getline(cin, st);

    re = decode(st, memo, 0);

    cout << "\nWays to Decode: " << re << "\n\n";

    return 0;
}

int decode(string st, map<string, int> &memo, int ind) {
    if (ind < st.size() && st[ind] == '0') return 0;

    if (ind >= st.size() - 1) return 1;

    string key = st.substr(ind);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int ch1 = decode(st, memo, ind + 1);

    int combined = (st[ind] - 48) * 10 + (st[ind + 1] - 48);

    int ch2 = 0;

    if (combined <= 26)
        ch2 = decode(st, memo, ind + 2); 

    memo[key] = ch1 + ch2;
    return memo[key];
}


