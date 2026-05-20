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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->left != nullptr){
                TreeNode* temp = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;

                //将右节点连接至左节点最右端
                TreeNode* n = cur->right;
                while(n->right != nullptr){
                    n = n->right;
                }
                n->right = temp;
            }

            cur = cur->right;
        }

        return;
    }
};

int main(){


    return 0;
}