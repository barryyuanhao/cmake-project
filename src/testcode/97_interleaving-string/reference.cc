#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(string& s1, string& s2, string& s3, int p1, int p2, int p3,vector<vector<int>>& result){
        if (result[p1][p2]) return; //已经判断过的组合，直接返回，避免重复判断
        // 如果s1 s2都满足的情况下
        if(p1<s1.size() && p2 <s2.size()){
            // 如果s1, s2同时满足s3的匹配，需要分别对两个进行单独的搜索
            if(s1[p1]==s3[p3] && s2[p2]==s3[p3]){
                dfs(s1,s2,s3,p1+1,p2,p3+1,result);
                dfs(s1,s2,s3,p1,p2+1,p3+1,result);
            }else if(s1[p1]==s3[p3]){
                dfs(s1,s2,s3,p1+1,p2,p3+1,result);
            }else if(s2[p2]==s3[p3]){
                dfs(s1,s2,s3,p1,p2+1,p3+1,result);
            }else{
                return;
            }
        }else if(p1 < s1.size()){ //S2运行到尾端，p2 == s2.size()
            if(s1[p1]==s3[p3]){
                dfs(s1,s2,s3,p1+1,p2,p3+1,result);
            }else{
                return;
            }
        }else if(p2 < s2.size()){ //S1运行到尾端，p1 == s1.size()
            if(s2[p2]==s3[p3]){
                dfs(s1,s2,s3,p1,p2+1,p3+1,result);
            }else{
                return;
            }
        }
        // 如果以上三个条件都不满足，说明已经完成了循环检测 
        result[p1][p2] = 1;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        vector<vector<int>> result(n1+1,vector<int>(n2+1,0));
        // 判断size是否匹配，不匹配可以直接返回false;
        if(n1+n2 != n3){return false;}
        dfs(s1,s2,s3,0,0,0,result);

        return result[n1][n2];
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}