#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for(int i=0 ; i<matrix.size()/2 ; i++){
            for(int j=0 ; j<(matrix.size()+1)/2 ; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }        
        return;
    }
};

int main(){


    return 0;
}