#include<iostream>
#include<stack>
#include<vector>
#define mod 1000000007
using namespace std;

// int main () {
//     vector<int> chefs;
//     int chef, seniority, x, min, fear = 0;
    
//     cin >> chef >> seniority;
//     for (int i = 0; i < chef; i++) {
//         cin >> x;
//         chefs.push_back(x);
//     }
//     min = chef - 1;
//     for (int i = (chef - 2); i >= 0; i--) {
//         if (chefs[i] > chefs[min]) {
//             fear += (min - i) + 1;
//             cout << (min - i) + 1;
//         }
//         if (chefs[i] <= chefs[min]) {
//             min = i;
//         }
//     }
//     cout << fear % mod << "\n";
//     return 0;
// }

int main () {
    vector<int> chefs;
    stack<pair<int, int>> st, tm;
    int chef, seniority, x, min, fear = 1, flag = 0;

    cin >> chef >> seniority;

    for (int i = 0; i < chef; i++) {
        cin >> x;
        chefs.push_back(x);
    }

    for (int i = (chef - 1); i >= 0; i --) {
        int next = chefs[i];

        if (st.empty()) {
            st.push({next, i});
            continue;
        }
        while (!st.empty()) {
            if (next <= st.top().first) {
                tm.push(st.top());
                st.pop();
            } else if (next > st.top().first) {
                min = st.top().second;
                flag = 1;
                while (!tm.empty()) {
                    st.push(tm.top());
                    tm.pop();
                }
                break;
            }
            if (st.empty()) {
               while (!tm.empty()) {
                    st.push(tm.top());
                    tm.pop();
                }
                break; 
            }
        }
        st.push({next, i});
        if (flag == 1) {
            //cout << next << " " << chefs[min] << endl;
            fear *= (min - i) + 1;
            //cout << "min: " << min << " i: " << i << " min - i: " << min - i << endl;
            //cout << fear << "\n";
            flag = 0;
        }
    }
    cout << fear << "\n";
}

/*
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main () {
    vector<int> chefs;
    stack<pair<int, int>> st;
    int chef, seniority, x, min, fear = 1, flag = 0;

    cin >> chef >> seniority;

    for (int i = 0; i < chef; i++) {
        cin >> x;
        chefs.push_back(x);
    }

    for (int i = (chef - 1); i >= 0; i --) {
        int next = chefs[i];

        if (st.empty()) {
            st.push({next, i});
            continue;
        }
        while (!st.empty() && next > st.top().first) {
            min = st.top().second;
            flag = 1;
            st.pop();
        }
        st.push({next, i});
        if (flag == 1) {
            fear *= ((min - i) + 1) % mod;
            flag = 0;
        }
    }
    cout << fear;
}
*/