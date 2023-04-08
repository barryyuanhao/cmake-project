#include <iostream>

int main(int argc, char* argv[]){
    int x = 12344321;
    int temp = x;
    std::cout << "The raw value is " << x << std::endl;
    int covert_value = 0;
    if (x < 0)
    {
        std::cout << "This value is not palindrome : " << x << std::endl;
    }

    while (temp > 0)
    {
        covert_value = covert_value*10 + temp % 10;
        temp = temp / 10;
    }

    if (covert_value == x)
    {
        std::cout << "This value is palindrome " << std::endl;
    }else if(covert_value != x){
        std::cout << "This value is not palindrome " << std::endl;
    }
    


    return 0;
}