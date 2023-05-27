#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::map<int,int> map_data;
        for(int i=0; i< nums.size(); i++){
            if(map_data.find(target - nums[i]) != map_data.end()){
                result.push_back(i);
                result.push_back(map_data[target - nums[i]]);
                break;
            }
            map_data[nums[i]] = i;
        }
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}