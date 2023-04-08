#include <iostream>
#include <vector>
#include <algorithm>


int FindMid(std::vector<int>num1,std::vector<int>num2,int k){
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

int main(int argc, char* argv[]){
    int arg_a[]={5,7,9,11,12,13};
    int arg_b[]={10,14,15,16};
    std::vector<int> arg1(arg_a,arg_a+6);
    std::vector<int> arg2(arg_b,arg_b+4);

    //使用 README.md中的trick，避免区分奇偶数 
    int left_k = (arg1.size()+arg2.size()+1)/2;
    int right_k = (arg1.size()+arg2.size()+2)/2;
    double mid_value = (FindMid(arg1, arg2,left_k) + FindMid(arg1, arg2,right_k))/2.0;

    std::cout << "The mid value is: " << mid_value << std::endl; 

    return 0;
}