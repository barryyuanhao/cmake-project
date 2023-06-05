#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left =0;
        // 对于一个非负数n，它的平方根不会大于（n/2+1）
        int right = x/2 +1;
        if(x ==1||x==0){return x;}

        // left存在等于right的场景,此处取等
        while(left <= right){
            int mid = (left + right)/2;
            if((long)mid*mid == x){
                return mid;
            }else if((long)mid*mid > x){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return left-1;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}