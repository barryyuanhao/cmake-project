#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // dp[i][j]表示从[0][0]到[i][j]坐标的路径数量
        vector<vector<int>> dp(m, vector<int>(n,0));
        // 第一列所有的点都只存在一种路径
        // 如果障碍点在第一列，后面的都为0，停止赋值为1
        for(int i=0; i< m && obstacleGrid[i][0] ==0; i++){
            dp[i][0] = 1;
        }
        // 第一行所有的点都只存在一种路径
        // 如果障碍点在第一行，后面的都为0，停止赋值为1
        for(int i=0; i< n && obstacleGrid[0][i] ==0; i++){
            dp[0][i] =1;
        }

        // 如果障碍点[i][j],则跳过障碍点dp[i][j]设置，使用dp[i][j]的默认值0
        for(int i =1; i< m; i++){
            for(int j=1; j< n; j++){
                if(obstacleGrid[i][j] == 1){continue;}
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}