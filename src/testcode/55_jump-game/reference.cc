#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 保存每次更新后的最大值
        int max_pos = nums[0];
        int size = nums.size();
        int flag = true;

        for(int i=0; i < size; i++){
            // 循环更新每次移动后可以到达的最远距离
            max_pos = max(max_pos, i+nums[i]);
            // 可以移动到最远距离
            if(max_pos >=size-1){
                flag = true;
                break;
            }
            // max_pos == i，说明在运行到下标i的位置，运行的最远距离也是i，
            // 所以无法到达终点
            if(max_pos == i && max_pos< size-1){
                flag = false;
                break;
            }
        }

        return flag;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}