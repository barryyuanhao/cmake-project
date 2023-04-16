#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);

    std::vector<int> raw_num = {1,2,4,4,5,5,8,9};
    int target = 10;
};

int main(int argc, char* argv[]){
    Solution obj;
    obj.twoSum(obj.raw_num, obj.target);
    return 0;
}

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         std::vector<int> result;
//         std::map<int,int> map_data;
//         for(int i=0; i<nums.size();i++){
//             if(map_data.find(target-nums[i]) != map_data.end()){
//                 result.push_back(i);
//                 result.push_back(map_data[target-nums[i]]);
//                 break;
//             }
//             map_data[nums[i]] = i;
//         }
//         return result;
//     }
// };