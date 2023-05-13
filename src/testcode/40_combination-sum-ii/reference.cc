#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void add(vector<int>& candidates, int target, int index, int sum, vector<bool> used){
        if(sum == target){
            result.push_back(path);
            return;
        }else if(sum > target){
            return;
        }

        for(int i =index; i< candidates.size(); i++){
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            sum =sum + candidates[i];
            path.push_back(candidates[i]);
            used[i] =true;
            // 这个的index的加1操作，是因为不允许重复使用
            add(candidates, target, i+1, sum,used);
            used[i] =false;
            sum =sum- candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 用于记录是否使用过该变量，去重检测
        vector<bool> used(candidates.size(),false);
        // 去重检测相邻的两个元素，需要排序
        sort(candidates.begin(), candidates.end());
        add(candidates, target, 0, 0, used);

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}