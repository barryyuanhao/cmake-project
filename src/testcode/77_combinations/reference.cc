#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    // 形参含义：count计算使用了多少个数字， index由于计算当前的下标， path存储当前已使用的数值
    void caculate(int n, int k, int count, int index, vector<int> path){
        if(count == k){
            result.push_back(path);
            return;
        }
        // 循环从index下标开始
        for(int i=index; i<=n; i++){
            path.push_back(i);
            // count值加1， 下标值在已使用的i基础上加一
            caculate(n,k,count+1,i+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        caculate(n,k,0,1,path);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}