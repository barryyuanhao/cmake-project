#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 初始化一个N * N 的矩阵
        vector<vector<int>> result(n,vector<int>(n,0));
        int up =0;
        int down = n-1;
        int left =0;
        int right = n-1;
        int count = 1;
        while(true){
            // 写最上面一行： 从左到右
            for(int i=left; i<=right; i++){
                result[up][i] = count;
                count++;
            }
            if(++(up) > down){break;}

            // 写最后一列：从上到下
            for(int i=up; i<=down; i++){
                result[i][right] = count;
                count++;
            }
            if(--(right) < left){break;}

            // 写最后一行：从右向左
            for(int i=right; i>=left; i--){
                result[down][i] = count;
                count++;
            }
            if(--(down) < up){break;}

            // 写第一列： 从下向上
            for(int i=down; i>=up; i--){
                result[i][left] = count;
                count++;
            }
            if(++(left) > right){break;}
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}