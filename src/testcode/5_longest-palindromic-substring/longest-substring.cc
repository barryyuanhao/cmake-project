#include <iostream>
#include <string.h>
#include <algorithm>

int findsubstring(std::string &s, int left, int right){
    while (left >=0 && right <= s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

int main(int argc, char* argv[]){
    std::string s="abcddcbaefglkklgf";
    int start = 0;
    int end = 0;
    int length =0;
    for (int i = 0; i < s.size(); i++)
    {
        int len_1 = findsubstring(s,i,i);
        int len_2 = findsubstring(s,i,i+1);
        int len = std::max(len_1,len_2);
        if (len > length)
        {
            length = len;
            start = i-(len-1)/2;
            end = i + len/2;
        }
    }

    std::cout << "The longest length : " << length 
              << " , the substring is :" << s.substr(start, end-start+1) << std::endl;
    
    return 0;
}