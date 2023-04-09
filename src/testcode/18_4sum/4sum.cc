#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::vector<int> num = {1,0,-1,0,-2,2};
    std::sort(num.begin(), num.end());
    int target = 0;
    std::vector<std::vector<int>> result;

    for (int i = 0; i < num.size()-3; i++)
    {
        if(i>0 &&num[i] == num[i-1]){continue;}
        for (int j = i+1; j < num.size()-2; j++)
        {
            if(j > 1 && num[j] == num[j-1]){continue;}
            int left = j+1;
            int right = num.size() -1;
            while (left < right)
            {
                if (num[i]+num[j]+num[left]+num[right] > target)
                {
                    right--;
                }else if(num[i]+num[j]+num[left]+num[right] < target){
                    left++;
                }else{
                    result.push_back({num[i],num[j],num[left],num[right]});
                    left++;
                    for(left;num[left] == num[left-1];left++);
                    right--;
                    for(right;num[right] == num[right+1];right++);
                }
            }
        }
    }
    
    for (std::vector<int> one:result)
    {
        for (int one_value: one)
        {
            std::cout << one_value << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}