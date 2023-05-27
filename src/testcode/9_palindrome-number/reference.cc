#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        int raw = x;
        long new_value = 0;
        
        if(x < 0){return false;}

        while(raw){
            int temp = raw % 10;
            raw = raw / 10;
            new_value = new_value *10 + temp;
        }

        if (new_value == x){
            return true;
        }else{
            return false;
        }
    }
};

int main(int argc, char* argv[]){

    return 0;
}