#include <iostream>
#include <string.h>
// #include <algorithm>

using namespace std;

class Solution {
public:
    int compareStr(string s, int left, int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int len = 0;
        int start =0;
        int end = 0;
        for(int i=0; i< s.size(); i++){
            int len1 = compareStr(s, i, i);
            int len2 = compareStr(s, i, i+1);
            int len_temp = max(len1, len2);
            
            if(len_temp > len){
                len = len_temp;
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};

int main(int argc, char* argv[]){

    return 0;
}