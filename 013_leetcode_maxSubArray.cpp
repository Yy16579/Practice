#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int& n : nums){
            sum = max(n , sum+n);
            ans = max(ans , sum);
        }
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums);

    return 0;
}