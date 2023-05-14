#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 旋转90°，执行步骤如下：
    // 1.对角线交换
    // 2.同行前后交换
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // 对角线交换
        // 注意：只能交换一次，所以 j的起点为 j=i
        for(int i=0; i< size; i++){
            for(int j=i; j<size; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 同行前后交换
        // 注意：前后交换一次，所以j<size/2
        for(int i=0; i< size; i++){
            for(int j=0; j<size/2; j++){
                // 每行的最后一个下标是size -1
                swap(matrix[i][j], matrix[i][size-1-j]);
            }
        }
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}