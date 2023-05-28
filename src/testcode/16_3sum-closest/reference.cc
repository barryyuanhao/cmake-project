#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); //对原数据进行排序
        int size = nums.size();
        int result = nums[0]+nums[1]+nums[2]; //初始化result

        // for循环结束点为 size-2；
        for(int i=0;i<size-2;i++){
            int left = i+1;
            int right = size-1;
            while(left<right){
                // 每组数据的temp_result
                int temp_result = nums[i]+nums[left]+nums[right];
                if(abs(temp_result - target) < abs(result - target)){
                    result = temp_result;
                }
                if(temp_result > target){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]){
  
    return 0;
}