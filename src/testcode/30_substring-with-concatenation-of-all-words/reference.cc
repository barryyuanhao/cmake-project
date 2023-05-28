#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.size();
        int w_size = words.size();
        int length = words[0].size();
        vector<int> result;
        // 使用无序unordered_map, unordered_map使用哈希表，查找速度更快
        // 该map_data用于存储words中的单词以及数量
        unordered_map<string , int> map_data;
        for(string w:words){
            map_data[w]++;
        }
        // 遍历字符串s
        for(int i=0; i<=size-length; i++){
            // 检查第一个单词是否为words的单词，否则往下查询
            if(map_data.count(s.substr(i,length)) ==0){continue;}
            // 由于会清理unordered_map中的单词，所以重新定义一个临时unordered_map
            unordered_map<string,int>temp_map=map_data;
            // 循环查找words中的单词数量
            for(int j=0; j<w_size; j++){
                // 每次查找的长度未words中单词的长度
                string a = s.substr(i+j*length,length);
                // temp_map中未查找到a,或者a的引用计数已经为0；说明不满足要求
                if(temp_map.count(a)==0 || temp_map[a] ==0){
                    break;
                }else{
                    temp_map[a]--;
                }
                // j的查找数量等于words中单词的数量，说明查找结束
                if(j == w_size-1){
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}