#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        // 特殊处理size <=2的nums,直接返回size
        if(size <=2){return size;}

        int slow =2;
        int fast = 2;
        // 快慢指针
        for(;fast<size;fast++){
            // slow-2不等于fast，说明最多slow-1、slow可以等于fast，超过则不处理
            if(nums[slow -2] != nums[fast]){
                // slow指针也同时++
                nums[slow++] = nums[fast];
            }
        }

        return slow;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}