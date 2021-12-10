#include<iostream>
#include<vector>
using namespace std;

void print_sprial(vector<vector<int>>, int, int);

int main () {
    vector<int> v1= {1, 2, 3};
    vector<int> v2= {4, 5, 6};
    vector<int> v3= {7, 8, 9};

    vector<vector<int>> matrix = {v1, v2, v3};

    print_sprial(matrix, 0, 2);

    return 0;
}

void print_sprial(vector<vector<int>> matrix, int start, int end) {
    int direction = 1, min = start, max = end, row = 0, column = 0, layer = 0;

    for (int i = 0; i < 9; i++) {
        switch(direction) {
            case 1: {
                if (column > max) {
                    min++;
                    direction = 2;
                } else {
                    column++;
                }
                cout << matrix[row][column];
                break;
            }

            case 2: {
                if (row > max) {
                    max--;
                    direction = 3;
                } else {
                    row++;
                }
                cout << matrix[row][column];
                break;
            }

            case 3: {
                if (column < min) {
                    min++;
                    direction = 4;
                } else {
                    column--;
                }
                cout << matrix[row][column];
                break;
            }

            case 4: {
                if (row < min) {
                    max--;
                    direction = 1;
                } else {
                    row--;
                }
                cout << matrix[row][column];
                break;
            }
        }
    }
}
//URI=mongodb+srv://arijit:arijit%4012345@dynamicformgenerator.xjnu8.mongodb.net/test

/*class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int> > &matrix) {
        int rows = matrix.size();
        if (rows == 0) return vector<int> ();
        int cols = matrix[0].size();
        int row = 0, col = 0, layer = 0;
        vector<int> res;
        res.push_back(matrix[0][0]);
        int dir = 1;
        for (int step = 1; step < rows * cols; step++) {
            switch(dir) { // based on dir, check and change dir, then move on
            case 1: // supposed to go right
                if (col == cols - layer - 1) { // reach right bound
                    row++;
                    dir = 2;
                }
                else col++;
                break;
            case 2: // supposed to go down
                if (row == rows - layer - 1) { // reach downside bound
                    col--;
                    dir = 3;
                }
                else row++;
                break;
            case 3: // supposed to go left
                if (col == layer) { // reach left bound
                    row--;
                    dir = 4;
                }
                else col--;
                break;
            case 4: // supposed to go up
                if (row == layer + 1) { // reach upside bound
                    col++;
                    dir = 1;
                    layer++;
                }
                else row--;
                break;
            }
            res.push_back(matrix[row][col]);
        }
        return res;
    }
};*/