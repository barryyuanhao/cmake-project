#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int up = 0;
        int down = row_size -1;
        int left = 0;
        int right = col_size -1;
        vector<int> result;

        while(true){
            // 第一行从左到右：left --> right
            for(int i =left; i<=right; i++){
                result.push_back(matrix[up][i]);
            }
            if(++(up) > down){break;}

            // 最后一列从上到下： up --> down
            for(int i=up; i<=down;i++){
                result.push_back(matrix[i][right]);
            }
            if(--(right) < left){break;}

            // 最后一行从右到左： right --> left
            for(int i=right; i>=left; i--){
                result.push_back(matrix[down][i]);
            }
            if(--(down) < up){break;}

            // 第一列从下到上： down --> up
            for(int i=down; i>=up; i--){
                result.push_back(matrix[i][left]);
            }
            if(++(left) > right){break;}
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}