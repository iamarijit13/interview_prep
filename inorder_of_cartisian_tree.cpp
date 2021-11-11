#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder_recursive(TreeNode *head, vector<int> &re) {
    if (head == NULL) return;
    
    inorder_recursive(head -> left, re);
    re.push_back(head -> val);
    inorder_recursive(head -> right, re);
}

void preorder_recursive(TreeNode *head, vector<int> &re) {
    if (head == NULL) return;
    
    re.push_back(head -> val);
    inorder_recursive(head -> left, re);
    inorder_recursive(head -> right, re);
}

void postorder_recursive(TreeNode *head, vector<int> &re) {
    if (head == NULL) return;
    
    inorder_recursive(head -> left, re);
    inorder_recursive(head -> right, re);
    re.push_back(head -> val);
}

// vector<int> zigzag(TreeNode *head) {
//     int direction = 1;
//     TreeNode *te;
//     queue<TreeNode*> st;
//     vector<int> re;

//     st.push(head);

//     while (!st.empty()) {
//         te = st.front();
//         re.push_back(te -> val);
//         st.pop();
        
//         if (direction == 1 && te != NULL) {
//             if (te -> right)
//                 st.push(te -> right);
//             if (te -> left)
//                 st.push(te -> left);
//             direction = 0;
//         }
        
//         if (direction == 0 && te != NULL) {
//             if (te -> left)
//                 st.push(te -> left);
//             if (te -> right)
//                 st.push(te -> right);
//             direction = 1;
//         }
        
//     }
    
//     return re;
// }

vector<vector<int>> zigzag(TreeNode *head) {
    TreeNode *te;
    queue<TreeNode*> qu;
    int level = 1;
    vector<vector<int>> result;

    qu.push(head);

    while (!qu.empty()) {
        vector<int> re;
        int n = qu.size();

        for (int i = 0; i < n; i++) {
            te = qu.front();
            qu.pop();
            re.push_back(te -> val);

            if (te -> left) {
                qu.push(te -> left);
            } 
            if (te -> right) {
                qu.push(te -> right);
            }
        }
        
        if (level % 2 == 0) {
            reverse(re.begin(), re.end());
        }
        level++;
        result.push_back(re);
    }
    return result;
}

void print(TreeNode *head) {
    stack<TreeNode*> st;
    TreeNode *te = head;

    cout << "\n Inorder Traversal: ";
    
    while (te != NULL || st.empty() == false) {
        while (te != NULL) {
            st.push(te);
            te = te -> left;
        }

        te = st.top();
        cout << st.top() -> val << " ";
        st.pop();
        te = te -> right;
    }
}

TreeNode* buildTrees(vector<int> &inorder, int start, int end) {
    if (start == end) {
        return new TreeNode(inorder[start]);
    }
    if (start > end) return NULL;

    // find max which will be the root. 
    int maxVal = INT_MIN, maxIndex = -1;
    for (int i = start; i <= end; i++) {
        if (inorder[i] > maxVal) {
            maxVal = inorder[i];
            maxIndex = i;
        }
    }

    TreeNode *root = new TreeNode(maxVal);
    root->left = buildTrees(inorder, start, maxIndex - 1);
    root->right = buildTrees(inorder, maxIndex + 1, end);
    return root;
}

TreeNode* buildTree(vector<int> &inorder) {
    if (inorder.size() == 0) return NULL;
    return buildTrees(inorder, 0, inorder.size() - 1);
}

int main() {
    // vector<int> inorder = {1, 2, 3};
    
    // TreeNode *re = buildTree(inorder);
    // print(re);

    // vector<int> result;
    // inorder_recursive(re, result);

    // cout << "\nInorder Traversal: ";
    // for (auto x : result) {
    //     cout << x << " ";
    // }

    // result.clear();

    // preorder_recursive(re, result);

    // cout << "\nPreorder Traversal: ";
    // for (auto x : result) {
    //     cout << x << " ";
    // }

    // result.clear();

    // postorder_recursive(re, result);

    // cout << "\nPostorder Traversal: ";
    // for (auto x : result) {
    //     cout << x << " ";
    // }

    // result.clear();

    TreeNode *tr;

    vector<vector<int>> result;

    tr = new TreeNode(3);
    tr -> left = new TreeNode(9);
    tr -> right = new TreeNode(20);
    tr -> right -> left = new TreeNode(15);
    tr -> right -> right = new TreeNode(7);

    result = zigzag(tr);

    cout << "\nPostorder Traversal: ";
    for (auto x : result) {
        for (auto y : x) {
            cout << y << " ";
        }
    }

    return 0;
}
