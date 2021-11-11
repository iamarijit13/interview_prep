#include<iostream>
using namespace std;

int my_atoi(string);

int main () {
    string number;
    int res;

    cout << "\nEnter a string: ";
    getline(cin, number);

    res = my_atoi(number);

    cout << "ATOI result: " << res << "\n\n";

    return 0;
}

// int my_atoi(string number) {
//     int base = 0, sign = 1, i = 0;

//     while (number[i] == ' ') {
//         i++;
//     }

//     if (number[i] == '-' || number[i] == '+') {
//         sign = 1 - 2 * (number[i++] == '-');
//     }

//     while (number[i] >= '0' && number[i] <= '9') {
//         if (base > INT_MAX / 10 || (base == INT_MAX / 10 && number[i++] - '0' > 7)) {
//             if (sign == 1) {
//                 return INT_MAX;
//             } else {
//                 return INT_MIN;
//             }
//             base = 10 * base + (number[i++] - '0');
//         }
//     }

//     return base * sign;
// }


int my_atoi(string str)
{
    int sign = 1, base = 0, i = 0;
     
    // if whitespaces then ignore.
    while (str[i] == ' ')
    {
        i++;
    }
     
    // sign of number
    if (str[i] == '-' || str[i] == '+')
    {
        sign = 1 - 2 * (str[i++] == '-');
    }
   
    // checking for valid input
    while (str[i] >= '0' && str[i] <= '9')
    {
        // handling overflow test case
        if (base > INT_MAX / 10
            || (base == INT_MAX / 10
            && str[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}