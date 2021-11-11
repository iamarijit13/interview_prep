#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> >);

int main () {
    vector<int> one = {1, 2};
    vector<int> two = {3, 4};
    vector<int> three = {4, 5};

    vector<vector<int>> matrix = {one, two, three};

    //rotate(matrix);

    cout << matrix.size();

    return 0;
}

void rotate(vector<vector<int> > &matrix) {

    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[len - j - 1][i];
            matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
            matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
            matrix[j][len - i - 1] = tmp;
        }
    }
}