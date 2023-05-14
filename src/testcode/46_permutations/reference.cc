#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, vector<bool>& used, int index, vector<int> path){
        // 递归退出条件
        if(index == nums.size()){
            // 中间结果存入最终结果
            result.push_back(path);
            return;
        }

        // 循环检测当前的变量
        for(int i =0; i< nums.size(); i++){
            if(used[i] == false){
                path.push_back(nums[i]);
                used[i] = true;
                generate(nums,used,index+1,path);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<bool> used(size, false); //用于检测是否使用了当前变量
        vector<int> path; //存储中间计算结果
        generate(nums,used,0, path); //递归函数， index从0 开始

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}