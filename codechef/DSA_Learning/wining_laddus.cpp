#include<iostream>
#include<vector>
#include <sstream>
#define ll long long
using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim(const string &s) {
    return rtrim(ltrim(s));
}

int main () {
    int tests;

    cin >> tests;

    while (tests--) {
        int activity;
        ll int laddus = 0, result = 0;
        string origin;
        vector<string> activities;

        cin >> activity;
        getline(cin, origin);

        for (int i = 0; i < activity; i++) {
            string tm;
            getline(cin, tm);
            activities.push_back(tm);
        }

        for (int i = 0; i < activity; i++) {
            string name, split;
            vector<string> values;
            ll int value;
            istringstream ss(activities[i]);
            
            while (ss >> split) {
                values.push_back(split);
            }
            name = values[0];
            if (values.size() > 1) {
                stringstream g(values[1]);
                g >> value;
            }

            if (name == "CONTEST_WON") {
                laddus += 300 + (20 - value);
            } else if (name == "TOP_CONTRIBUTOR") {
                laddus += 300;
            } else if (name == "BUG_FOUND") {
                laddus += value;
            } else if (name == "CONTEST_HOSTED") {
                laddus += 50;
            }
        }
        origin = trim(origin);

        if (origin == "INDIAN") {
            result = laddus / 200;
        } else if (origin == "NON_INDIAN") {
            result = laddus / 400;
        }

        cout << result << "\n";
    }
}