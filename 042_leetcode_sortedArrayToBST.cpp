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
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid-1);
        root->right = dfs(nums, mid+1, r);
        return root;
    }
    // -10 -3 0 5 9         mid = 2  mid = 0
    //  0   1 2 3 4
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};

int main(){


    return 0;
}