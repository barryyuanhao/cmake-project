#include <iostream>
#include <vector>
#include <string.h>

int main(int argc, char* argv[]){
    int int_data = std::atoi(argv[1]);
    std::vector<int> int_arg = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    std::vector<std::string> str_arg = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    std::string result = "";

    for (int i = 0; i < int_arg.size(); i++)
    {
        while(int_data >= int_arg[i]){
            result = result + str_arg[i];
            int_data = int_data - int_arg[i];
        }
    }
    std::cout << "The result is :" << result << std::endl;
    return 0;
}