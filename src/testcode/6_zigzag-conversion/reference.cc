#include <iostream>
#include <string.h>
#include <vector>
// #include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<string> result_v(numRows);
        string result = "";
        int flasg = -1;
        int index = 0;

        if(numRows == 1){ return s;}
        if(s.size() <= numRows){ return s;}
        for(int i=0; i < s.size(); i++){
            if(index ==0 || index == numRows-1){
                flasg = -flasg;
            }
            result_v[index] = result_v[index] + s[i];
            index = index + flasg;
        }

        for(int i=0; i< numRows; i++){
            result = result+ result_v[i];
        }
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}