/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include<iostream>
#include<vector>
#define null 0
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = null;
    }
};

class Solution
{
    vector<int> v; 
    public:
    void inorder(Node *root) {
        if (root == NULL) return;
        
        inorder(root -> left);
        v.push_back(root -> data);
        inorder(root -> right);
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        inorder(root);
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] >= v[i+1]) {
                return false;
            }
        }
        return true;
    }
};