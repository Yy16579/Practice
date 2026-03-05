#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set;
        for(const int& num : nums){
            set.insert(num);
        }
        int curl;
        int num;
        for(auto it=set.begin() ; it!=set.end() ; it++){
            num = *it;
            if(set.find(num-1) != set.end()){
                continue;
            }else{
                curl = 1;
                num++;
                while(set.find(num) != set.end()){
                    curl++;
                    num++;
                }
                ans = max(ans , curl);
            }
        }
        return ans;
    }
};


int main(){


    

    return 0;
}