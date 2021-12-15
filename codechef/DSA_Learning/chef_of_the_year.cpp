#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#define ll long long int
using namespace std;

// bool cmp(pair<string, int>& a, pair<string, int>& b) {
//     return a.second > b.second;
// }
bool my_compare(string a, string b) {
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
 
        return a.size() > b.size();
 
    // Else return lexicographically
    // smallest string
    else
        return a < b;
}

int main () {
    int n, m, max;
    string input, word1, word2;
    //vector<pair<string, string>> chefs_countries;
    //vector<string> mail;
    vector<string> chef, country;
    unordered_map<string, string> chefs_countries;
    unordered_map<string, int> track;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin >> ws, input);
        istringstream ss(input);
        ss >> word1;
        ss >> word2;
        if (chefs_countries.find(word1) == chefs_countries.end()) {
            chefs_countries.insert({word1, word2});
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> input;
        //mail.push_back(input);
        if (track.find(input) == track.end()) {
            track.insert({input, 1});
        } else {
            track[input]++;
        }
    }

    //sort(track.begin(), track.end(), cmp);
    max = track.begin() -> second;

    for (auto x : track) {
        if (x.second > max) {
            max = x.second;
        }
    }
    for (auto x : track) {
        if (x.second == max) {
            chef.push_back(x.first);
            country.push_back(chefs_countries[x.first]);
        }
    }

    // if(lexicographical_compare(chef.begin(), chef.end()) {
    //     cout << "geeksforgeeks is lexicographically less than Gfg\n";     
    // } else {
    //     cout << "geeksforgeeks is not lexicographically less than Gfg\n";
          
    // }

    // for (auto x : chef) {

    // }

    // cout << "\n\nChefs: \n";
    // for (auto x : chef) {
    //     cout << x << "\n";
    // }

    // cout << "\n\nCountry: \n";
    // for (auto x : country) {
    //     cout << x << "\n";
    // }

    sort(chef.begin(), chef.end(), my_compare);
    sort(country.begin(), country.end(), my_compare);

    cout << "\n\n";
    cout << *country.begin() << "\n" << *chef.begin() << "\n";

    return 0;
}