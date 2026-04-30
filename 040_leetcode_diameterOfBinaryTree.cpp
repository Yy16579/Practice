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
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int L = depth((root)->left);
        int R = depth((root)->right);
        ans = max(ans, L+R+1);

        return max(L,R) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        int L = depth(root->left);      //递归计算左子树的深度
        int R = depth(root->right);     //递归计算右子树的深度
        ans = max(ans, L+R+1);          //计算该节点最长路径，更新ans最大值

        return ans - 1;
    }
private:
    int ans;
};

int main(){


    return 0;
}