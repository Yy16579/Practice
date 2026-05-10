#include<iostream>
#include<vector>


using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, long long lower, long long upper){     //参数为二叉节点最小最大边界值
        if(root == nullptr){
            return true;
        }
        if(root->val <= lower || root->val >= upper){
            return false;
        }
        
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }
               
    bool isValidBST(TreeNode* root) {
        return dfs(root->left, LONG_LONG_MIN, root->val) && dfs(root->right, root->val, LONG_LONG_MAX);
    }
};

int main(){


    return 0;
}