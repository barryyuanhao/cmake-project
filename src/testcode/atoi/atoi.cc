#include <iostream>
#include <string.h>

int main(int argc ,char* argv[]){
    std::string s = "   +1999 9.87";
    std::cout << "The raw value is :" << s << std::endl;
    int flag = 1;
    int ans = 0;
    int key = 0;

    // 检测空格字符
    while(key < s.size() && s[key] == ' '){
        key++;
        continue;
    }

    // 检测 正负符号
    if(key < s.size() && s[key] == '-'){
        flag = -1;
        key++;
    }else if(key < s.size() && s[key] == '+'){
        flag = 1;
        key++;
    }

    // 检测数字
    while (key < s.size() && s[key] >= '0' && s[key] <= '9')
    {
        // 最小负整数边界检测
        if(ans < INT32_MIN/10) return INT32_MIN;
        // 最大正整数边界检测
        if(ans > INT32_MAX/10) return INT32_MAX;
        // 获取最新的数值
        ans = ans*10 + (s[key] - '0');
        key++;
    }
    ans = ans * flag;
    
    std::cout << "The value is : " << ans << std::endl;
    

    return 0;
}