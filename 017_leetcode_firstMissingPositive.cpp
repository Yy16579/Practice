#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            while(nums[i] != i+1){
                if(nums[i]<=0 || nums[i]>nums.size()){
                    break;
                }
                if(nums[nums[i]-1] != nums[i]){
                    swap(nums[nums[i]-1] , nums[i]);
                }else{
                    break;
                }
            }
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(){
    //测试数据
    vector<int> nums = {3,4,-1,1};
    Solution s;
    cout << s.firstMissingPositive(nums);

    return 0;
}