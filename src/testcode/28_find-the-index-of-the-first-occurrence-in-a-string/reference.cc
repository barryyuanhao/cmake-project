#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size();
        int n_size = needle.size();
        int index =-1;
        bool flag =false;

        // 注意：i小于等于（<=）size-n_size
        for(int i =0; i<= size-n_size;i++){
            // 比对needle的字符
            for(int j =0; j< n_size;j++){
                // 不相等就退出该needle的比较
                if(haystack[i+j] != needle[j]){
                    break;
                }
                // 说明比较完毕neeedle
                if(j==n_size-1){
                    flag =true;
                }
            }
            if(flag){
                index = i;
                break;
            }
        }

        return index;
    }
};

int main(int argc, char* argv[]){

    return 0;
}