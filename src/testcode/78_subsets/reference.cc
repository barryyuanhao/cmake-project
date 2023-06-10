#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void caculate(vector<int>& nums, int count, int index, vector<int> path);
    vector<vector<int>> subsets(vector<int>& nums);
};
// 形参含义， count表示子集位数， index标识当前下标， path用于存储当前使用的数字
void Solution::caculate(vector<int>& nums, int count, int index, vector<int> path){
    // 递归终止条件：path的size与count相等
    if(path.size() == count){
        result.push_back(path);
        return;
    }
    // 循环从index下标开始
    for(int i = index; i<nums.size(); i++ ){
        path.push_back(nums[i]);
        caculate(nums,count,i+1,path);
        path.pop_back();
    }
}
vector<vector<int>> Solution::subsets(vector<int>& nums){
    int size = nums.size();
    vector<int> path;
    //此处需要取等，因为子集包括全集
    for(int i =0; i<= size; i++){
        caculate(nums,i,0,path);
    }

    return result;
}

int main(int argc, char* argv[]){
    
    return 0;
}