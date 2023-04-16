#include <iostream>
#include <vector>

class Solution{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
};

int main(int argc, char* argv[]){
    int arg_a[]={5,7,9,11,12,13};
    int arg_b[]={10,14,15,16};
    std::vector<int> v_arg_a(arg_a,arg_a+6);
    std::vector<int> v_arg_b(arg_b,arg_b+4);

    Solution obj;
    obj.findMedianSortedArrays(v_arg_a, v_arg_b);
    return 0;
}