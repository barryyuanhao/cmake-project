#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void cacualte(vector<int>& nums, int count, int index, vector<int> path,vector<bool> used){        
        // 递归退出条件
        if(path.size() == count){
            result.push_back(path);
            return;
        }
        
        // 避免往前查找,i=index
        for(int i =index; i< nums.size(); i++){
            // 去重,
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false){continue;}
            path.push_back(nums[i]);
            used[i] = true;
            cacualte(nums,count,i+1,path,used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        vector<int> path;
        // 检测是否使用了该位
        vector<bool> used(size,false);
        // 去重一定要先排序
        sort(nums.begin(), nums.end());
        // 设置不同的子集位数
        for(int i=0; i<=size; i++){
            cacualte(nums,i,0,path,used);
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}