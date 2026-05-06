#include<iostream>
#include<vector>
#include<queue>


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sum = q.size();
            vector<int> v;

            while(sum > 0){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                sum--;
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }    
            ans.push_back(v);
        }
        return ans;
    }
};

int main(){


    return 0;
}