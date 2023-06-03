#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> result;
        // 加一数值
        int carry =1;
        // 从后往前计算
        for(int i=size-1; i>=0; i--){
            int temp = digits[i] + carry;
            carry = temp/10;
            temp = temp%10;
            // 方法一：在vector的前面插入
            result.insert(result.begin(),temp);
            // 方法二：在vector的后面插入，最后做一次反转
            // result.push_back(temp);
        }
        if(carry>0){
            // 方法一：在vector的前面插入
            result.insert(result.begin(),carry);
            // 方法二：在vector的后面插入，最后做一次反转
            // result.push_back(carry);
        }
        // 方法二：在vector的后面插入，最后做一次反转
        // reverse(result.begin(),result.end());

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}