#include<iostream>
#define ll long long
using namespace std;

int main () {
    ll tests;

    cin >> tests;

    while (tests--) {
        ll int k, d0, d1, sum = 0, digit;

        cin >> k >> d0 >> d1;

        k -= 2;
        sum = d0 + d1;

        while (k--) {
            digit = sum % 10;
            sum += digit;
        }

        if (sum % 3 == 0) {
            cout << "YES" << "\n"; 
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main () {
    ll tests;

    cin >> tests;

    while (tests--) {
        ll int k, d0, d1, sum = 0;

        cin >> k >> d0 >> d1;

        long int s = (2 * (d0 + d1)) % 10 +
                (4 * (d0 + d1)) % 10 +
                (8 * (d0 + d1)) % 10 +
                (6 * (d0 + d1)) % 10;
        
        int a = (k - 3) % 4;
        int x;

        switch(a)
        {
            case 0:
                x = 0;
                break;
        
            case 1:
                x = (2 * (d0 + d1)) % 10;
                break;
    
            case 2:
                x = (2 * (d0 + d1)) % 10 +
                    (4 * (d0 + d1)) % 10;
                break;
        
            case 3:
                x = (2 * (d0 + d1)) % 10 +
                    (4 * (d0 + d1)) % 10 +
                    (8 * (d0 + d1)) % 10;
                
                break;
        }
        
        sum = d0 + d1 + ((k - 3) / 4) * s + x;
        
        if (sum % 3 == 0) {
            cout << "YES" << "\n"; 
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}