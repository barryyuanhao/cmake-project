#include <iostream>
#include <string.h>
#include <vector>
#include <map>

int main(int argc, char* argv[]){
    std::string roman_data = "MCMXCIV";
    std::map<char,int> m_arg ={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}}; 
    int result =0;

    for (int i = 0; i < roman_data.size(); i++)
    {   
        if(m_arg[roman_data[i]] < m_arg[roman_data[i+1]]){
            result = result - m_arg[roman_data[i]];
        }else{
            result = result + m_arg[roman_data[i]];
        }
    }
    std::cout << "The result value is: " << result << std::endl;

    return 0;
}