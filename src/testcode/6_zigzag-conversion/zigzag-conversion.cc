#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

std::string z_covert(std::string s, int row){
    if(row == 1){ return s;}

    std::vector<std::string> v_covert(std::min(row, (int)s.size()));
    int curRow = 0;
    bool goingDown = false;

    for (char s_char : s)
    {
        v_covert[curRow] = v_covert[curRow] + s_char;
        if(curRow == 0 || curRow == row-1){
            goingDown = !goingDown;
        }
        curRow = curRow + (goingDown ? 1 : -1);
    }

    std::string s_covert = "";
    for (std::string s_one : v_covert)
    {
        s_covert = s_covert+s_one;
    }
    
    return s_covert;

}

int main(int argc, char* argv[]){
    std::string s="abcdefghijklmnopq";
    std::string s_back = z_covert(s,4);
    std::cout << "The Z-covert string is: " << s_back << std::endl;
    return 0;
}