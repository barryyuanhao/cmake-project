#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    void caculate(string digits, map<int,string> map_data, int index){
        // 返回条件，index与digits的数量一致
        if(index == digits.size()){
            result.push_back(path);
            return;
        }

        // 获取index字符对应的string
        string str_data = map_data[digits[index] - '0'];

        // 循环获取str——data的一个字符，压入path
        for(int i=0; i<str_data.size();i++){
            path.push_back(str_data[i]);
            caculate(digits,map_data,index+1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == ""){return result;} //输入为空，直接返回
        // 定义电话号码对应的字符
        map<int,string> map_data = {{0,""},{1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        caculate(digits,map_data,0);

        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}