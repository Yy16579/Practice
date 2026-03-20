#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        
        //将后缀相乘的结果存放到ans中，不增加额外空间开销
        ans[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2 ; i>=0 ; i--){
            ans[i] = nums[i] * ans[i+1]; 
        }

        //前缀相乘的结果放到L中，空间复杂度O(1)
        int L = 1;

        for(int i=0 ; i<nums.size()-1 ; i++){
            ans[i] = L * ans[i+1];
            L *= nums[i];
        }
        ans[nums.size()-1] = L;
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> nums = {1,2,3,4};
    vector<int> ans;      
    Solution s;             
    ans = s.productExceptSelf(nums);
    for(int& i : ans){
        cout << i << "  ";
    }

    return 0;
}