#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	int tests;
	
	cin >> tests;
	
	while(tests--) {
	    string s;
	    int le, mid, second, flag = 0;
	    unordered_map<char, int> one, two;
	    
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    getline(cin, s);
	    le = s.size();
	    
	    if (le % 2 == 0) {
	       mid = le / 2;
	       second = (le / 2) + 1;
	    } else {
	        mid = le / 2;
	        second = (le / 2) + 2;
	    }
	    
	    for (int i = 0; i < mid; i++) {
	        if (one.find(s[i]) == one.end()) {
	            one.insert(make_pair(s[i], 1));
	        } else {
	            one[s[i]]++;
	        }
	    }
	    
	    for (int i = second - 1; i < s.size(); i++) {
	        if (two.find(s[i]) == two.end()) {
	            two.insert(make_pair(s[i], 1));
	        } else {
	            two[s[i]]++;
	        }
	    }
	    
	    for (auto x : one) {
	        if (x.second != two[x.first]) {
	            flag = 1;
	            break;
	        }
	    }
	    
	    if (flag == 0) {
	        cout << "YES" << "\n";
	    } else {
	        cout << "NO" << "\n";
	    }
	    
	}
	return 0;
}
