#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        // 动态存放中间路径，
        vector<string> v_result;
        // 存放两个'/'间的字符路径
        string temp_path ="";
        for(int i=0; i< size; i++){
            // 通过是否为'/'作为分支条件，
            if(path[i] == '/'){
                // 回到上一级
                if(temp_path==".." && !v_result.empty()){
                    v_result.pop_back();
                }
                // 路径压入vector
                else if(temp_path!="."&&temp_path!=".."&&!temp_path.empty()){
                    v_result.push_back(temp_path);
                }
                //清空中间的path数据
                temp_path = "";
            }else{
                // 累计获取中间path数据
                temp_path = temp_path + path[i];
            }
        }
        //处理最后一个temp_path中的数据
        if(temp_path==".." && !v_result.empty()){
            v_result.pop_back();
        }else if(temp_path!="."&&temp_path!=".."&&!temp_path.empty()){
            v_result.push_back(temp_path);
        }

        // 如果为空返回根目录 '/'
        if(v_result.empty()){
            return "/";
        }
        // 返回最终目录
        string ans ="";
        for(string str:v_result){
            ans = ans + "/" + str;
        }
        return ans;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}