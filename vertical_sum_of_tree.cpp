#include<iostream>
#include<map>
#include<vector>
#define null 0
using namespace std;

class tree {
    public:
        int data;
        tree *left, *right;

        tree(int dt = 0) {
            this -> data = dt;
            this -> left = this -> right = null;
        }

        void vertical_sum(tree*, map<int, int>&, int);
        void print(vector<int>);
        void inorder(tree*);
};

void tree :: vertical_sum(tree* root, map<int, int> &mp, int hd) {
    if (root == null) return;

    vertical_sum(root -> left, mp, hd - 1);
    mp[hd] += root -> data;
    vertical_sum(root -> left, mp, hd + 1);
}

void tree :: print(vector<int> re) {
    cout << "\nVertical Sum: ";
    for (auto x : re) {
        cout << x << " ";
    }
}

void tree :: inorder(tree *root) {
    if (root == null) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main () {
    tree object;
    map<int, int> mp;
    vector<int> re;

/*
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
Giving wrong output.
*/

    tree *root = new tree(1);
    root -> left = new tree(2);
    root -> right = new tree(3);
    root -> left -> left = new tree(4) ;
    root -> left -> right = new tree(5);
    root -> right -> left = new tree(6);
    root -> right -> right = new tree(7);

    cout << "\nInorder traversal: ";
    object.inorder(root);
    object.vertical_sum(root, mp, 0);

    for (auto x : mp) {
        re.push_back(x.second);
    }

    object.print(re);

    return 0;
}