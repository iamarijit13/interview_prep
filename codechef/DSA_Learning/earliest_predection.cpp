#include<iostream>
#include <sstream>
#define ll long long
using namespace std;

int main () {
    ll int tests;

    cin >> tests;

    while (tests--) {
        ll int n, teamA = 0, teamB = 0, early = 0;
        string s;

        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin, s);

        for (int i = 0; i < (2 * n); i++) {
            //cout << "Early: " << early << "\n";
            early++;
            int goal = s[i] - '0';
            if ((i + 3) % 2 != 0) {
                teamA += goal;
            } else {
                teamB += goal;
            }

            if (((i + 3) % 2 == 0) && abs(teamA - teamB) > (((2 * n) - i) / 2)) {
                break;
            }
        }

        cout << early << "\n";
    }

    return 0;
}