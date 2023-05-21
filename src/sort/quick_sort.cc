#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int partition(vector<int>& nums, int left, int right) {
    // 在闭区间 [left, right] 随机选取任意索引，并与 nums[left] 交换
    int ra = left + rand() % (right - left + 1);
    swap(nums[left], nums[ra]);

    // 以 nums[left] 作为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) j--;
        while (i < j && nums[i] <= nums[left]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        // 子数组长度为 1 时终止递归
        if (left >= right){return;}
        // 哨兵划分操作
        int i = partition(nums, left, right);
        // 递归左（右）子数组执行哨兵划分
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        quickSort(nums, 0, size - 1);
        return nums;
    }

};

int main(int argc, char* argv[]){
    vector<int> Input = {5,2,3,1,4,7,10,9,8};
    Solution obj;
    auto result = obj.sortArray(Input);
    for(auto data:result){
        std::cout << data << " ";
    }
    std::cout << std::endl;
    return 0;
}