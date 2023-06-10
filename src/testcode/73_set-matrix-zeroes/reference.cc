#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 因为需要对原始矩阵进行数据修改，所以创建一个同样矩阵记录数据
        // 而对原始矩阵直接进行数据修改
        vector<vector<int>> temp = matrix;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                // 注意判断使用新的矩阵
                if(temp[i][j] == 0){
                    // 修改使用原始矩阵
                    for(int k=0; k<m;k++){matrix[k][j] =0;}
                    for(int k=0; k<n;k++){matrix[i][k] =0;}
                }
            }
        }
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}