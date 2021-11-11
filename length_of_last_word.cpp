#include<iostream>
using namespace std;

int length_of_last_word(string);
string remove_spaces(const string&);

int main () {
    string sentence;
    int re;

    cout << "\nEnter the sentence: ";
    getline(cin, sentence);

    re = length_of_last_word(sentence);

    cout << "\nLength of the las word is: " << re << "\n";
}

int length_of_last_word(string sen) {

    string sentence = remove_spaces(sen);

    int len = 0;

    for (int i = 0; i < sentence.size(); i++) {
        len++;
        if (sentence[i] == ' ') {
            len = 0;
        }
    }
    return len;
}

string remove_spaces(const string &s)
{
  int last = s.size() - 1;
  while (last >= 0 && s[last] == ' ')
    --last;
  return s.substr(0, last + 1);
}