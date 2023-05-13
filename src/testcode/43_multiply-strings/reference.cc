#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A;
        vector<int> B;
        int m = num1.size();
        int n = num2.size();
        //两数相乘，最大为 m+n 位数
        vector<int> C(m+n);
        // 反向将字符存入整数数组
        for(int i=m-1; i>=0; i--){A.push_back(num1[i]-'0');}
        for(int i=n-1; i>=0; i--){B.push_back(num2[i]-'0');}

        // 整数相乘
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                // 注意： 原数加上新的乘积
                C[i+j] = C[i+j] + A[i]*B[j];
            }
        }
        
        // 统一计算进位操作
        int carry =0;
        for(int i=0; i < C.size(); i++){
            C[i] = C[i] + carry;
            carry = C[i]/10;
            C[i] = C[i]%10;
        }

        // 去除先导0
        int k=C.size() -1;
        while(k>0 && C[k]==0){k--;}

        // 反向输出整数值到string
        string result = "";
        while(k>=0){
            result = result + to_string(C[k]);
            k--;
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}