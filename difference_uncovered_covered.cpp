#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long coveredNodes(TreeNode* A) {
    if (A == NULL) return 0;
    TreeNode *te;
    queue<TreeNode*> qu;
    long unc = 0, cov = 0;
    
    qu.push(A);

    while (!qu.empty()) {
        int n = qu.size();

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == (n - 1)) {
                unc += qu.front() -> val;
                te = qu.front();
                qu.pop();
            } else {
                cov += qu.front() -> val;
                te = qu.front();
                qu.pop();
            }

            if (te -> left) {
                qu.push(te -> left);
            }
            if (te -> right) {
                qu.push(te -> right);
            }
        }
    }

    return abs(unc - cov);
    
}

int main () {

    /*
             2
            / \
           1   4
          /   / \
         6  10   5
    */
   
    TreeNode *root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(4);
    root -> left -> left = new TreeNode(6);
    root -> right -> left = new TreeNode(10);
    root -> right -> right = new TreeNode(5);

    long re = coveredNodes(root);

    cout << "\n\nDifference between uncovered and covered nodes: " << re << "\n\n";

    return 0;
}
