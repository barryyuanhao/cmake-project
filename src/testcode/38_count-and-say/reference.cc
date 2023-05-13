#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // 递归退出条件
        if(n == 1){
            return "1";
        }

        // 进入递归，直到n=1, path为上一级的输出
        string path = countAndSay(n-1);
        int size = path.size();
        string temp_result = ""; //本级的输出结果
        for(int i=0;i < size;i++){
            char value = path[i];
            int count =1;
            while(i+1 < size && path[i+1] == path[i]){
                count++;
                i++;
            }
            temp_result = temp_result+ to_string(count) + value;
        }

        return temp_result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}