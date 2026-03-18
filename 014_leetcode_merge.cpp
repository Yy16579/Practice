#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());          //对二维数组进行字典序排序
        int L = intervals[0][0];
        int R = intervals[0][1];
        for(int i=1 ; i<intervals.size() ; i++){
            if(R >= intervals[i][0]){
                R = max(R , intervals[i][1]);
            }else{
                ans.push_back({L , R});
                L = intervals[i][0];
                R = intervals[i][1];
            }
        }
        ans.push_back({L , R});
        return ans;
    }
};

int main(){
    //测试数据
    vector<vector<int>> intervals = {{1,3},{15,18},{8,10},{2,6}};
    vector<vector<int>> ans;

    Solution s;
    ans = s.merge(intervals);
    for(vector<int>& v : ans){
        for(int& i : v){
            cout << i << "  ";
        }
        cout << endl;
    }

    return 0;
}