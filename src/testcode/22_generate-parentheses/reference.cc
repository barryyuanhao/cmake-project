#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    // 形参：输入数字n, 左括号数left，右括号数right, 中间存储变量path
    void generate(int n, int left, int right, string path){
        // 递归退出条件，left = right = n
        if(left == n && right == n){
            result.push_back(path);
            return;
        }

        // 左括号数量小于n
        if(left < n){
            path.push_back('(');
            generate(n,left+1,right,path);
            path.pop_back();
        }
        // 右括号数量小于左括号
        if(right < left){
            path.push_back(')');
            generate(n,left,right+1,path);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(n,0,0,"");

        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}