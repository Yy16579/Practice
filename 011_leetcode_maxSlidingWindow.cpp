#include<iostream>
#include<vector>
#include<deque>


using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;                 //单调队列，存储元素的下标
        int l=0 , r=0;

        while(r < nums.size()){
            while(!deq.empty() && nums[r] > nums[deq.back()]){
                deq.pop_back();         //弹出队尾所有比 nums[r] 小的元素，保证队列单调递减
            }
            deq.push_back(r);
            r++;

            while(r - l >= k){                  
                ans.push_back(nums[deq.front()]);
                
                if(l >= deq.front()){       //窗口移动，处理过期队头
                    deq.pop_front();
                }
                l++;
            }
        }
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    vector<int> ans;
    Solution s;
    ans = s.maxSlidingWindow(nums , k);
    for(int& i : ans){
        cout << i << "  ";
    }

    return 0;
}