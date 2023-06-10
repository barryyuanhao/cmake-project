#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left =0;
        // 使用二分查找模板 [左闭，右闭]，right = size-1;
        int right = m*n-1;
        // 使用二分查找模板 [左闭，右闭]，检测条件left<=right
        while(left <= right){
            int mid = (left+right)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }else if(matrix[mid/n][mid%n] > target){
                // 使用二分查找模板 [左闭，右闭]，right = mid -1;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}