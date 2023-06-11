#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 本题三指针: i,j分别为nums1 nums2有效值的末尾指针, index未nums1的tail指针
    // 采用谁大谁排最后的思路,分别从后往前查找
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int index = m+n-1;

        // 由于往nums1填充数据,所以外层循环为nums2
        while(j>=0){
            // nums1[i] > nums2[j],将nums1移动到后面
            while(i>=0 && nums1[i] > nums2[j]){
                nums1[index--] = nums1[i--];
            }
            // 否则nums2移动到后面
            nums1[index--] = nums2[j--];
        }
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}