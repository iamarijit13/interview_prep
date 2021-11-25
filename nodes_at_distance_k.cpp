#include<iostream>
#include<unordered_map>
#define null 0
using namespace std;

class tree {
    public: 
        int data;
        tree *left, *right;

    public: 
        tree(int dt) {
            this -> data = dt;
            this -> left = this -> right = null;
        }

        void print(tree*);
        void inorder(tree*);
};

void tree :: print(tree *root) {
    tree *te = root;

    while (te) {

    }
}

void tree :: inorder(tree *root) {
    if (root == null) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main () {
    tree ob(0);

    tree *root = new tree(1);
    root -> left = new tree(2);
    root -> right = new tree(3);
    root -> left -> left = new tree(4) ;
    root -> left -> right = new tree(5);
    root -> left -> left -> left = new tree(6);
    root -> left -> left -> right = new tree(7);

    ob.inorder(root);

    return 0;
}

