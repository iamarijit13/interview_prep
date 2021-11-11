#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* A) {
    //if (A == NULL) return NULL;

    TreeNode *t = A;
    stack<TreeNode*> st;
    vector<int> re;

    while (t != NULL || st.empty() == false) {
        while (t != NULL){
            st.push(t);
            t = t -> left;
        }

        // if (t == NULL && !st.empty() == false) {
        //     t = st.top();
        //     re.push_back(t -> val);
        //     st.pop();
        //     t = t -> right;
        // }
        t = st.top();
        re.push_back(t -> val);
        st.pop();
        t = t -> right;
    }

    return re;

}

vector<int> inorder_recursive(TreeNode *head, vector<int> &re) {
    if (head == NULL) return;

    inorder_recursive(head -> left, re);
    re.push_back(head -> val);
    inorder_recursive(head -> right, re);

    return re;
}

// Algorithm 

/*
    1. Initialize a stack of type TreeNode pointer.
    2. Traverse the left sub tree until NULL reaches.
    3. Push every treeNode to the stack.
    4. repeate step 1 to 3 until false.
    5. pop stack top, initialize it to the traversing pointer.
    6. print stack top value.
    7. pop the TreeNode from stack.
    8. point the traversing pointer to the right of its current position.
*/