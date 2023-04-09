#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    // std::vector<int> length = {1,8,6,2,5,4,8,3,7};
    std::vector<int> length = {1};
    int left = 0;
    int right = length.size()-1;
    int temp_result = 0;
    int result = 0;

    while (left < right)
    {
        temp_result = (right - left)*std::min(length[left],length[right]);
        result = std::max(result, temp_result);
        std::cout << "result : " << result << " ,temp_result: " << temp_result 
                  << " ,left: " << left << " ,right: " << right<< std::endl;
        if(length[left] < length[right]){
            left++;
        }else{
            right--;
        }
    }
    std::cout << "The most water is : " << result << std::endl;
    return 0;
}