#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    int lengthOfLastWord(string s) {
        int size =s.size();
        // 存储string中的单词
        string path ="";
        for(int i =0; i< size ; i++){
            // 遇到空格的情况下，如果有单词，存入单词；然后继续查找后面的字符
            if(s[i] == ' '){
                if(!path.empty()){
                    result.push_back(path);
                    path="";
                }
                continue;
            }else{
                // 连续字符写入单词中
                path = path + s[i];
            }
        }

        // 注意：最后还有一个单词在 path中，需要存入最终的结果
        if(!path.empty()){
            result.push_back(path);
            path = "";
        }

        return result.back().size();
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}