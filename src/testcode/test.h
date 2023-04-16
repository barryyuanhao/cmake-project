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