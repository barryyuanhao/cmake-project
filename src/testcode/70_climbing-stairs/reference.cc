#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/climbing-stairs/solution/dai-ma-sui-xiang-lu-dong-tai-gui-hua-jin-y1hw/

class Solution {
public:
    // ps: 此题采用递归方法会超时，因此采用动态规划

    int climbStairs(int n) {
        // 因为增加了对dp[2]的操作，所以当n=1的会越界
        if(n==1){return 1;}
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        // 循环从3开始，如果n=2，跳过循环
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
int main(int argc, char* argv[]){
    
    return 0;
}