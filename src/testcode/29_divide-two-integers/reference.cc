#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 避免数据越界，将除数、被除数都转为long数据类型
        long div = dividend;
        long div_sor = divisor;
        // 除数为1，直接返回
        if(div_sor ==1){return div;}
        // 输出为-1，需要对被除数取反，取反存在超出范围的问题
        if(div_sor ==-1){
            if(-div > INT_MAX){return INT_MAX;}
            else if(-div < INT_MIN){return INT_MIN;}
            else{return -div;}
        }
        // 计算flag的类型
        int flag =1;
        if((div>0 && div_sor <0)||(div<0 && div_sor>0)){
            flag = -1;
        }
        // 转化为绝对值计算
        div = abs(div);
        div_sor = abs(div_sor);
        if(div < div_sor){return 0;}

        // 注意使用long数据类型
        long sub_divor = div_sor;
        long count =1;
        // 除数相加，对应的count也相加
        while(sub_divor +sub_divor <= div){
            count = count +count;
            sub_divor = sub_divor+sub_divor;
        }

        // 需要对result检查数据范围，
        long result = (count + divide(div - sub_divor, div_sor))*flag;
        if(result > INT_MAX){result = INT_MAX;}
        else if(result < INT_MIN){result =INT_MIN;}
        
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}