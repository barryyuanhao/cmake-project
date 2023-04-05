#include <iostream>

int main(int argc, char* argv[]){
    int value = -1567890;
    std::cout << "The raw value is : " << value << std::endl;
    int ans = 0;
    while (value !=0)
    {   
        int x = value % 10;
        value = value / 10;
        if(ans < INT32_MIN || ans > INT32_MAX){
            std::cout << "The integer covert value overflow : " << ans << std::endl;
            ans = 0;
            break;
        }
        ans = ans*10 + x;
    }
    std::cout << "The integer covert value is : " << ans << std::endl;

    return 0;
}