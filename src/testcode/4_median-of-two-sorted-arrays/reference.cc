#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fineMediValue(std::vector<int>num1,std::vector<int>num2,int k){
        int n = num1.size();
        int m = num2.size();
        int left = std::max(0, k-m);
        int right = std::min(n,k);
        while(left < right){
            int mid = left + (right - left)/2;
            if(num2[k-mid-1] > num1[mid]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        // 循环结束后最小K值为 max(num1[left -1], num2[k-left -1]) 的最大值， 下标从0开始，所以都减1；
        // 边界检测  left -1 >= 0 , k-left-1 >=0;
        int num1max = left==0 ? -1:num1[left-1]; //设置 -1是为了设置一个不合理的值，标识该情况下数据不使用
        int num2max = left==k ? -1:num2[k-left -1];
        return std::max(num1max, num2max);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double result = 0;
        double result1 = fineMediValue(nums1, nums2, (m+n+1)/2);
        double result2 = fineMediValue(nums1, nums2, (m+n+2)/2);
        result = (result1 + result2) /2;

        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}