#include <iostream>
#include <string.h>
#include <vector>

int main(int argc, char* argv[]){
    std::vector<std::string> strs = {"flower","flow","flight"};
    std::string result = "";
    for (int i =0; i<strs[0].size();i++)
    {
        int count = 0;
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[0][i] == strs[j][i])
            {
                count++;
            }
            
        }

        if (count == strs.size())
        {
            result = result+ strs[0][i];
        }else{
            break;
        }
    }
    std::cout << "The result is: " << result << std::endl;
    
    return 0;
}