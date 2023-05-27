#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> data_v   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<string> str_v = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        std::string str_result = "";
        for(int i=0; i < data_v.size(); i++){
            while(num >= data_v[i]){
                str_result = str_result + str_v[i];
                num = num - data_v[i];
            }
        }
        return str_result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}