#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur = nums.size()-2;
        // 从后往前查找第一个降序的元素位置
        while(cur>=0 && nums[cur] >=nums[cur+1]){
            cur--;
        }
        // 如果cur<0。说明是全降序队列，反向存储
        if(cur<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        // 从后往前查找第一个大于cur的元素，然后交换
        int pos = nums.size()-1;
        while(nums[pos]<=nums[cur]){
            pos--;
        }
        swap(nums[pos],nums[cur]);
        // 对cur后的队列重新升序排列
        sort(nums.begin()+cur+1, nums.end());
    }
};

int main(int argc, char* argv[]){

    return 0;
}