#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 首先需要掌握一个概念，box的index计算方法：
    // box_num = col/3 + (row/3)*3
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0}; //统计行
        int col[9][10]={0}; //统计列
        int box[9][10]={0}; //统计box
        int size = board.size();

        for(int i=0; i< size; i++){
            for(int j=0; j<size; j++){
                // 如果为字符".",直接查看下一个数字
                if(board[i][j]=='.'){continue;}
                int value = board[i][j]-'0';
                if(row[i][value]) return false;
                if(col[j][value]) return false;
                if(box[j/3 + (i/3)*3][value]) return false;

                row[i][value] =1;
                col[j][value] =1;
                box[j/3 + (i/3)*3][value] =1;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}