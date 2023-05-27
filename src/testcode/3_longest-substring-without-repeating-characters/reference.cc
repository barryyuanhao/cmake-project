#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right =0;
        int result =0;
        while( right < s.size()){
            for(int i = left; i < right; i++){
                if(s[i] == s[right]){
                    left = i+1;
                }
            }
            result = max(result , right - left+1);
            right++;
        }
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}