#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::vector<int> arg = {-1,2,1,-4};
    int target = std::atoi(argv[1]);
    std::sort(arg.begin(),arg.end());
    int len = arg.size();
    int result = arg[0]+arg[1]+arg[2];

    for (int i = 0; i < len-2; i++)
    {
        int left = i+1;
        int right = len-1;
        int temp_result =arg[i] + arg[i+1]+arg[i+2];
        
        while (left < right)
        {
            if(arg[i] + arg[left]+arg[right] > target){
                temp_result = arg[i] + arg[left]+arg[right];
                right--;
            }else if(arg[i] + arg[left]+arg[right] < target){
                temp_result = arg[i] + arg[left]+arg[right];
                left++;
            }else{
                temp_result = arg[i] + arg[left]+arg[right];
                break;
            }
        }
        std::cout << "temp_result : " << temp_result << " ,left:"<< left << " ,right: "<< right << std::endl;
        if(abs(temp_result - target) < abs(result - target)){
            result = temp_result;
        }
    }
    std::cout << "The result is : " << result << std::endl;
    
    return 0;
}