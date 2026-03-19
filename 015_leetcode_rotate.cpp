#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0 ; i<nums.size()/2 ; i++){
            swap(nums[i] , nums[nums.size()-i-1]);
        }

        k %= nums.size();
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());
        return;
    }
};

int main(){
    //测试数据
    vector<int> nums = {1,2,3,4,5,6,7}; 
    int k = 3;
    Solution s;
    s.rotate(nums , k);
    for(int& i : nums){
        cout << i << "  ";
    }

    return 0;
}