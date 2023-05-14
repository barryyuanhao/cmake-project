#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, vector<bool>& used, int index, vector<int> path){
        // 递归退出条件
        if(index == nums.size()){
            result.push_back(path);
            return;
        }

        // 循环检测元素
        for(int i=0; i < nums.size(); i++){
            // 去重操作
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过 
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false){continue;}
            if(used[i] == false){
                path.push_back(nums[i]);
                used[i] = true;
                generate(nums,used,index+1,path);
                path.pop_back();
                used[i] = false;
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<bool> used(size, false); //检查是否使用了该元素
        vector<int> path;
        // 去重一定要排序，是一个有序数列
        sort(nums.begin(), nums.end());
        generate(nums,used,0,path);

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}