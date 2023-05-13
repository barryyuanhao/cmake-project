#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchData(vector<int>& nums, int target, int left, int right){
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        // 此处在搜索到右边界的时候结束，但是left=mid+1，此时left等于size,
        // 直接nums[left]其实就是nums[size]，导致越界。
        if(left>=nums.size()){
            return nums[left-1]==target? left: -1;
        }else{
            return nums[left]==target? left: -1;
        }

    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int idex = 0;
        // 获取切割点
        for(int i=0; i< size-1; i++){
            // 防止越界，循环上限 size -1
            if(nums[i] > nums[i+1]){
                idex = i;
            }
        }
    
        // 先搜索前半部分的点
        int result = searchData(nums,target,0,idex);
        if(result != -1) {return result;}
        // 前半部分不存在结果的情况下，再搜索后半部分的点
        result = searchData(nums,target,idex,size);
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}