#include <iostream>
#include <map>
#include <vector>

int main(int argc, char* argv[]){
    int target = std::atoi(argv[1]);
    std::cout << "The target value is : " << target<< std::endl;
    std::vector<int> arg = {1,2,4,4,5,5,8,9};
    std::map<int, int> m_value;
    std::vector<int> ans = { -1, -1};

    for (int i=0; i<arg.size(); i++)
    {
        m_value.insert(std::map<int,int>::value_type(arg[i],i));
    }

    for (int i = 0; i < arg.size(); i++)
    {
        if(m_value.count(target - arg[i]) ==1 && m_value[target - arg[i]] != i){
            ans[0] = i;
            ans[1] = m_value[target - arg[i]];
        }
    }
    std::cout << "The ans value is [" << ans[0] << " , " << ans[1] << "]" << std::endl; 
    
    return 0;
}