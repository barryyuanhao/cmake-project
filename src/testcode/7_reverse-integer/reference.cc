#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        long new_vale =0;
        if(x < 0){
            flag = -1;
        }
        x= abs(x);

        while(x){
            int temp = x%10;
            x = x/10;
            new_vale = new_vale*10 + temp;
        }

        new_vale = new_vale * flag;

        new_vale = new_vale > INT_MAX ? 0 : new_vale;
        new_vale = new_vale < INT_MIN ? 0 : new_vale;
        return new_vale;
    }
};

int main(int argc, char* argv[]){

    return 0;
}