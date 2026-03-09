#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int i , l , r;
        for(i=0 ; i<nums.size() ; i++){
            if(nums[i]>0){
				break;
			}
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            l = i + 1;
            r = nums.size()-1;
            while(l < r){
                if((nums[i] + nums[l] + nums[r]) == 0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    ans.push_back(v);
                    l++ , r--;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r] == nums[r+1]){
                        r--;
                    }
                }else if((nums[i] + nums[l] + nums[r]) > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}