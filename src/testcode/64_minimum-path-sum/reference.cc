#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化dp[0][0]
        dp[0][0] = grid[0][0];
        // 计算第一列的dp[i][0]值
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        // 计算第一行的dp[0][i]值
        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i=1; i< m; i++){
            for(int j=1; j< n; j++){
                // 对于坐标[i][j]有两个路径[i-1][j] 和[i][j-1]两个路径，
                // 动态计算获取[i][j]位置的最小值
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}