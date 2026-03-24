#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        //定义边界
        int u = 0;      
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;

        while(1){
            for(int i=l ; i<=r ; i++){
                ans.push_back(matrix[u][i]);
            }
            if(++u > d) break;
            for(int i=u ; i<=d ; i++){
                ans.push_back(matrix[i][r]);
            }
            if(--r < l) break;
            for(int i=r ; i>=l ; i--){
                ans.push_back(matrix[d][i]);
            }
            if(--d < u) break;
            for(int i=d ; i>=u ; i--){
                ans.push_back(matrix[i][l]);
            }
            if(++l > r) break;
        }
        return ans;
    }
};

int main(){


    return 0;
}