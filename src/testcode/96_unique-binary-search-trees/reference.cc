#include <iostream>
#include <vector>

using namespace std;
// 此题使用递归查找然后输出size的方法会超时
// https://leetcode.cn/problems/unique-binary-search-trees/solution/96-bu-tong-de-er-cha-sou-suo-shu-dong-ta-vn6x/
// dp[i] ： 1到i为节点组成的二叉搜索树的个数为dp[i]
// dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]
// dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1; //dp[0]没有实际意义，为了保证在相乘不为0，设置为1

        for(int i=0; i<=n; i++){
            for(int j=1; j<=i; j++){
                //dp[i]加入等式是因为最终需要求总和，所以要加入，原始默认值为0
                dp[i] = dp[i] + dp[j-1]*dp[i-j];
            }
        }

        return dp[n];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}