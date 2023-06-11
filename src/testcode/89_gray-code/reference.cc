#include <iostream>
#include <vector>

using namespace std;

/*
解题思路：
    n =1 ,delta = 0, [00,01]
    n =2 ,delta = 2, [00,01,11,10]
    n =3 ,delta = 4, [00,01,11,10,110,111,101,100]
    n =4 ,delta = 8, [00,01,11,10,110,111,101,100,1100,1101,1111,1110,1010,1011,1001,1000]
    从以上规律可以发现，n每增加1，就在原有的result基础上从后往前，在二进制值前加1
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        // 在result存入n=1时的结果, 二进制: 00, 01
        result.push_back(0);
        result.push_back(1);

        // 每次计算都是在原有的resul中的前一位(二进制值)加1
        int delta =2;

        for(int i=2; i<=n; i++){
            // 对result中的数值从后向前,保证每次只有一个二进制位变动
            for(int j = result.size()-1; j>=0;j--){
                result.push_back(result[j]+delta);
            }
            // delta左移一位
            delta = delta*2;
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}