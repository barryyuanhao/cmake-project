#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index =0;
        bool flag = false;
        for(; index < strs[0].size();index++){
            for(int j=0; j < strs.size(); j++){
                if(strs[j][index] != strs[0][index]){
                    flag =true;
                    break;
                }
            }
            if(flag){break;}
        }
        return strs[0].substr(0, index);
    }
};

int main(int argc, char* argv[]){
  
    return 0;
}