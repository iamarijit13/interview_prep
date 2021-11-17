#include<iostream>
using namespace std;

int calc_time(string, string);

int main () {
    int tests;

    cin >> tests;

    while (tests--) {
        string keyboard, word;
        int re;

        getline(cin, keyboard);
        getline(cin, word);

        re = calc_time(keyboard, word);

        cout << re;
    }

    return 0;
}

int clac_time(string key, string word) {

}

int find_index(string keyboard, string key) {
    if ()
}