#include<iostream>
using namespace std;

string convert_to_roman(int);

int main () {
    int number;
    string result;

    cout << "\nEnter a number: ";
    cin >> number;

    result = convert_to_roman(number);

    cout << "\nRoman numeric of " << number << ": " << result << "\n\n";

    return 0;
}

string convert_to_roman(int number) {
    int num[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    string sym[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int i = 12;
    string re;

    while(number > 0) {
      int div = number / num[i];
      number = number % num[i];
      while (div--) {
        re += sym[i];
      }
      i--;
    }
    return re;
}