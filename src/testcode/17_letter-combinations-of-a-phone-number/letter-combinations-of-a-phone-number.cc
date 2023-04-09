#include <iostream>
#include <vector>
#include <string.h>

std::vector<std::string> strs = {""};
std::string s = "";
std::vector<std::string> letter_map ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void GenerateString(std::string num, int index){
    if(index == num.size()){
        strs.push_back(s);
        // std::cout << "s: " << s << std::endl;
        return;
    }

    std::string letters = letter_map[num[index]-'0'];
    for (int i = 0; i < letters.size(); i++)
    {
        s = s+letters[i];
        GenerateString(num, index+1);
        s.pop_back();
    }
    
}

int main(int argc, char* argv[]){
    std::string num = "23";
    int index =0;
    GenerateString(num,index);
    for(std::string temp : strs){
        std::cout << temp << std::endl;
    }
    return 0;
}