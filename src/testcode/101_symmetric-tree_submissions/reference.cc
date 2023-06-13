#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
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
    // 左右对称
    bool check(TreeNode* tree1, TreeNode* tree2){
        // 都为NULL, 返回true
        if(tree1==nullptr && tree2 == nullptr){return true;}
        // 上一步已判断了都为NULL,执行这步说明有一个为NULLL
        if(tree1==nullptr || tree2 == nullptr){return false;}
        // 比较val值是否相等
        if(tree1->val == tree2->val){
            // 相等的情况下继续比较左右分支，交叉对称比较
            return check(tree1->left, tree2->right)&&check(tree1->right, tree2->left);
        }else{
            // val值不相等直接返回false
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}