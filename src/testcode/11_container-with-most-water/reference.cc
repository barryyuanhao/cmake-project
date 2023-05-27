#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        long max_value =0;
        int left = 0;
        int right  = height.size() -1;

        while(left < right){
            int height_min = height[left] < height[right] ? height[left]: height[right];
            long temp_max = (right - left)*height_min;
            max_value = max(max_value, temp_max);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return max_value;
    }
};

int main(int argc, char* argv[]){

    return 0;
}