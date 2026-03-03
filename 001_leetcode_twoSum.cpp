#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> ans;
        unordered_map<int , int> map;
        for(int i=0 ; i<nums.size() ; i++){
            unordered_map<int,int>::iterator it = map.find(target-nums[i]);
            if(it != map.end()){
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};

int main(){
    //测试数据
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(11);
    nums.push_back(15);
    nums.push_back(7);
    int target = 9;

    vector<int> v;
    v = s.twoSum(nums,target);
    cout << v[0] << "  " << v[1];

    return 0;
}