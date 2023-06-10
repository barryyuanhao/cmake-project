#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right);
    void quickSort(vector<int>& nums, int left, int right);
    void sortColors(vector<int>& nums);
};

int Solution::partition(vector<int>& nums, int left, int right){
    int length = right-left +1;
    // 在闭区间 [left, right] 随机选取任意索引，并与 nums[left] 交换
    int ra = rand()%length + left;
    // 以随机任意索引值为基准，交换left与ra值，使ra值移动到nums[left]
    swap(nums[ra], nums[left]);
    // 以 nums[left] 作为基准数
    int i = left;
    int j = right;
    // *********以左边界为准，先移动right；以右边界为准，先移动left;
    while(i <j){
         // 参考左边界为基准，先检测右边，找到小于基准的值
        while(i< j && nums[j] >= nums[left]){j--;}
        // 参考左边界，找到大于基准的值
        while(i< j && nums[i] <= nums[left]){i++;}
        // 交换: 左边大于基准值，右边小于基准值的两个数据
        swap(nums[i], nums[j]);
    }
    // 循环结束后，将基准值移动到i的位置。
    swap(nums[i], nums[left]);
    return i;
}

void Solution::quickSort(vector<int>& nums, int left, int right){
    // 子数组长度为 1 时终止递归
    if(left >= right){return;}
    // 哨兵划分操作
    int i = partition(nums, left, right);
    // 递归左（右）子数组执行哨兵划分
    quickSort(nums, left, i-1);
    quickSort(nums, i+1, right);
}

void Solution::sortColors(vector<int>& nums){
    int size = nums.size();
    quickSort(nums,0,size-1);
}

int main(int argc, char* argv[]){
    
    return 0;
}