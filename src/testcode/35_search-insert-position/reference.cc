#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size =nums.size();
        int left = 0;
        int right = size;
        // 左开右闭，
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid +1;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[]){
  
    return 0;
}