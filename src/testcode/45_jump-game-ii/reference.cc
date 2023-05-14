#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0; //计算跳跃次数
        int max_pos =0; //记录每次更新后的最大距离
        int size =nums.size(); 
        int cur_pos =0; //记录当前最大距离

        // 循环查找当前最远的距离，max_pos；只有当i = cur_pos的情况下才需要加1
        for(int i=0; i< size; i++){
            // 查找当前的最远距离
            max_pos = max(nums[i]+i, max_pos);
            // 此时检查cur_pos是否到终点，否则进行count++
            if(i == cur_pos){
                // cur_pos不是终点，count++
                if(cur_pos != size -1){
                    count++;
                    // 更新当前的cur_pos
                    cur_pos = max_pos;
                    if(cur_pos >= size-1){
                        break;
                    }
                }
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}