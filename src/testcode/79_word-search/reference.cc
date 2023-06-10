#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // ax、ay组合在一起分别对应四个方向的移动
    int ax[4] = {-1,0,0,1};
    int ay[4] = {0,-1,1,0};
    // 形参含义， count标识当前计算到word的第几个下标，x,y表示坐标
    bool dfs(vector<vector<char>>& board, string word, int count, int x, int y){
        // 检查最新的坐标（x,y）是否与word的下标count匹配，不匹配直接返回
        if(board[x][y]!=word[count]){return false;}
        // 如果匹配，且count == word.size()-1,说明检测完毕
        if(count == word.size()-1){return true;}

        // 临时记录（x,y）中的字符，不满足的情况下用于恢复
        char temp = board[x][y];
        // 已使用的字符转化为特殊字符
        board[x][y] = '.';
        // 分别四个方向搜索下一个字符
        for(int i =0; i<4;i++){
            int temp_x= x+ax[i];
            int temp_y =y+ay[i];
            // 此处边界条件分别对应四个边界以及已使用字符'.'
            if(temp_x<0 || temp_x>=board.size() ||
               temp_y<0 || temp_y>=board[0].size() ||
               board[temp_x][temp_y]=='.'){
                   continue;
            }
            // 继续下一层搜索
            if(dfs(board,word,count+1,temp_x,temp_y)){return true;};
        }
        // 如果不满足搜索条件，需要将字符恢复
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // 单词的首字母分别从矩阵的每一个字符开始
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                bool result = dfs(board,word,0,i,j);
                if(result){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}