#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        std::map<char,int> map_ruoma = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0; i < s.size(); i++){
            if(map_ruoma[s[i]] < map_ruoma[s[i+1]]){
                result = result - map_ruoma[s[i]];
            }else{
                result = result + map_ruoma[s[i]];
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}