#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> int_arg = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result;
    std::sort(int_arg.begin(), int_arg.end());

    for (int i = 0; i < int_arg.size() - 2; i++)
    {
        // 跳过重复的i
        if (i != 0 && int_arg[i] == int_arg[i - 1])
        {
            i++;
            continue;
        }
        if(int_arg[i]+int_arg[i+1]+int_arg[i+2] > 0){
            break;
        }
        if(int_arg[i]+int_arg[int_arg.size()-2]+int_arg[int_arg.size()-3] < 0){
            continue;
        }

        int j = i + 1;
        int k = int_arg.size() - 1;
        while (j < k)
        {
            if (int_arg[i] + int_arg[j] + int_arg[k] > 0)
            {
                k--;
            }
            else if (int_arg[i] + int_arg[j] + int_arg[k] < 0)
            {
                j++;
            }
            else
            {
                result.push_back({int_arg[i], int_arg[j], int_arg[k]});
                j++;
                for (j; j < k && int_arg[j] == int_arg[j + 1]; j++);
                k--;
                for (k; j < k && int_arg[k - 1] == int_arg[k]; k--);
            }
        }
    }
    for (std::vector<int> one:result)
    {
        for(int one_value: one){
            std::cout << one_value << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}