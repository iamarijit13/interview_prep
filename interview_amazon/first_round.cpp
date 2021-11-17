/**
Q. Consider a 2-D map with a horizontal river passing through its center.
There are n cities on the northern bank with x-coordinates a(1) … a(n) and n cities on the southern bank
with x-coordinates b(1) … b(n). You want to connect as many north-south pairs of cities as possible with
bridges such that no two bridges cross. When connecting cities, you can only connect city a(i) on the
northern bank to city b(i) on the southern bank. Find maximum number of bridges that can be built to connect
north-south pairs with the aforementioned constraints.

Ex- Input :
        n = 4
        6 4 2 1
        2 3 6 5

    Output :
        2
Explanation:
        Bridge - (2,6) and (1,5) can be built

        Nothern  = 1 2 3 4 5 6
                    \ \
                     \ \
                      \ \
                       \ \
                        \ \
                         \ \
                          \ \
        Southern = 1 2 3 4 5 6
        
        6 -> 2
        
        6 8 10 2 8
        2 3 5 6 7 
**/        


#include<iostream>
#include<vector>
using namespace std;

int lis(vector<pair<int, int>> cities) {
    vector<int> store(cities.size());
    
    store[0] = 1;
    
    for (int i = 1; i < cities.size(); i++) {
        store[i] = 1;
        for (int j = 0; j < i; j++) {
            if (cities[i].second > cities[j].second && store[j] + 1 > store[i]) {
                store[i] = store[j] + 1;
            }
        }
    }
    
    return *max_element(store.begin(), store.end());
}


int main () {
    int n = 4;
    vector<int> northen_cities(n), southern_cities(n);
    
    for ( int i = 0; i < n; i++) {
        int x;
        cin >> x;
        northen_cities.push_back(x);
    }
    
    for ( int i = 0; i < n; i++) {
        int x;
        cin >> x;
        southern_cities.push_back(x);
    }
    
    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++) {
        cities.push_back(make_pair(northen_cities[i], southern_cities[i]));
    }
    
    sort(cities.begin(), cities.end());
    
    int sq = lis(cities);

    cout << "Possible Bridges: " << sq << " \n";
    
    return 0;
}

