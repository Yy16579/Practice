#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        //求出前缀和
        vector<int> pre;
        pre.resize(nums.size()+1 , 0);
        for(int i=1 ; i<=nums.size() ; i++){
            pre[i] = pre[i-1] + nums[i-1];
        }

        unordered_map<int , int> map;
        for(int& i : pre){          
            int target = i - k;
            if(map.count(target) == 1){
                ans += map[target];
            }

            map[i]++;
        }
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> nums = {3,4,7,2,-3,1,4,2};
    int k = 7;

    Solution s;
    cout << s.subarraySum(nums , k);

    return 0;
}