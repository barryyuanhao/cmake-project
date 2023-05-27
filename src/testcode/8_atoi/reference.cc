#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long new_value = 0;
        int flag = 1;
        int i = 0;
        while(s[i] == ' '){i++;}
        if(s[i] == '-'){
            flag = -1;
            i++;
        }else if(s[i] == '+'){
            flag = 1;
            i++;
        }

        for(; i< s.size(); i++){
            if(s[i] >='0' && s[i] <= '9'){
                if(new_value > INT_MAX/10){
                    return flag==1 ? INT_MAX : INT_MIN;
                }
                new_value = new_value * 10 + (s[i] - '0');
            }else{
                break;
            }
        }
        new_value = new_value*flag;
        new_value = new_value > INT_MAX ? INT_MAX : new_value;
        new_value = new_value < INT_MIN ? INT_MIN : new_value;

        return new_value;
    }
};

int main(int argc ,char* argv[]){

    return 0;
}