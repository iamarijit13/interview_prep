#include<iostream>
#include<map>
using namespace std;

int convert_to_int(string);

int main () {
    string roman;
    int re;

    cout << "\nEnter roman number: ";
    getline(cin, roman);

    re = convert_to_int(roman);

    cout << "\nEquvalent Decimal of Roman Numeric, " << roman << " is: " << re << "\n\n";

    return 0;
}

int convert_to_int(string roman) {
    map<char, int> m;
    int re = 0;

    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });

    for (int i = 0; i < roman.size(); i++) {
        if (m[roman[i]] < m[roman[i + 1]]) {
            re += m[roman[i + 1]] - m[roman[i]];
            i++;
            continue;
        }
        re += m[roman[i]];
    }

    return re;
}