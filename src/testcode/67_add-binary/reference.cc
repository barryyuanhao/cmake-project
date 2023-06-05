#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        string result = "";
        // 以下的老两个while循环用于将a,b的位数拉齐，高位补充‘0’
        while(size_a < size_b){
            a = '0' + a;
            size_a++;
        }

        while(size_b < size_a){
            b = '0' + b;
            size_b++;
        }
        // 进位标志carry
        int carry =0;
        for(int i =size_a-1; i>=0; i--){
            int temp = (a[i] -'0') + (b[i] -'0') + carry;
            carry = temp/2;
            temp = temp%2;
            result = to_string(temp) + result;
        }
        // 最后检查进位标志是否为空
        if(carry > 0){
            result = to_string(carry) + result;
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}