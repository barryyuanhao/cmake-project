#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        // nusm为0或1，直接返回size
        if(size==0 || size ==1){return size;}
        int slow =0;
        int fast =1;
        // 循环检测，指导fast=size
        for(;fast < size;fast++){
            if(nums[slow]!=nums[fast]){
                nums[++slow] = nums[fast];
            }
        }
        // 注意返回的时候slow下标需要+1
        return slow+1;
    }
};

int main(int argc, char* argv[]){

    return 0;
}