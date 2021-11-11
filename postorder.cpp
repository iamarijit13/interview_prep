#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
pre-order traversal is root-left-right, and post order is left-right-root. modify the code for pre-order to make it root-right-left, and then reverse the output so that we can get left-right-root .

Create an empty stack, Push root node to the stack.
Do following while stack is not empty.

2.1. pop an item from the stack and print it.

2.2. push the left child of popped item to stack.

2.3. push the right child of popped item to stack.

reverse the ouput.
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode*> nodeStack;
    vector<int> result;
    //base case
    if(root==NULL)
        return result;
    nodeStack.push(root);
    while(!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();  
        result.push_back(node->val);
        nodeStack.pop();
        if(node->left)
            nodeStack.push(node->left);
        if(node->right)
            nodeStack.push(node->right);
    }
    reverse(result.begin(),result.end());
    return result;
}

vector<int> postorderTraversal(TreeNode* A) {
    if (A == NULL) return vector<int>();

    TreeNode *t;
    stack<TreeNode*> st, re;
    vector<int> result;

    st.push(A);

    while (!st.empty()) {
        t = st.top();
        st.pop();
        re.push(t);

        if (t -> left) {
            st.push(t -> left);
        }

        if (t -> right) {
            st.push(t -> right);
        }
    }

    while (!re.empty()) {
        result.push_back(re.top() -> val);
        re.pop();
    }

    return result;
}
