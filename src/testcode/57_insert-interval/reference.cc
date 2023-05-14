#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        int index =0;
        // 查找需要合并的区间
        while(index < size && intervals[index][1] < newInterval[0]){
            result.push_back({intervals[index][0], intervals[index][1]});
            index++;
        }
        // 合并区间
        while(index < size && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        result.push_back({newInterval[0], newInterval[1]});
        // 存入合并区间后的区间
        while(index < size){
            result.push_back({intervals[index][0], intervals[index][1]});
            index++;
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}