#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l=0 , r=n-1;        //左右指针
        int hl=0 , hr=0;        //记录 左指针 左边最高的墙，和右指针 右边最高的墙
        while(l <= r){             //记录 当前墙较矮的这一侧 的指针指向的这一列 能存多少水
            if(hl <= hr){           
                if(hl >= height[l]){
                    ans += (hl - height[l]);
                }else{
                    hl = height[l];
                }
                l++;
            }else{
                if(hr >= height[r]){
                    ans += (hr - height[r]);
                }else{
                    hr = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

int main(){
    //测试数据
    vector<int> h = {4,2,0,3,2,5};
    Solution s;
    cout << s.trap(h);

    return 0;
}