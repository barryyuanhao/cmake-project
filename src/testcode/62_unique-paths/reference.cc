#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 本题使用DFS深度搜索的方法存在超时的问题
    // 所以本题采用动态规划的算法
    int uniquePaths(int m, int n) {
        // dp[i][j]标识从[0][0]坐标到[i][j]坐标存在dp[i][j]种到达路径
        vector<vector<int>> dp(m,vector<int>(n,0));
        // 第一列所有的[i][0]都只存在一种路径
        for(int i=0; i < m; i++){
            dp[i][0] = 1;
        }
        // 第一行所有的[0][i]都只存在一种路径
        for(int i=0; i < n; i++ ){
            dp[0][i] =1;
        }

        for(int i=1; i< m; i++){
            for(int j=1; j<n; j++){
                // 每个坐标点[i][j]都存在两个路径[i-1][j]与[i][j-1]
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}