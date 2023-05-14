#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map用于存储相同key值对应的string数据
        map<string, vector<string>> map_data;
        int size = strs.size();
        for(int i=0; i<size; i++){
            string temp = strs[i];
            // 对每个strs[i]进行排序，检查key值是否相同
            sort(temp.begin(),temp.end());
            // key值相同，存入同一个vector<string>
            if(map_data.count(temp)){
                map_data[temp].push_back(strs[i]);
            }else{
                // key值不相同，创建新的key,存储数据
                map_data[temp].push_back(strs[i]);
            }
        }

        // 循环获取MAP的值，并且将map的second数据存入result
        vector<vector<string>> result;
        for(auto it = map_data.begin(); it!=map_data.end();it++){
            result.push_back(it->second);
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}