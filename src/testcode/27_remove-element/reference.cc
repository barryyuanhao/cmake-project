#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size =nums.size();
        int slow =0;
        int fast =0;
        for(; fast<size; fast++){
            if(nums[fast]!=val){
                nums[slow++] = nums[fast];
            }
        }
        // 注意与26题区分，26题是使用的下标所以需要+1；
        // 此处在每次赋值后都进行了++,相当于领先下标1个值
        return slow;
    }
};

int main(int argc, char* argv[]){

    return 0;
}