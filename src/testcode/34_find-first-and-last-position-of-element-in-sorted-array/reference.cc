#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left =0;
        int right = size;
        int idx_first = -1; //第一个下标
        int idx_end = -1;   //最后一个下标
        
        // 使用二分法，先查找nums中是否存在target值
        while(left < right){
            int mid  = (left + right) /2;
            if(nums[mid] == target){
                idx_first = mid;
                idx_end = mid;
                break;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        // 如果没有查找到target，直接返回{-1，-1}
        if(idx_first ==-1){
            return {-1,-1};
        }

        // 搜索第一个下标值
        while(idx_first > 0 && nums[idx_first] == nums[idx_first-1]){idx_first--;}
        // 搜索最后一个下标值
        while(idx_end < size-1 && nums[idx_end] == nums[idx_end+1]){idx_end++;}
        return {idx_first, idx_end};
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}