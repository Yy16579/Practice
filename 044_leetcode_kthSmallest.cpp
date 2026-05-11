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
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        if(K == 0){
            return;
        }
        K--;
        if(K == 0){
            ans = root->val;
            return;
        }
        dfs(root->right);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        K = k;
        dfs(root);
        return ans;
    }

private:
    int K;
    int ans;
};

int main(){


    return 0;
}