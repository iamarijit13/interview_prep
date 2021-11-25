#include<iostream>
#include<string>
#include<vector>
#include <iostream>
#include <sstream>
#include<vector>
using namespace std;

string remove_spaces(const string &s)
{
  int last = s.size() - 1;
  while (last >= 0 && s[last] == ' ')
    --last;
  return s.substr(0, last + 1);
}

string solve(string A) {
    istringstream ss(A);
    vector<string> ve;
  
    string word, ex = "";

    while (ss >> word) {
        ve.push_back(word);
    }

    reverse(ve.begin(), ve.end());

    for (auto x : ve) {
        ex += x + " ";
    }

    return remove_spaces(ex);
}

int main () {
    string s = "i am arijit";

    cout << solve(s) << "\n\n";

    return 0;
}
