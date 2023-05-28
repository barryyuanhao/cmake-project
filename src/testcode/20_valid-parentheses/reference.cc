#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        vector<char> v_data; //存放中间数据
        for(int i =0; i< size; i++){
            if(s[i]=='('){v_data.push_back(')');} //注意此处为反向压入
            else if(s[i]=='{'){v_data.push_back('}');}
            else if(s[i]=='['){v_data.push_back(']');}
            //检测是否为空或者与最后一个不匹配
            else if(v_data.empty()||v_data.back()!=s[i]){return false;}
            // 说明新的字符与压入的最后一个字符相同，执行弹出操作
            else{v_data.pop_back();}
        }

        //检查最终的中间数据是否为空，为空说明是有效括号
        if(v_data.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(int argc, char* argv[]){

    return 0;
}