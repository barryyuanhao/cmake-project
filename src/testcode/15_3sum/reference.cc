#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> arg_data(3);
        std::sort(nums.begin(), nums.end());

        for(int i=0; i< nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1]){continue;}
            int left =i+1;
            int right = nums.size()-1;
            if(nums[i] + nums[i+1] + nums[i+2] > 0){break;}
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0 ){
                    right--;
                    // while(nums[right] == nums[right+1]){right--;}
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                    // while(nums[left] == nums[left-1]){left++;}
                }else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(nums[right] == nums[right+1] && left < right){right--;}
                    while(nums[left] == nums[left-1] && left < right){left++;}
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}