#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int caculate(vector<int>& nums, int target, int left, int right){
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int idx = 0;
        // 查找螺旋点
        for(int i=0; i< size-1; i++){
            if(nums[i] > nums[i+1]){
                idx = i;
            }
        }
        // 前半部分查找目标值
        int index = caculate(nums, target, 0, idx);
        // 对返回值进行上限确认，防止越界
        if(index >= size){index = size-1;}
        // 如果返回值为目标值直接返回True
        if(nums[index] == target){return true;}
        // 对后半部分查找目标值
        index = caculate(nums,target,idx,size);
        // 对返回值进行上限确认，防止越界
        if(index >= size){index = size-1;}
        // 如果返回值为目标值直接返回True
        if(nums[index] == target){return true;}

        return false;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}