#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先将所有区间按照左端点，从小到大的顺序排列
        sort(intervals.begin(), intervals.end());

        int size = intervals.size();
        int left = intervals[0][0]; //寻找区间的左端点
        int right = intervals[0][1]; //寻找区间的左端点

        for(int i=1; i< size; i++){
            // 当前区间的左端点大于上一个区间的右端点，将上一个区间存入结果
            if(intervals[i][0] > right){
                result.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }else{
                // 合并当前区间与上一个区间的右端点
                right = max(right, intervals[i][1]);
            }
        }

        // 将最后一个动态区间存入结果
        result.push_back({left, right});

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}