#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bfs_to_map_parents(TreeNode *root, map<TreeNode*, TreeNode*> &mp, int start) {
    queue<TreeNode*> qu;
    qu.push(root);
    TreeNode *res;

    while (!qu.empty()) {
        TreeNode *cu = qu.front();
        qu.pop();
        if (cu -> val == start) {
            res = cu;
        }
        if (cu -> left) {
            mp[cu -> left] = cu;
            qu.push(cu -> left);
        }
        if (cu -> right) {
            mp[cu -> right] = cu;
            qu.push(cu -> right);
        }
    }
    return res;
}

int max_distance (map<TreeNode*, TreeNode*> &mp, TreeNode *target) {
    queue<TreeNode*> qu;
    qu.push(target);
    map<TreeNode*, int> map;
    map[target] = 1;
    int res = 0;

    while(!qu.empty()) {
        int n = qu.size();
        bool isBurn = false;

        for (int i = 0; i < n; i++) {
            TreeNode *cu = qu.front();
            qu.pop();
            if (cu -> left && !map[cu -> left]) {
                map[cu -> left] = isBurn = 1;
                qu.push(cu -> left);
            }
            if (cu -> right && !map[cu -> right]) {
                map[cu -> right] = isBurn = 1;
                qu.push(cu -> right);
            }
            if (mp[cu] && !map[mp[cu]]) {
                map[mp[cu]] = isBurn = 1;
                qu.push(mp[cu]);
            }
        }
        if (isBurn) {
            res++;
        }
    }
    return res;
}

int main () {
    /*
             2
            / \
           1   4
          /   / \
         6  10   5
        / \     / \
       3   7   8   9
    */
   
    TreeNode *root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(4);
    root -> left -> left = new TreeNode(6);
    root -> left -> left -> left = new TreeNode(3);
    root -> left -> left -> right = new TreeNode(7);
    root -> right -> left = new TreeNode(10);
    root -> right -> right = new TreeNode(5);
    root -> right -> right -> left = new TreeNode(8);
    root -> right -> right -> right = new TreeNode(9);

    map<TreeNode*, TreeNode*> mp;

    TreeNode *target = bfs_to_map_parents(root, mp, 10);
    int re =max_distance(mp, target);

    cout << "\nTime to burn the tree: " << re << "\n\n";

    // for (auto x : mp) {
    //     cout << x.first -> val << " " << x.second -> val <<" \n";
    // }

    return 0;
}