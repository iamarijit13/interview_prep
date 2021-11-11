#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder(TreeNode *A) {
    if (A == NULL) return vector<int>();

    stack<TreeNode*> st;
    vector<int> result;
    TreeNode *te;

    st.push(A);

    while(!st.empty()) {
        te = st.top();
        st.pop();
        result.push_back(te -> val);

        if (te -> right) {
            te = te -> right;
        } 
        if(te -> left) {
            te = te -> left;
        }
    }

    return result;
}