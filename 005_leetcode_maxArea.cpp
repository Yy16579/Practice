#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l=0 , r=height.size()-1;
        while(l<r){
            ans = max(ans , min(height[l],height[r])*(r-l));
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> h;
    h.push_back(1);
    h.push_back(8);
    h.push_back(6);
    h.push_back(2);
    h.push_back(5);
    h.push_back(4);
    h.push_back(8);
    h.push_back(3);
    h.push_back(7);

    Solution s;
    cout << s.maxArea(h);

    return 0;
}