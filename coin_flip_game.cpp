#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main () {
    ll int tests;

    cin >> tests;

    while (tests--) {
        ll int g;

        cin >> g;

        while (g--) {
            ll int a, b, c, heads, tails;

            cin >> a >> b >> c;

            if (a == 1) {
                if (b % 2 != 0){
                    heads = b / 2;
                    tails = (b / 2) + 1;
                } else {
                    heads = b / 2;
                    tails = b / 2;
                }
            } else if (a == 2) {
                if (b % 2 != 0){
                    heads = (b / 2) + 1;
                    tails = b / 2;
                } else {
                    heads = b / 2;
                    tails = b / 2;
                }
            }

            if (c == 1) {
                cout << heads;
            } else {
                cout << tails;
            }
        }
    }
}