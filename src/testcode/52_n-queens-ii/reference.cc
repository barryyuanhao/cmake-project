#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int result;
    bool isvalid(int n, int row, int col, vector<string> path);
    void generate(int n, int row, vector<string>path);
    int totalNQueens(int n);
};

bool Solution::isvalid(int n, int row, int col, vector<string> path){
    // 列检查
    for(int i=0; i<row; i++){
        if(path[i][col] == 'Q'){
            return false;
        }
    }

    // 对角线135°角度
    for(int i= row-1,j=col-1; i>=0 && j>=0; i--,j--){
        if(path[i][j] == 'Q'){
            return false;
        }
    }

    // 对角线45°角
    for(int i=row-1, j=col+1; i>=0 && j < n; i--,j++){
        if(path[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void Solution::generate(int n, int row, vector<string>path){
    // row从0开始，如果row==n，说明最后一行已经完成填写
    // 循环结束
    if(row == n){
        result++;
        return;
    }
    // 每行从第0下边开始检测，查找合法的列的位置
    for(int i=0; i<n; i++){
        if(isvalid(n,row,i,path)){
            path[row][i] = 'Q';
            generate(n, row+1, path);
            path[row][i] = '.';
        }
    }
}

int Solution::totalNQueens(int n){
    // 设置中间结果，默认填充n*n的'.'二位数组
    vector<string> path(n,string(n,'.'));
    // 计算的思路是一行一行的往下设置，所以第二个参数从0开始
    generate(n,0,path);

    return result;
}

int main(int argc, char* argv[]){

    return 0;
}