#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode* A) {
    if( A -> left == NULL && A -> right == NULL) return A;

    if ( A -> left == NULL) return solve(A -> right);
    if ( A -> right == NULL) return solve(A -> left);

    A -> left = solve(A -> left);
    A -> right = solve(A-> right);

    return A;
}

void inorder(TreeNode *te) {
    if (te == NULL) return;

    inorder(te -> left);
    cout << te -> val << " ";
    inorder(te -> right);
}

int main () {
    TreeNode *tree = new TreeNode(1), *result;
    tree -> left = new TreeNode(2);
    tree -> right = new TreeNode(3);
    tree -> left -> left = new TreeNode(4);
    tree -> left -> right = new TreeNode(5);
    tree -> right -> right = new TreeNode(6);

    result = solve(tree);
    inorder(result);

    return 0;
}