#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/decode-ways/solution/jie-ma-fang-fa-tu-jie-dp-zui-qing-xi-yi-97hng/

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        // 动态规划
        // 状态表示: dp[i] 标识s(0,i-1)的组合数量
        // dp[0]无实际含义,边界值dp[0]=1
        // dp[i]默认值为0,针对无效的组合,默认使用这的dp[i] =0表示;
        vector<int> dp(size+1,0);
        dp[0]=1;
        for(int i=1; i<=size; i++){
            // 独立解析s[i-1]位
            if(s[i-1] != '0'){dp[i] = dp[i-1];}
            if(i>=2){
                // 组合解析s[i-1]s[i-2],组合值 10<=x<=26
                int value = (s[i-2]-'0')*10 + (s[i-1] - '0');
                if(value>=10 && value <=26){
                    dp[i] = dp[i] + dp[i-2];
                }
            }
        }

        return dp[size];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}