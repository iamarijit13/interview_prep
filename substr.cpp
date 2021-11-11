#include<iostream>
using namespace std;

int sub_string(string, string);

int main () {
    string a, b;
    int re;

    cout << "\nEnter string-1: ";
    getline(cin, a);

    cout << "\nEnter string-2: ";
    getline(cin, b);

    re = sub_string(a, b);

    cout << "\nResult: " << re << "\n";

    return 0;
}

int sub_string(const string a, const string b) {
    int start = 0, t_start = start, j = 0;

    while (t_start < a.size() && j < b.size()) {
        if (a[t_start] == b[j]) {
            t_start++;
            j++;
        } else {
            j = 0;
            t_start = ++start;
        }
        if (j == b.size()) {
            return start;
        }
    }
    return -1;
}