#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_data = nums[0]; //记录最大的值；
        int size = nums.size();
        //动态规划，用于存储数据
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(size);
        dp[0] = nums[0];

        for(int i=1; i< size; i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_data = max(max_data, dp[i]);
        }

        return max_data;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}