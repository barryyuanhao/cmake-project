#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a):val(a),left(nullptr),right(nullptr){}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* generate(vector<int>& nums, int left , int right){
        // 递归退出条件
        if(left > right){return nullptr;}
        // 选择中间点作为根节点
        int mid = left +(right - left)/2;
        // 创建根节点
        TreeNode* root = new TreeNode(nums[mid]);
        // [left,mid-1] [左闭,右闭]作为左分支
        root->left = generate(nums, left, mid-1);
        // [mid+1,right] [左闭,右闭]作为右分支
        root->right = generate(nums, mid+1, right);

        // 返回根节点
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 递归,[左闭,右闭]
        TreeNode* result = generate(nums, 0, nums.size()-1);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}