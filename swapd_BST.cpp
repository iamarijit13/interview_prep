#include<iostream>
#include<vector>
using namespace std;

int main() {

}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 int x,y;
 vector<int> g(2);
 void fun(TreeNode* A)
 {
     if(A==nullptr)
     return;
     if(A->left)
     fun(A->left);
     if(y==0)
     {
     if(x>A->val)
     {
     g[1]=x;
     y=1;
     g[0]=A->val;
     }
     x=A->val;
     }
     else
     {
         if(g[1]>A->val)
         g[0]=A->val;
     }
     if(A->right)
     fun(A->right);
 }
vector<int> recoverTree(TreeNode* A) {
    x=INT_MIN;
    y=0;
    fun(A);
    return g;
}