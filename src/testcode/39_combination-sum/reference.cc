#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void add(vector<int>& nums, int target, int sum, int index, vector<int> path){
        if(sum == target){
            // 和为target，path存入结果result
            result.push_back(path);
            return;
        }else if( sum > target){
            // 超过target，直接退出该分支
            return;
        }

        for(int i=index; i<nums.size(); i++){
            sum = sum + nums[i];
            path.push_back(nums[i]);
            add(nums, target,sum,i,path);
            // 和减去最后一个加入的值
            sum = sum - nums[i];
            // 删除最后一个压入数据
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        add(candidates,target,0,0,path);

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}