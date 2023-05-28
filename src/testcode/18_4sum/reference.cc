#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        // 排序
        sort(nums.begin(), nums.end());
        // 第一个数
        for(int i=0; i<size-3;i++){
            // 对第一个数去重
            if(i>0 && nums[i] == nums[i-1]){continue;}
            // 第二个数
            for(int j=i+1;j<size-2; j++){
                // 对第二个数去重
                if(j>i+1 && nums[j] == nums[j-1]){continue;}
                // 设置第三、第四个数，并且动态检测
                int left = j+1;
                int right = size-1;
                while(left < right){
                    // 此处避免int数据溢出，转为long
                    if((long)nums[i]+nums[j]+nums[left]+nums[right] == target){
                        // 合法的需求结果
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // 对第三、第四个数去重
                        left++;
                        while(left < right && nums[left] == nums[left-1]){left++;}
                        right--;
                        while(left < right && nums[right]== nums[right+1]){right--;}
                    }else if((long)nums[i]+nums[j]+nums[left]+nums[right] > target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}