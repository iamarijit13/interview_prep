#include<iostream>
#include <sstream>
using namespace std;

int to_int(string a) {
    int re = 0;
    // for (int i = 0; i < a.size(); i++) {
    //     re *= 10 + int(a[i]);
    // }
    stringstream ob(a);

    ob >> re;
    cout << re << "\n\n";
    return re;
}

int pow_of_two(string A) {
    int r = to_int(A);
    if (r == 0) return 0;

    while (r != 1) {
        if (r % 2 == 1) return 0;

        r /= 2;
    }
}

int main() {
    string a = "123";

    int re = pow_of_two(a);

    if (re == 1) cout << "true";
    else cout << "false";

    return 0;
}

// bool check0str(string a){
//     int n = a.size();
//     for(int i=0; i<n-1; i++)
//     if(a[i] != '0') return false;
//     if(a[n-1] == '1') return true;
//     return false;
// }

// int Solution::power(string a) {
//     int n = a.size();
    
//     int j=0;
//     while(a[j] == '0') j++; 
//     if(n-j == 1 & a[0] == '1') return 0;
    
//     while(!check0str(a)){
        
//         if((a[n-1] - '0')%2 == 1) return 0;
        
//         int carry = 0;
//         string temp = "";
//         for(int i=0; i<n; i++){
//             temp.push_back('0' + carry+(a[i] - '0')/2);
//             carry = (a[i] - '0')%2 == 1 ? 5: 0;
//         }
//         a = temp;
//     }
//     return 1;
// }
