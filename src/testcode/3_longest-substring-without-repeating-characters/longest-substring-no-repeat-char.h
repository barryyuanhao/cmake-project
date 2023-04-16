#include <iostream>
#include <vector>
#include <string.h>

class Solution{
public:
    int lengthOfLongestSubstring(std::string s);

    std::string raw_s = "aaabcdefbd";
};

int main(int argc, char* argv[]){
    Solution obj;
    obj.lengthOfLongestSubstring(obj.raw_s);
    return 0;
}
