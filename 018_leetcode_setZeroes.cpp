#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;        //记录第一行是否有0
        bool col = false;        //记录第一列是否有0
        for(int i=0 ; i<matrix[0].size() ; i++){
            if(matrix[0][i] == 0){
                row = true;
                break;
            }
        }
        for(int i=0 ; i<matrix.size() ; i++){
            if(matrix[i][0] == 0){
                col = true;
                break;
            }
        }
        
        //用数组第一行，第一列分别记录每一行和每一列是否有零出现
        for(int i=1 ; i<matrix.size() ; i++){
            for(int j=1 ; j<matrix[0].size() ; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i=1 ; i<matrix.size() ; i++) {
            for (int j=1; j<matrix[0].size() ; j++) {
                if (matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row == true) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if (col == true) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(){


    return 0;
}