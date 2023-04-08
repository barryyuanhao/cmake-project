#include <iostream>
#include <string.h>

int main(int argc, char* argv[]){
    std::string s = "aaabcdefbd";
    int left = 0, right = 0, length = 0, result =0;
    while (right < s.size())
    {
        for (int i = left; i < right; i++)
        {
            if(s[i] == s[right]){
                left = i+1;
            }
            
        }
        right++;
        length = right-left;
        result= std::max(result, length);
    }
    std::cout << "The longest char length is : " << result << std::endl;
    return 0;
}